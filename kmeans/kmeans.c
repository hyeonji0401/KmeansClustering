#include"kmeans.h"

// K-means Ŭ�����͸�
void kmeans(double** data, int n, int dim, int k) {
    double** centers = (double**)malloc(k * sizeof(double*));
    for (int i = 0; i < k; i++) {
        centers[i] = (double*)malloc(dim * sizeof(double));
    }

    int* labels = (int*)malloc(n * sizeof(int));

    // �ʱ� �߽��� ����
    findFirstCenter(data, centers, n, dim, k);

    // �ݺ� ����
    int iter = 0;
    int centerChanged;
    do {
        // ���� �߽����� ����
        double** oldCenters = (double**)malloc(k * sizeof(double*));
        for (int i = 0; i < k; i++) {
            oldCenters[i] = (double*)malloc(dim * sizeof(double));
            for (int j = 0; j < dim; j++) {
                oldCenters[i][j] = centers[i][j];
            }
        }

        // ������ Ŭ������ ����
        assignCluster(data, centers, labels, n, dim, k);

        // ���ο� �߽��� ã��
        findNewCenter(data, centers, labels, n, dim, k);

        // �߽����� �ٲ������ Ȯ��
        centerChanged = isCenterChanged(oldCenters, centers, dim, k);

        // �޸� ����
        for (int i = 0; i < k; i++) {
            free(oldCenters[i]);
        }
        free(oldCenters);

        iter++;
    } while (centerChanged && iter < MAX_ITER);

    // �Ƿ翧 ��� ���
    double* silhouetteScores = silhouetteCoefficient(data, labels, centers, n, k, dim);

    // ���� �߽��� ���
    printf("���� �߽���:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d Center: ", i);
        for (int j = 0; j < dim; j++) {
            printf("%lf ", centers[i][j]);
        }
        printf("\n");
    }

    // �� �߽����� �Ҵ�� ������ ���
    printf("\n�� �߽����� �Ҵ�� ������:\n");
    printClusterData(data, labels, n, dim, k, silhouetteScores);

    // �� Ŭ�������� ��� �Ƿ翧 ����� ���� ���
    evaluateSilhouette(silhouetteScores, labels, n, k);

    printf("�ݺ� Ƚ��: %d", iter);

    // �޸� ����
    free(silhouetteScores);

    // �޸� ����
    for (int i = 0; i < k; i++) {
        free(centers[i]);
    }
    free(centers);
    free(labels);
}
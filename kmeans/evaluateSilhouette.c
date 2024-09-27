#include "silhouette.h"

// �� Ŭ�������� ��� �Ƿ翧 ����� ������ ����ϴ� �Լ�
void evaluateSilhouette(double* silhouetteScores, int* labels, int n, int k) {
    double* clusterSilhouetteSum = (double*)calloc(k, sizeof(double));
    double* clusterSilhouetteSquaredSum = (double*)calloc(k, sizeof(double));
    int* clusterSizes = (int*)calloc(k, sizeof(int));

    // �� Ŭ�����ͺ� �Ƿ翧 ��� �հ� �� ũ�� ���
    for (int i = 0; i < n; i++) {
        int cluster = labels[i];
        clusterSilhouetteSum[cluster] += silhouetteScores[i]; //�� Ŭ������ �Ƿ翧 ��� �� ��
        clusterSilhouetteSquaredSum[cluster] += silhouetteScores[i] * silhouetteScores[i]; //�� Ŭ������ �Ƿ翧 ��� �� ���� ����
        clusterSizes[cluster]++;  //Ŭ������ �� ������ ����
    }

    // ��ü �Ƿ翧 ��� �հ� �� ��� ���
    double totalSilhouetteSum = 0.0;
    for (int c = 0; c < k; c++) {
        if (clusterSizes[c] > 0) {
            double clusterMean = clusterSilhouetteSum[c] / clusterSizes[c]; //�� Ŭ������ �Ƿ翧 ��� ��� ����
            double clusterVariance = (clusterSilhouetteSquaredSum[c] / clusterSizes[c]) - (clusterMean * clusterMean); //�� Ŭ������ �� �������� �Ƿ翧 �Լ� �л�
            double clusterStdDev = sqrt(clusterVariance); //�� Ŭ������ �� �������� �Ƿ翧 ��� ǥ�� ����
            totalSilhouetteSum += clusterSilhouetteSum[c];

            printf("Cluster %d: Mean Silhouette = %.4f, StdDev = %.4f\n", c, clusterMean, clusterStdDev);
        }
    }

    double totalMeanSilhouette = totalSilhouetteSum / n;
    printf("Overall Mean Silhouette = %.4f\n", totalMeanSilhouette);

    free(clusterSilhouetteSum);
    free(clusterSilhouetteSquaredSum);
    free(clusterSizes);
}

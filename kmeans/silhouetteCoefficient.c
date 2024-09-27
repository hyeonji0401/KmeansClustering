#include"silhouette.h"

double* silhouetteCoefficient(double** data, int* labels, double** centers, int n, int k, int dim) {
    double* silhouetteScores = (double*)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        double a = 0.0;  // ���� Ŭ������ �� ��� �Ÿ�
        double b = DBL_MAX;  // �ٸ� Ŭ�����Ϳ��� �ּ� ��� �Ÿ�

        int clusterSize = 0;
        for (int j = 0; j < n; j++) {
            if (labels[i] == labels[j]) {
                clusterSize++;
            }
        }

        //Ŭ������ ũ�Ⱑ 1�� ���, �Ƿ翧 ����� 0���� ����
        if (clusterSize == 1) {
            silhouetteScores[i] = 0.0;
            continue;
        }

        //a(i) ���: ���� Ŭ������ ���� ��� �Ÿ�
        for (int j = 0; j < n; j++) {
            if (labels[i] == labels[j]) {
                a += euclideanDistance(data[i], data[j], dim);
            }
        }
        if (clusterSize > 1) {
            a /= (clusterSize - 1);  // �ڱ� �ڽ��� �����ϰ� ��� �Ÿ� ���
        }

        //b(i) ���: ���� ����� �ٸ� Ŭ�����Ϳ��� ��� �Ÿ�
        for (int c = 0; c < k; c++) {
            if (c == labels[i]) continue;  // ���� Ŭ�����ʹ� ����
            double otherClusterDist = 0.0;
            int otherClusterSize = 0;

            for (int j = 0; j < n; j++) {
                if (labels[j] == c) {
                    otherClusterDist += euclideanDistance(data[i], data[j], dim);
                    otherClusterSize++;
                }
            }

            if (otherClusterSize > 0) {
                otherClusterDist /= otherClusterSize;
                if (otherClusterDist < b) {
                    b = otherClusterDist;
                }
            }
        }

        //Silhouette �� ���
        silhouetteScores[i] = (b - a) / fmax(a, b);
    }

    return silhouetteScores;
}


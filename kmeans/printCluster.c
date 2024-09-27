#include "inoutputCluster.h"

// �� Ŭ�������� �Ҵ�� ������ ��� �Լ�
void printClusterData(double** data, int* labels, int n, int dim, int k, double* silhouette) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (labels[j] == i) {
                printf("  Data Point: ");
                for (int d = 0; d < dim; d++) {
                    printf("%lf ", data[j][d]);
                }
                printf("/ Silhouette coefficient : %lf\n", silhouette[j]);
                printf("\n");
            }
        }
    }
}

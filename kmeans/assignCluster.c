#include"kmeans.h"

// ������ �Ҵ� �Լ� (��Ŭ����� �Ÿ� �������� �Ҵ�)
void assignCluster(double** data, double** centers, int* labels, int n, int dim, int k) {
    for (int i = 0; i < n; i++) {
        double minDist = DBL_MAX;
        int cluster = -1;
        for (int j = 0; j < k; j++) {
            double dist = euclideanDistance(data[i], centers[j], dim);
            if (dist < minDist) {
                minDist = dist;
                cluster = j;
            }
        }
        labels[i] = cluster;
    }
}
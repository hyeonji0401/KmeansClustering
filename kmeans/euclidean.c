#include"euclidean.h"

// ��Ŭ����� �Ÿ� ��� �Լ�
double euclideanDistance(double* a, double* b, int dim) {
    double sum = 0.0;
    for (int i = 0; i < dim; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}
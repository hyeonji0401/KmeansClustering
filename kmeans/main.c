#include "kmeans.h"

int main(void) {
    int n = ROWS;     // ������ ��
    int dim = COLS;   // ������ ����
    int k = 4;     // ���� ��

    // ���� ������
    double data[ROWS][COLS]; // ���� �迭 ����

    // CSV ���� �б�
    read_csv(data, "random_2d_points.csv");

    // 2���� �迭�� �������� ��ȯ
    double** dataptr = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        dataptr[i] = (double*)malloc(dim * sizeof(double));
        for (int j = 0; j < dim; j++) {
            dataptr[i][j] = data[i][j];
        }
    }

    // kmeans ����
    kmeans(dataptr, n, dim, k);

    // �޸� ����
    for (int i = 0; i < n; i++) {
        free(dataptr[i]);
    }
    free(dataptr);

    return 0;
}

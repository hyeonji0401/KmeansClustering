#include"findCenter.h"

// �߽��� ��ȭ ���� Ȯ�� �Լ�
int isCenterChanged(double** oldCenters, double** newCenters, int dim, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < dim; j++) {
            if (fabs(oldCenters[i][j] - newCenters[i][j]) > 1e-6) {
                return 1;
            }
        }
    }
    return 0;
}
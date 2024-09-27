#include"inoutputCluster.h"

void read_csv(double data[ROWS][COLS], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256];
    int row = 0;

    // ù ��° ���� ����̹Ƿ� ����
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        sscanf_s(line, "%lf,%lf", &data[row][0], &data[row][1]);
        row++;
    }

    fclose(file);
}
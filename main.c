#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char matrix[50][50];

int maxX = 0;
int maxY = 0;

int showBoard();

void initLevel(int level);

int main() {
    initLevel(1);
    showBoard();
}

void initLevel(int level) {
    FILE *file = fopen("level/level1.txt", "r");

    if (file == NULL) {
        printf("NULL");
        return;
    }

    int x = 0;
    int y = 0;
    while (!feof(file)) {
        int ch = fgetc(file);
        if (ch == '\n') {
            y++;
            maxY++;
        }
        matrix[x][y] = ch;
        x++;
        maxX++;
        printf("%c", ch);
    }

    fclose(file);
}

int showBoard() {

    int row = sizeof(matrix) / sizeof(matrix[0]);
    for (int i = 0; i < row; ++i) {
        int column = sizeof(matrix[i]) / (sizeof(matrix) / sizeof(matrix[i]));
        for (int j = 0; j < column; ++j) {
            int matrixCase = matrix[i][j];

            printf("%d", matrixCase);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matrix[50][50];

int maxX;

int maxY = 1;

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
            printf("\n");
            x = 0;
            continue;
        }
        matrix[y][x] = ch;
        x++;
        if(x > maxX){
            maxX = x;
        }
    }

    fclose(file);
}

int showBoard() {

    for (int i = 0; i < maxY; ++i) {
        for (int j = 0; j < maxX; ++j) {
            int matrixCase = matrix[i][j];

            printf("%c", matrixCase);
        }
        printf("\n");
    }
    return 0;
}

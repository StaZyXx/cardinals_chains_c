#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int matrix[50][50];

int maxX;

int maxY = 1;

int showBoard();

void initLevel(int level);

void Color(int couleurDuTexte,int couleurDeFond){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


int main() {
    initLevel(1);
    showBoard();
    moveCase();
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
int moveCase(){
    char lettre;
    char startCase[10][10];
    printf("\n\n");
    printf("Entrez une direction (Z, Q, S, D)\n");
    printf("Annuler le coup precedent (B)\n");
    printf("Effacer la chaine (R)\n");
    printf("Restart the level (X)\n");
    printf("Changer de chaine (C)\n" );
    scanf("%c", &lettre);
    for(int i = 0; i < maxX; i++){
        for(int j = 0; j < maxY; j++){
            if (matrix[i][j] == 'X'){
                startCase[i][j] = matrix[i][j];
            }
        }
    }

    return 0;
}

int showBoard() {

    for (int i = 0; i < maxY; ++i) {
        for (int j = 0; j < maxX; ++j) {
            int matrixCase = matrix[i][j];
            if(matrixCase == 'X'){
                Color(12, 0);
            }
            printf("%c", matrixCase);
            Color(15, 0);
        }
        printf("\n");
    }
    return 0;
}



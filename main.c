#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int matrix[50][50];

int maxX;

int maxY = 1;

struct Location{
    int x;
    int y;
};

struct Color{
    int textColor;
    int backgroundColor;
};

struct Chains{
    struct Location locations[50];
    struct Color color;
};

struct Player{
    struct Location location;
    struct Location lastLocation;
};

struct SpawnPoint{
    struct Location spawnPoint;
};

Player player;

int show_board();

void init_level(int level);

void set_color(struct Color color){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,color.backgroundColor*16+color.textColor);
}


int main() {
    init_level(1);
    show_board();
    game_logic();
}

void init_level(int level) {
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

        if(ch == 'X'){
            spawnPoint[0] = x;
            spawnPoint[1] = y;
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
int game_logic(){
    char lettre;
    printf("\n\n");
    printf("Entrez une direction (Z, Q, S, D)\n");
    printf("Annuler le coup precedent (B)\n");
    printf("Effacer la chaine (R)\n");
    printf("Restart the level (X)\n");
    printf("Changer de chaine (C)\n" );
    scanf("%c", &lettre);

    return 0;
}

void move(int direction){

    switch (direction) {
        case 1:

            break;
    }
}

int show_board() {

    for (int i = 0; i < maxY; ++i) {
        for (int j = 0; j < maxX; ++j) {
            int matrixCase = matrix[i][j];
            if(matrixCase == 'X'){
                set_color(Color{18, 0});
            }
            printf("%c", matrixCase);
            set_color(Color{15, 0});
        }
        printf("\n");
    }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int matrix[50][50];

int maxX;

int maxY = 1;

int amountSpawnPoint = 0;

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


struct SpawnPoint spawnPoints[5];
struct Player player;

int show_board();

void init_level(int level);

void set_color(struct Color color){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,color.backgroundColor*16+color.textColor);
}

void game_logic();


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

            struct SpawnPoint spawnPoint;

            spawnPoint.spawnPoint.x = x;
            spawnPoint.spawnPoint.y = y;
            spawnPoints[amountSpawnPoint] = spawnPoint;
            amountSpawnPoint++;
        }
        matrix[y][x] = ch;
        x++;
        if(x > maxX){
            maxX = x;
        }
    }

    fclose(file);
}

void game_logic(){
    char lettre;
    printf("\n\n");
    printf("Entrez une direction (Z, Q, S, D)\n");
    printf("Annuler le coup precedent (B)\n");
    printf("Effacer la chaine (R)\n");
    printf("Restart the level (X)\n");
    printf("Changer de chaine (C)\n" );
    scanf("%c", &lettre);

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
                struct Color color;
                color.textColor = 18;
                color.backgroundColor = 0;
                set_color(color);
                printf("X");
                continue;
            }
            struct Color color;
            color.textColor = 15;
            color.backgroundColor = 0;
            set_color(color);
            printf("%c", matrixCase);
        }
        printf("\n");
    }
    return 0;
}



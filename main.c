#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <unistd.h>

int maxX;

int maxY = 1;

int amountSpawnPoint = 0;

int level = 1;

struct Location {
    int x;
    int y;
};

struct Color {
    int textColor;
    int backgroundColor;
};

struct Case {
    int caseChar;
    bool hasChains;
    bool isCase;
};


struct Chains {
    int spawnPoints;
    struct Location locations[50];
    struct Color color;

    struct Location lastLocation;
};

struct Player {
    struct Location location;
    struct Location lastLocation;

    struct Chains chains[2];

    int currentChains;
};

struct SpawnPoint {
    struct Location spawnPoint;
};

struct Case matrix[50][50];


struct SpawnPoint spawnPoints[5];
struct Player player;

int show_board();

void init_level(int level);

void move(char direction);

void set_color(struct Color color) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, color.backgroundColor * 16 + color.textColor);
}

void game_logic();


int main() {
    init_level(level);
    game_logic();
}

void init_level(int level) {
    char filename[20];
    sprintf(filename, "level/level%d.txt", level);
    FILE *file = fopen(filename, "r");

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


        if (ch == 'X') {

            struct SpawnPoint spawnPoint;

            spawnPoint.spawnPoint.x = x;
            spawnPoint.spawnPoint.y = y;
            spawnPoints[amountSpawnPoint] = spawnPoint;
            amountSpawnPoint++;
            player.location.x = x;
            player.location.y = y;
        }
        struct Case c;

        if (ch != ' ') {
            c.isCase = true;
        }

        c.hasChains = false;
        c.caseChar = ch;
        matrix[y][x] = c;
        x++;
        if (x > maxX) {
            maxX = x;
        }
    }
    fclose(file);
}

bool is_finished() {

    for (int i = 0; i < maxY; ++i) {
        for (int j = 0; j < maxX; ++j) {
            struct Case matrixCase = matrix[i][j];

            if (!matrixCase.hasChains) return false;
        }
    }
    level++;
    return true;
}

void game_logic() {

    char lettre;
    while (!is_finished() && level < 30) {
        show_board();
        printf("-------------------------------------\n");
        printf("Entrez une direction (Z, Q, S, D)\n");
        printf("Annuler le coup precedent (B)\n");
        printf("Effacer la chaine (R)\n");
        printf("Restart the level (X)\n");
        printf("Changer de chaine (C)\n");


        scanf("%c", &lettre);

        if (lettre == 'z' || lettre == 'q' || lettre == 's' || lettre == 'd') {
            move(lettre);
        }

        if (lettre == 'b') {
            player.location = player.lastLocation;
        }
        struct SpawnPoint spawnPoint;
        if (lettre == 'c'){
            if (amountSpawnPoint == 1){
                printf("Nombre de chaines insuffisant\n");
            }
            else{
                player.currentChains = 2;
            }
        }
        if (lettre == 'x'){
            init_level(level);
        }
        sleep(1);

    }

}

bool can_move(char direction) {
    struct Case c;
    switch (direction) {
        case 'z':
            c = matrix[player.location.x - 1][player.location.y];
            if (player.location.x >= 0 && !c.hasChains && c.isCase) {
                return true;
            }
            return false;

        case 'q':
            c = matrix[player.location.x][player.location.y - 1];
            if (player.location.y - 1 >= 0 && c.isCase) {
                return true;
            }
            return false;

        case 'd':
            c = matrix[player.location.x][player.location.y + 1];
            if (player.location.y +2 < maxX && !c.hasChains && c.isCase) {
                return true;
            }
            return false;

        case 's':
            c = matrix[player.location.x + 1][player.location.y];
            if (player.location.x + 2 < maxY -1 && !c.hasChains && c.isCase) {
                return true;
            }
            return false;
    }
}

void move(char direction) {


    if (!can_move(direction)) {
        printf("\nERREUR\n");
        return;
    }

    switch (direction) {
        case 'z':
            player.lastLocation = player.location;
            player.location.x--;
            break;
        case 'q':
            player.lastLocation = player.location;
            player.location.y--;
            break;
        case 'd':
            player.lastLocation = player.location;
            player.location.y++;
            break;
        case 's':
            player.lastLocation = player.location;
            player.location.x++;
            break;
    }
}

int show_board() {
    struct Color color;
    for (int i = 0; i < maxY; ++i) {
        for (int j = 0; j < maxX; ++j) {
            struct Case matrixCase = matrix[i][j];

            if (matrixCase.hasChains == true) {
                color.backgroundColor = 18;
                color.textColor = -1;
                set_color(color);
                continue;
            }
            if (player.location.x == i && player.location.y == j) {
                color.backgroundColor = 18;
                color.textColor = -1;
                set_color(color);
                printf("P");
                continue;
            }

            if (matrixCase.caseChar == 'X') {
                color.backgroundColor = -1;
                color.textColor = 17;
                set_color(color);
                printf("X");
                continue;
            }

            color.backgroundColor = 1;
            color.textColor = -1;
            set_color(color);
            printf("%c", matrixCase.caseChar);
        }
        printf("\n");
    }
    return 0;
}


/*
 * TODO :
 * - Quand un joueur ce déplace faut checker ça chains avec le currentChains et ajouter la location dans chains et checker le montant de spawnPoints,
 * - y'a déjà une variable amountSpawnPoints
 * - player.chains[player.currentChains] -> pour récupérer
 *
 * - Changer le boolean de hasChains
 * - Afficher un background différent (j'ai mis une couleur sur chains)
 */

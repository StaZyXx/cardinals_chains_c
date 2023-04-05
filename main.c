#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    showBoard();
}

int showBoard(){
    /*Ouverture du fichier*/
    FILE* fp = fopen("./level/level1.txt", "r");
    if (fp == NULL)
    {
        printf("Le fichier txt n'a pas pu etre ouvert\n");
        return EXIT_FAILURE;
    }
    printf("Le fichier txt existe\n");
    /*Fin ouverture*/

    fseek(fp, 0L, SEEK_END);
    int fsize = ftell(fp);
    fseek(fp, 0L, SEEK_SET)

    for(int i = 0; i < fsize, i++){
        for(int j = 0; j<)
    }



    return 0;

}

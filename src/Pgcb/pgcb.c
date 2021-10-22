/**
 * @file pgcb.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "pgcb.h"

int fill_mat(bool *mat, int taille_mat)
{
    srand(time(NULL));
    for (int i = 0; i < taille_mat; i++)
    {
        for (int j = 0; j < taille_mat; j++)
        {
            mat[i*taille_mat+j] = rand() % 2;
        }
    }
    aff_pgcd(mat, taille_mat);

    return 1;
}

void aff_pgcd(bool *mat, int taille_mat)
{
    for (int i = 0; i < taille_mat; i++)
    {
        for (int j = 0; j < taille_mat; j++)
        {
            if (mat[i*taille_mat+j] == 1)
            {
                printf("*|");
            }
            if (mat[i*taille_mat+j] == 0)
            {
                printf(" |");
            }
        }
        printf("\n");
    }
}
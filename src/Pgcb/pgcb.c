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

int fill_mat(int *mat, int taille_mat)
{
    srand(time(NULL));
    for (int i = 0; i < taille_mat; i++)
    {
        for (int j = 0; j < taille_mat; j++)
        {
            mat[i * taille_mat + j] = rand() % 2;
        }
    }
    aff_mat(mat, taille_mat);

    return 1;
}

void aff_mat(int *mat, int taille_mat)
{
    for (int i = 0; i < taille_mat; i++)
    {
        for (int j = 0; j < taille_mat; j++)
        {
            if (mat[i * taille_mat + j] == 1)
            {
                printf("*|");
            }
            if (mat[i * taille_mat + j] == 0)
            {
                printf(" |");
            }
        }
        printf("\n");
    }
}


int find_min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
        return b;
}

int find_carre(int pos, int *tab, int taille_mat, int numCol, int numLig)
{
    int tMax, pos1, pos2, pos3;
    //i*taille_mat+j
    //PGCB(x-1;y-1)
    pos1 = ((numCol - 1) * taille_mat) + (numLig - 1);
    //PGCB(x;y-1)
    pos2 = (numCol * taille_mat) + (numLig - 1);
    //PGCB(x-1;y)
    pos3 = ((numCol - 1) * taille_mat) + numLig;

    if (tab[pos] == 1) //pixl noir
    {
        return 0;
    }
    //pixl blanc, et première ligne en haut àou première colonne à gauche
    if ((numLig == 0 || numCol == 0) && tab[pos] == 0)
    {
        return 1;
    }
    else
    {
        tMax = 1 + find_min(
                       find_min(
                           find_carre(pos1, &tab[pos1], taille_mat, numCol - 1, numLig - 1), //PGCB(x-1;y-1)
                           find_carre(pos2, &tab[pos2], taille_mat, numCol,  numLig - 1)),    //PGCB(x;y-1
                       find_carre(pos3, &tab[pos1], taille_mat, numCol - 1, numLig));        //PGCB(x-1;y)
        return tMax;
    }
}
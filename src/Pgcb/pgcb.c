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

void fill_mat(int *mat, int taille_mat)
{
    srand(time(NULL));
    for (int i = 0; i < taille_mat; i++)
    {
        for (int j = 0; j < taille_mat; j++)
        {
            mat[i * taille_mat + j] = rand() % 2;
        }
    }
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

int find_min3(int a, int b, int c)
{
    int min = a;

    if (b < a)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    return min;
}

int find_carre(int *tab, size_t taille_mat, int x, int y, carre_blanc *carreRet)
{

    int tailleCarreMax, temp = 0;
    if (tab[x * taille_mat + y] == 1) //pixel noir
    {
        return 0;
    }
    //pixl blanc, et première ligne en haut ou première colonne à gauche
    if ((tab[x * taille_mat + y] == 0) && (x == 0 || y == 0))
    {
        return 1;
    }
    else
    {

        temp = 1 + find_min3(find_carre(tab, taille_mat, x - 1, y - 1, carreRet),
                             find_carre(tab, taille_mat, x, y - 1, carreRet),
                             find_carre(tab, taille_mat, x - 1, y, carreRet));
        if (temp >= carreRet->taille)
        {
            carreRet->x = x;
            carreRet->y = y;
        }
        return temp;
    }
}

void aff_plus_Grand_Blanc(int *tab, size_t taille_mat, int taille, carre_blanc *carreRet)
{
    
}
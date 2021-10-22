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


//TODO: finir inversion lignes/colonnes
int find_carre(int pos, int *tab, int taille_mat, int numLig, int numCol)
{
    int tMax, pos1, pos2, pos3;
    //numLigne*taille_mat+Colonne
    //x*taille_ligne +y
    //PGCB(x-1;y-1)
    pos1 = ((numLig - 1) * taille_mat) + (numCol - 1);
    //PGCB(x;y-1)
    pos2 = (numLig * taille_mat) + (numCol - 1);
    //PGCB(x-1;y)
    pos3 = ((numLig - 1) * taille_mat) + numCol;

    //ICI SEGFAULT
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
                           find_carre(pos1, &tab[pos1], taille_mat, numLig - 1, numCol - 1), //PGCB(x-1;y-1)
                           find_carre(pos2, &tab[pos2], taille_mat, numLig,  numCol - 1)),    //PGCB(x;y-1
                       find_carre(pos3, &tab[pos1], taille_mat, numLig - 1, numCol));        //PGCB(x-1;y)
        return tMax;
    }
}

//TODO: finir inversion lignes/colonnes
//FIND_CARRE2, ENCORE PLUS CARRE
void find_carre2(int *tab, size_t taille_mat, int x, int y, Struct *CarretRet)
{
    int tailleCarreMax;
    //x*taille_ligne +y
    if (tab[x*taille_mat+y] == 1) //pixl noir
    {
        return 0;
    }
    //pixl blanc, et première ligne en haut ou première colonne à gauche
    if ( tab[pos] == 0)
    {
        if((x == 0 || y == 0)){
            return 1;
        }else
        tailleCarreMax = 1 + find_min(
                        find_min(
                            find_carre2(*tab,x-1,y-1),find_carre2(*tab,x,y-1)),
                        find_carre2(*tab, x-1,y));
        )
        //on vérifie si on a pas deja un carre plus grand
        if(tailleCarreMax >= CarreRet.taille){
            CarreRet.x=x;
            CarreRet.y=y;
            CarreRet.taille=tailleCarreMax;
        }
    }
        return CarreRet;
    }
}

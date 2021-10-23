/**
 * @file pgcb.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef PGCB_H
#define PGCB_H
#include <stdbool.h>

typedef struct CARRE_BLANC
{
    int x;
    int y;
    int taille;
}carre_blanc;


int fill_mat(int *mat, int taille_mat);

void aff_mat(int *tab, int tailletab);

int find_min(int a, int b);

int find_carre2(int *tab, size_t taille_mat, int x, int y, carre_blanc *CarreRet);

int find_carre(int pos, int *tab, int taille_mat, int numCol, int numLig);

#endif
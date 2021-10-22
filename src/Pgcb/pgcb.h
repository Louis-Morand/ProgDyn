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

int fill_mat(bool *mat, int taille_mat);

void aff_mat(bool *tab, int tailletab);

int find_min(int a, int b);


int find_carre(int pos, bool *tab, int taille_mat, int numCol, int numLig);

#endif
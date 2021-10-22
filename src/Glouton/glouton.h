/**
 * @file glouton.h
 * @author Louis Morand
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * 
 */

#ifndef GLOUTON_H
#define GLOUTON_H

typedef struct ITEM
{
    int valeur;
    int poids;
    float moyenne;

} item;

void tri_insertion_glouton(item tab[], int tailletab);
int find_glouton(item tabItems[], int nbItems, item sac[], int volSac);

#endif
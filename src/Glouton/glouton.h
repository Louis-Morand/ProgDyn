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

/**
 * @brief Structure d'objets, utilisée pour l'algorithme glouton
 * Contient deux entiers: le poids et la valeur d'un objet, ainsi que le rapport valeur/poids
 * Une amélioration pourrait etre de prendre en compte les objets avec un prix non entier
 */
typedef struct ITEM
{
    int valeur;
    int poids;
    float moyenne;

} item;

void tri_insertion_glouton(item tab[], int tailletab);
int find_glouton(item tabItems[], int nbItems, item sac[], int volSac);

#endif
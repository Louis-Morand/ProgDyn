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
 * @param int valeur La valeur de l'objet
 * @param int poids Le poids de l'objet
 * @param float moyenne Le rapport "qulité/prix" de l'objet, soit le résultat du rapport valeur/poids
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
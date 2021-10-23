/**
 * @file pgcb.h
 * @author Louis Morand
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

/**
 * @brief Structure permettant de stocker les informations du carré blanc trouvé
 * Contient la position (colonne, ligne) du pixel en bas à droite plus grand carré trouvé, ainsi que sa taille
 * @param int x La colonne du pixel en bas à droite du plus grand carre
 * @param int y La ligne du pixel en bas à droite du plus grand carre blanc
 * @param int taille La taille du carré
 */
typedef struct CARRE_BLANC
{
    int x;
    int y;
    int taille;
}carre_blanc;


void fill_mat(int *mat, int taille_mat);

void aff_mat(int *tab, int tailletab);

int find_min(int a, int b, int c);

int find_carre(int *tab, size_t taille_mat, int x, int y, carre_blanc *carreRet);

void replacement(int *mat, size_t taille_mat, int tailleMaxCarre, carre_blanc *carreRet);


#endif
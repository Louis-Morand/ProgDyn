/**
 * @file pgcb.c
 * @author Louis Morand
 * @brief Regroupe l'ensemble des fonctions utilisées par l'algorithme de recherche du plus grand carré blanc dans une image, ou ici, un tableau
 * Cet algorithme vise à rechercher et mettre en évidence le plus grand carré blanc situé dans un tableau donné.
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

/**
 * @brief Fonction permettant de remplir le tableau
 * Remplis la matrice à partir du modulo de nombre générés aléatoirements, permettant donc de le remplir de 0 ou de 1
 * @param mat le tableau à remplir
 * @param taille_mat la taille du tableau
 */
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

/**
 * @brief Fonction permettant d'afficher la matrice
 * Affiche un blanc si la valeur est 0, un * si la valeur est 1, est un # si la valeur est -1, représentative du plus grand carré blanc
 * @param mat la matrice à afficher
 * @param taille_mat la taille de la matrice
 */
void aff_mat(int *mat, int taille_mat)
{
    printf("\n");
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
            if (mat[i * taille_mat + j] == -1)
            {
                printf("#|");
            }
        }
        printf("\n");
    }
}

/**
 * @brief Fonction prmettant de trouver le minimum de trois nombres
 * 
 * @param a un entier à comparer
 * @param b le deuxième entier à comparer
 * @param c le troisième entier à comparer
 * @return int le plus grand des trois nombres
 */
int find_min(int a, int b, int c)
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

/**
 * @brief Fonction permettant de trouver le plus grand carre blanc
 * Cette fonction recherche, à partir des coordonnées x,y données, si un carré blanc se situe à partir de ses coordonnées.
 * Un carré est blanc si le pixel en bas à droite du carré est blanc, et les trois carrés de pixels en haut à gauche, droite, et en bas à gauche sont blancs.
 * Elle recherche donc récusrivement dans ces trois directions le nombre de pixels blancs, et s'arrete sur les bords du tableau.
 * Dans le tableau, un pixel blanc est représenté par un 0 et un pixel noir par un 1.
 * La fonction prends ensuite le minimum de la taille des trois cirections explorées, qui est la taille minimale du carré, et la renvoie.
 * Elle stocke ensuite dans la structure carre blanc la taille du plus grand carre, et ses coordonnées d'origine (soit les coordonnées en bas à droite du carré),
 * pour permettre de modifier l'affichage en mettant en évidence le carré trouvé. Elle n'ajoute que si un carré plus grand que celui deja stocké est trouvé.
 * 
 * @param mat la matrice dans lequel chercher
 * @param taille_mat la taille de la matrice
 * @param x la colonne à laquelle rechercher
 * @param y la lignesur laquelle rechercher
 * @param carreRet la structure permettant de stocker les informations du carre
 * @return int la taille du plus grand carre blanc trouvé
 */
int find_carre(int *mat, size_t taille_mat, int x, int y, carre_blanc *carreRet)
{

    int tailleCarreMax = 0;
    if (mat[x * taille_mat + y] == 1)
    {
        return 0;
    }
    if ((mat[x * taille_mat + y] == 0) && (x == 0 || y == 0))
    {
        return 1;
    }
    else
    {

        tailleCarreMax = 1 + find_min(find_carre(mat, taille_mat, x - 1, y - 1, carreRet),
                                       find_carre(mat, taille_mat, x, y - 1, carreRet),
                                       find_carre(mat, taille_mat, x - 1, y, carreRet));

        if (tailleCarreMax >= carreRet->taille)
        {
            carreRet->x = x;
            carreRet->y = y;
            carreRet->taille = tailleCarreMax;
        }
        return tailleCarreMax;
    }
}

/**
 * @brief Fonction de remplacement des valeurs du carré
 * Cette fonction est appellée une fois que le plus grand caré blanc a été trouvé, et remplace ses valeurs par la valeur -1,
 * pour permettre de modifier l'affichage et de mettre en avant le plus grand carré trouvé
 * @param mat la matrice dans lequel chercher
 * @param taille_mat la taille de la matrice
 * @param tailleMaxCarre la taille du plus grand carre blanc trouvé précédemment
 * @param carreRet la structure permettant de stocker les informations du carre
 */
void replacement(int *mat, size_t taille_mat, int tailleMaxCarre, carre_blanc *carreRet)
{
    int x = carreRet->x;
    int y = carreRet->y;

    for(int i = tailleMaxCarre; i>0; i--){
        for(int j = tailleMaxCarre; j >0; j--){
            mat[x * taille_mat + y] = -1;
            y = y-1;
        }
        x--;
        y = carreRet->y;
    }
}

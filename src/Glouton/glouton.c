/**
 * @file glouton.c
 * @author Louis Morand
 * @brief Regroupe l'ensemble des fonctions utilisées par l'algorithme glouton, appliqué à un probleme de remplissage de sac
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "glouton.h"

/**
 * @brief Réalise un tri par insertion 
 * Le but de ce tri est de trier le tableau d'objets par rapport valeur/poids décroissants, pour permettre de remplir le sac de manière optimisée
 * Pour cela, se base sur la structure objet, qui contient le poids, la valeur, et la moyenne valeur/poids de l'objet
 * 
 * @param tab tableau d'objets dans lequel rechercher
 * @param tailletab taille du tableau
 */
void tri_insertion_glouton(item tab[], int tailletab)
{
    int i, j;
    item val;
    for (i = 1; i < tailletab; ++i)
    {
        val = tab[i];
        for (j = i; j > 0 && tab[j - 1].moyenne > val.moyenne; j--)
            tab[j] = tab[j - 1];
        tab[j] = val;
    }
}

/**
 * @brief Fonction permettant de remplir le sac avec les objets triés 
 * 
 * Cette fonction remplis le sac d'objets à partir des objets déja triés, mais sans dépasser la contenance du sac.
 * Une amélioration de l'algorithme serait de retirer les objets du tableau une fois qu'ils ont été mis dans le sac
 * 
 * @param tabItems  tableau d'objets à mettre dans le sec
 * @param nbItems nombre d'objets disponibles à mettre
 * @param sac tableau d'objets, est le sac à remplir
 * @param volSac le volume du sac disponible, donc la taille du tableau
 * @return int la taille du sace rempli
 */
int find_glouton(item tabItems[], int nbItems, item sac[], int volSac)
{
    int tailleSacRempli = 0;
    tri_insertion_glouton(tabItems,nbItems);

    for (int i = nbItems -1 ; i >= 0; i--)
    {
        if (volSac == 0)
        {
            return tailleSacRempli;
        }
        if (tabItems->poids <= volSac)
        {
            sac[tailleSacRempli] = tabItems[i];
            volSac = volSac - tabItems[i].poids;
            tailleSacRempli++;
        }
    }
    return tailleSacRempli;
}
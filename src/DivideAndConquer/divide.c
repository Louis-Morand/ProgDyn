/**
 * @file divide.c
 * @author Louis morand
 * @brief Regroupe l'ensemble des fonctions utiles pour l'algorithme de recherche de nombre dans un tableau.
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "divide.h"

/**
 * @brief Recherche la valeur passée en paremètre par dychotomie du tableau
 * 
 * Pour rechercher la valeur, la fonction divise la portée de recherche par 2, en divisant l'intervalle de recherche par 2 à chaque itération. 
 * Cette fonction présuppose que le tableau est déja trié.
 * @param array Le tableau de valeurs
 * @param size_t La taille du tableau
 * @param value La valeur à trouver
 * @return int La position de la valeur ou -1 si la valeur n'a pas été trouvée
 */
int find_by_dichotomy(int array[], int size_t, int value)
{
    int max = size_t-1, min = 0, milieu = max / 2, ret = -1, intervalle;

    do
    {
        if (array[milieu] == value)
        {
            ret = milieu;
            return ret;
        }

        if (array[milieu] > value)
        {
            max = milieu;
        }
        else
        {
            if (array[milieu] < value)
            {
                min = milieu;
            }
        }
        milieu = (min + max) / 2;
        intervalle = max-min;
    } while (intervalle != 1);

    return ret;
}

/**
 * @brief Implémantation  du tri par bulle, mis au point dans le tp d'implémentation des tris.
 * 
 * @param tab le tableau à trier
 * @param tailletab la taille maximale du tableau
 */
void tri_bulle(int *tab, int tailletab)
{
	int val_inter;
	int nb_chmgt = 0;
	do
	{
		nb_chmgt = 0;
		for (int i = 0; i < tailletab - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				val_inter = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = val_inter;
			}
		}
		for (int i = 0; i < tailletab - 1; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				nb_chmgt++;
				
			}
		}
	} while (nb_chmgt != 0);
}
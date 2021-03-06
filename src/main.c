/**
 * @file main.c
 * @author Louis Morand
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <limits.h>
#include "Pgcb/pgcb.h"
#include "./Glouton/glouton.h"
#include "./DivideAndConquer/divide.h"
#include "./DivideAndConquer/divide.h"

/**
 * @mainpage ProgDyn Documentation
 * 
 * @brief Documentation du Tp ProgDyn
 * Le but de ce TP est d'implémenter trois algorithmes différents, permettant de toucher à des contraintes de programmation dynamique
 * Un algorithme de recherche par division, dans un tableau, un algorithme glouton, et un algorithme de rerche récursive dans une matrice pour trouver le plus grand carré libre
 *
 */


/**
 * @brief Contient les tests rélisés par la fonction de recherche dans un tableau par divison
 * Initialise la tableau, la valeur cherchée, et gère l'affichage des résultats.
 * @param int maxtab la taille maximale du tableau
 * 
 */
void tests_Conquer()
{
	int maxTab = 30, tabDivide[maxTab], res = 0, valCherchee = 977;
	srand(58);
	printf("\nTESTS ALGO DIVISION:\n");
	for (int i = 0; i < maxTab; i++)
	{
		tabDivide[i] = (rand() % 999) + 1;
	}
	tri_bulle(tabDivide, maxTab);

	for (int i = 0; i < maxTab; i++)
	{
		printf("Indice %d: %d;\t\t", i, tabDivide[i]);
	}

	res = find_by_dichotomy(tabDivide, maxTab, valCherchee);
	if(res == -1){
		printf("\n\nValeur %d non contenue dans le tableau\n\n", valCherchee);
	}else printf("\nposition: %d\n", res);
}

/**
 * @brief Fonction regroupant les tests réalisés par l'algorithme de recherche glouton
 * Initialise un tablau de sac, dobjets, définis le nombre d'objets, le poids maximum du sac.
 * @param int tailleTabMax la taille maximale du tableau
 * 
 */
void tests_glouton()
{
	printf("\n\n TESTS ALGO GLOUTON:\n\n");

	int tailleTabMax = 20, poidsSacMax = 30, tailleSacRempli, moyenne;
	item tab[tailleTabMax];
	item sac[tailleTabMax];

	srand(10);
	for (int i = 0; i < tailleTabMax; i++)
	{
		tab[i].valeur = (rand() % 10) + 1;
		tab[i].poids = (rand() % 10) + 1;
		moyenne = tab[i].valeur / tab[i].poids;
		tab[i].moyenne = moyenne;
	}
	printf("\nTableau d'objets:");
	for (int i = 0; i < tailleTabMax; i++)
	{
		printf("\nPoids: %d, Valeur: %d, Moyenne: %.2f", tab[i].poids, tab[i].valeur, tab[i].moyenne);
	}
	tailleSacRempli = find_glouton(tab, tailleTabMax, sac, poidsSacMax);

	printf("\n\nTableau de sac:");
	for (int i = 0; i < tailleSacRempli; i++)
	{
		printf("\nObjet num %d: Poids: %d, Valeur: %d", i, sac[i].poids, sac[i].valeur);
	}
}


/**
 * @brief Fonction de tests du plus grand carre blanc
 * Initialise un tableau, le remplis de valeurs aléatoires, puis recherche le carré, affiche sa position, et affiche la matrice en mettant en évidence le carré
 * @param size_t taille_mat La taille maximale de la matrice
 * 
 */
void tests_pgcb()
{
	printf("\n\nTESTS RECHERCHE DANS MATRICE:\n");

	size_t taille_mat = 10;
	int *mat = malloc(sizeof(int)*taille_mat*taille_mat);

	carre_blanc *carreRet = malloc(sizeof(carre_blanc));
	carreRet->x = 0;
	carreRet->y = 0;
	carreRet->taille = 0;

	int tailleMaxCarre = 0, temp;

	fill_mat(mat, taille_mat);
    aff_mat(mat, taille_mat);

	for (int numCol = 0; numCol < taille_mat; numCol++)
	{
		for (int numLig = 0; numLig < taille_mat; numLig++)
		{
			temp = find_carre(mat, taille_mat, numCol, numLig, carreRet);
			if(temp> tailleMaxCarre){
				tailleMaxCarre = temp;
			}
		}
	}
	replacement(mat, taille_mat, tailleMaxCarre, carreRet);
	aff_mat(mat, taille_mat);
	free(mat);
	free(carreRet);

}

int test_init()
{
	return 0;
}
int test_cleanup()
{
	return 0;
}

int main()
{
	tests_Conquer();
	tests_glouton();
	tests_pgcb();

	return (EXIT_SUCCESS);
}
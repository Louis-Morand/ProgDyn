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
 * @brief Contient les tests rélisés par la fonction de recherche dans un tableau par divison
 * Initialise la tableau, la valeur cherchée, et gère l'affichage des résultats.
 * 
 */
void tests_Conquer()
{

	int maxTab = 100, tabDivide[maxTab], res = 0, valCherchee = 977;
	srand(58);
	for (int i = 0; i < maxTab; i++)
	{
		tabDivide[i] = (rand() % 999) + 1;
	}
	tri_bulle(tabDivide, maxTab);

	for (int i = 0; i < maxTab; i++)
	{
		printf("\tTab %d: %d", i, tabDivide[i]);
	}

	res = find_by_dichotomy(tabDivide, maxTab, valCherchee);
	if(res == -1){
		printf("Valeur %d non contenue dans le tableau", valCherchee);
	}
	printf("\nposition: %d\n", res);
}

/**
 * @brief Fonction regroupant les tests réalisés par l'algorithme de recherche glouton
 * Initialise un tablau de sac, dobjets, définis le nombre d'objets, le poids maximum du sac.
 * 
 */
void tests_glouton()
{
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
	printf("tableau d'objets:");
	for (int i = 0; i < tailleTabMax; i++)
	{
		printf("\nPour %d: TabPoids: %d, TabValeur: %d, TabMoyenne: %.2f", i, tab[i].poids, tab[i].valeur, tab[i].moyenne);
	}
	tailleSacRempli = find_glouton(tab, tailleTabMax, sac, poidsSacMax);

	printf("\ntableau de sac:");
	for (int i = 0; i < tailleSacRempli; i++)
	{
		printf("\nPour %d: TabPoids: %d, TabValeur: %d", i, sac[i].poids, sac[i].valeur);
	}
}


/**
 * @brief Fonction de tests du plus grand carre blanc
 * Initialise un tableau, le remplis de valeurs aléatoires, puis recherche le carré, affiche sa position, et affiche la matrice en mettant en évidence le carré
 * 
 */
void tests_pgcb()
{
	size_t taille_mat = 30;
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
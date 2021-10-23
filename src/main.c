/**
 * @file main.c
 * @author your name (you@domain.com)
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
		//tab[i].moyenne = (tab[i].valeur)/(tab[i].poids);
	}

	//tab[0].poids = 6;
	//tab[0].valeur = 7;
	//tab[0].moyenne = 6.5;

	//tab[1].poids = 5;
	//tab[1].valeur = 5;
	//tab[1].moyenne = 5;

	//tab[2].poids = 5;
	//tab[2].valeur = 5;
	//tab[2].moyenne = 5;

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

void tests_Conquer()
{

	int maxTab = 100, tabDivide[maxTab], res = 0;
	srand(58);
	for (int i = 0; i < maxTab; i++)
	{
		tabDivide[i] = (rand() % 999) + 1;
	}
	tri_bulle(tabDivide, maxTab);

	for (int i = 0; i < maxTab; i++)
	{
		//printf("\nTab %d: %d", i, tabDivide[i]);
	}

	res = find_by_dichotomy(tabDivide, maxTab, 977);
	//printf("\nposition: %d\n", res);
}

int find_max(int a, int b){
	if (a > b)
    {
        return a;
    }
    else
        return b;
}


void tests_pgcb()
{
	size_t taille_mat = 3;
	int *mat = malloc(sizeof(int)*taille_mat*taille_mat);
	carre_blanc *carreRet = malloc(sizeof(carre_blanc));
	carreRet->x = 0;
	carreRet->y = 0;
	carreRet->taille = 0;

	//fill_mat(*mat, taille_mat);

	mat[0]=1;
	mat[1]=0;
	mat[2]=0;
	//mat[0][3]=0;

	mat[3]=1;
	mat[4]=0;
	mat[5]=0;
	//mat[1][3]=0;

	mat[6]=1;
	mat[7]=0;
	mat[8]=0;
	//mat[2][3]=0;

	// mat[3][0]=1;
	// mat[3][1]=1;
	// mat[3][2]=1;
	// mat[3][3]=1;
    aff_mat(mat, taille_mat);


	for (int numCol = 0; numCol < taille_mat; numCol++)
	{
		for (int numLig = 0; numLig < taille_mat; numLig++)
		{
			find_carre2(mat, taille_mat, numCol, numLig, carreRet);
		}
	}
	printf("\nCARRE MIN: %d, x:%d, y:%d\n", carreRet->taille, carreRet->x, carreRet->y);
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
	// CU_initialize_registry();

	// CU_pSuite *tests = CU_add_suite("tests ProgDyn", test_init, test_cleanup);

	// tests_Conquer();
	// tests_glouton();
	tests_pgcb();

	// CU_add_test(tests, "test Divide and Conquer", tests_glouton);
	// CU_add_test(tests, "test Glouton", tests_Conquer);
	// CU_add_test(tests, "test A FAIRE", test_AFAIRE);

	// CU_basic_run_tests();
	// test_cleanup();

	return (EXIT_SUCCESS);
}
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

void init_glouton()
{
	int tailleTabMax = 20, poidsSacMax = 30, tailleSacRempli;
	item tab[tailleTabMax];
	item sac[tailleTabMax];

	srand(5);
	for (int i = 0; i < tailleTabMax; i++)
	{
	tab[i].valeur = rand() %10;
	tab[i].poids = rand() %10;
	tab[i].moyenne = tab[i].valeur/tab[i].poids;
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
	for(int i=0;i<3;i++){
		printf("\nPour %d: TabPoids: %d, TabValeur: %d, TabMoyenne: %.2f", i, tab[i].poids, tab[i].valeur, tab[i].moyenne);
	}
	tailleSacRempli =  find_glouton(tab, tailleTabMax, sac, poidsSacMax);

	printf("\ntableau de sac:");
	for(int i=0;i<tailleSacRempli;i++){
		printf("\nPour %d: TabPoids: %d, TabValeur: %d, TabMoyenne: %.2f", i, sac[i].poids, sac[i].valeur, sac[i].moyenne);
	}
}

void init_Conquer(){

	int maxTab = 100, tabDivide[maxTab], res = 0;
	srand(58);
	for (int i = 0; i < maxTab; i++)
	{
		tabDivide[i] = (rand() %999) + 1;
	}
	tri_bulle(tabDivide, maxTab);

	for (int i = 0; i < maxTab; i++)
	{
		//printf("\nTab %d: %d", i, tabDivide[i]);
	}

	res = find_by_dichotomy(tabDivide, maxTab, 977);
	//printf("\nposition: %d\n", res);

}

int main()
{	
	init_Conquer();
	init_glouton();
}
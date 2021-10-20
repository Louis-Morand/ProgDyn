/**
 * @file glouton.c
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
#include <stdbool.h>
#include "glouton.h"

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

int find_glouton(item tabItems[], int nbItems, item sac[], int volSac)
{
    int j = 0;
    tri_insertion_glouton(tabItems,nbItems);

    for (int i = 0; i < nbItems; i++)
    {
        if (volSac == 0)
        {
            return j;
        }
        if (tabItems->poids <= volSac)
        {
            sac[j] = tabItems[i];
            volSac = volSac - tabItems[i].poids;
            j++;
        }
    }
    return j;
}
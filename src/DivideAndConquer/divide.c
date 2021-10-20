/**
 * @file divide.c
 * @author Louis morand
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "divide.h"

/**
 * @brief 
 * 
 * @param array Le tableau de valeurs
 * @param size_t La taille du tableau
 * @param value La valeur à trouver
 * @return int La position de la valeur ou -1
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
/*-----------------------------------------------------------------\
|Ces fonctions servent à réduire les nombres en prenant le produits|
|de leurs chiffre.                                                 |
\-----------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void reduce(char* nombre); //Prend un argument une chaine sur laquelle on a écrit un nombre, fait le produit de ses chiffres et met le résultat dans nombre
int howManyTimes(uint64_t val); //Regarde combien de fois on peut réduire val avant d'avoir un nombre d'un seul chiffre


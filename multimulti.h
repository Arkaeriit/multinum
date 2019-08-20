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
int writeLine(char* line,char* file);//Écrit la ligne line dans le fichier file en rajoutant un retour chariot. Renvoie 0 si tout va bien et 1 si on arrive pas à ouvrir le fichier.
int sampleAnalyse(char* file,uint64_t start,uint64_t stop,int threadmax,int threadNumber); //Analyse le nombre de reduction pour les nombres de start à stop en reniseignant les découvertes dans file. Si il y a du multithreading on reiseigne le nombre e thread dans threadmax et on indique le numéro de la thread dans threadNumber à partir de 0. Revoie 0 si tout va bien.


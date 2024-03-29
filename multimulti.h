/*-----------------------------------------------------------------\
|Ces fonctions servent à réduire les nombres en prenant le produits|
|de leurs chiffre.                                                 |
\-----------------------------------------------------------------*/

#ifndef MULTIMULTI
#define MULTIMULTI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

void reduce(char* nombre); //Prend un argument une chaine sur laquelle on a écrit un nombre, fait le produit de ses chiffres et met le résultat dans nombre
int howManyTimes(char* nombre); //Regarde combien de fois on peut réduire le nombre écrit dans la chaine nombre avant d'avoir un nombre d'un seul chiffre
int writeLine(char* line,char* file);//Écrit la ligne line dans le fichier file en rajoutant un retour chariot. Renvoie 0 si tout va bien et 1 si on arrive pas à ouvrir le fichier.
int sampleAnalyse(char* file,uint64_t start,uint64_t stop,int threadmax,int threadNumber); //Analyse le nombre de reduction pour les nombres de start à stop en reniseignant les découvertes dans file. Si il y a du multithreading on reiseigne le nombre e thread dans threadmax et on indique le numéro de la thread dans threadNumber à partir de 0. Revoie 0 si tout va bien.

void test(); //on verifie que tout va bien

typedef struct combiARG {
    int nombreChiffre; //nombre de chiffre dans les nombres étudiés
    uint64_t nombreCombinaisons; //nombre de combinaisons trouvées
    char** combinaisons; //liste des nombres
} combiARG;

void combiaisonLoop(combiARG* args); //boucles appelées par getCombinaisons
void addCharX(char* string,char elem,int combien,combiARG* args); //ajoute combien fois elem à la fil de string et évalue ses reductions
void rmChar(char* string,int combien); //enlève les combien derniers éléments de string
combiARG* getCombinaisons(int digits); //renvoie une structure servant à retrouver les combinaisons de digits chiffres
void combiAnalyze(char* file,char** listCombi,uint64_t nombreCombinaisons); //regarde le nombre de reductions du vecteur de nombre listCommbi (les nombreCombinaisos élements) et écrit le résultat dans file
uint64_t factorial(unsigned int);

#endif

/*------------------------------------------------------------\
|Ces fonctions servent à faire les annalyses en multithreading|
\------------------------------------------------------------*/


#include <pthread.h>
#include "multimulti.h"

typedef struct sampleArg {
    char* file;
    uint64_t start;
    uint64_t stop;
    int threadmax;
    int threadNumber;
} sampleArg;

void* analyzeWarper(void* arg); //permet de lancer les analyses dans un thread
void launchAnalyzes(char* file,uint64_t start,uint64_t stop,int threadmax); //lances plusieurs annalyses en parrallèle.

#include "multimulti.h"

void reduce(char* nombre){
    uint64_t res = 1;
    for(int i=0;i<strlen(nombre);i++){
        res *= *(nombre + i) - 48; //On regarde la valeuleur du i-ème chiffre de nombre
    }
    sprintf(nombre,"%lu",res); //On met le nombre résuit dans la string que l'on utilise
}

int howManyTimes(uint64_t val){
    char* nombre = malloc(sizeof(char) * 22); //On a la place de mettre n'importe quel nombre représentable sur 64 bits
    sprintf(nombre,"%lu",val);
    int tours = 0;
    while(strlen(nombre) > 1){
        reduce(nombre);
        tours++;
    }
    free(nombre);
    return tours;
}

int writeLine(char* line,char* file){
    FILE* fpnt;
    if( (fpnt = fopen(file,"a")) == NULL){
        fprintf(stderr,"Error: impossible to write in %s.\n",file);
        return 1;
    }else{
        fprintf(fpnt,"%s\n",line);
        fclose(fpnt);
        return 0;
    }
}

int sampleAnalyse(char* file,uint64_t start,uint64_t stop,int threadmax,int threadNumber){
    int max=0; //nombre maximum de reductions à faire
    char* bufferline = malloc(sizeof(char) * 256); //buffer poour céer les lignes à écrire dans le fichier
    for(uint64_t i = start;i<stop;i++){
        if(i%threadmax == threadNumber){ //On est à un nombre que l'on doit faire
            int act = howManyTimes(i);
            if(act > max){ //On a un nouveau maximum donc on le documente
                max = act;
                sprintf(bufferline,"%lu %i",i,act);
                writeLine(bufferline,file);
            }
        }
    }
    free(bufferline);
    return 0;
}


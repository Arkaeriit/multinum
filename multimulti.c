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
    return tours;
}

int writeLine(char* line,char* file){
    FILE* fpnt;
    if( (fptr = fopen(file,"a")) == NULL){
        fprintf(stderr,"Error: impossible to write in %s.\n",file);
        return 1;
    }else{
        fprintf(fpnt,"%s\n",line);
        fclose(fptr);
        return 0;
    }
}

//void sampleAnnalyse(char* file,uint64_t start,uint64_t stop

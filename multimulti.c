#include "multimulti.h"

void reduce(char* nombre){
    uint64_t res = 1;
    for(int i=0;i<strlen(nombre);i++){
        res *= *(nombre + i) - 48; //On regarde la valeuleur du i-ème chiffre de nombre
    }
    sprintf(nombre,"%lu",res); //On met le nombre résuit dans la string que l'on utilise
}

int howManyTimes(char* nombre){
    int tours = 0;
    while(strlen(nombre) > 1){
        reduce(nombre);
        tours++;
    }
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
    char* nombre = malloc(sizeof(char) * 22); //On a la place de mettre n'importe quel nombre représentable sur 64 bits
    int max=0; //nombre maximum de reductions à faire
    char* bufferline = malloc(sizeof(char) * 256); //buffer poour céer les lignes à écrire dans le fichier
    for(uint64_t i = start;i<stop;i++){
        if(i%threadmax == threadNumber){ //On est à un nombre que l'on doit faire
            sprintf(nombre,"%lu",i);
            int act = howManyTimes(nombre);
            if(act > max){ //On a un nouveau maximum donc on le documente
                max = act;
                sprintf(bufferline,"%lu %i",i,act);
                writeLine(bufferline,file);
            }
        }
    }
    free(bufferline);
    free(nombre);
    return 0;
}

void palindromes(char* nombre,int chiffreAct,int tailleMax,int maxReduce){
    if(strlen(nombre) == tailleMax){ //On a construit le nombre
        /*int red = howManyTimes(nombre);
        if(red > maxReduce){
            maxReduce = red;
            char* line = malloc(sizeof(char) * 256);
            sprintf(line,"%s %i",nombre,red);
            writeLine(line,"/dev/stdout"); //TODO : change
            free(line);
        }*/ printf("%s\n",nombre);
    }else{ //On construit recursivement le nombre
        if(chiffreAct < 10){ //Si on a déja placé tout les noombres cela ne sert à rien de continuer
            for(int i = 0;i < tailleMax + (strlen(nombre) );i++){ //i represente le nombre de fois que l'on va ajouter nombreAct à nombre
                //char* nombreCopy = malloc(sizeof(char) * 22);
                //memcpy(nombreCopy,nombre,strlen(nombre));
                for(int j = 0;j < i;j++){ //On ajoute i fois nombreActuel à nombre
                    *(nombre + strlen(nombre)) = (char) chiffreAct + 48; //On met ce que l'on veut à la fin de nombre
                }
                palindromes(nombre,chiffreAct + 1,tailleMax,maxReduce); //On continue de remplir
                for(int j=0;j<i;j++){
                    *(nombre + strlen(nombre) - 1) = 0;
                //free(nombreCopy);
                }
            }
        }else{
            chiffreAct = 0;
        }
    }
}

#define limite (tailleMax - strlen(number) + 1)
#define sauverlesmeubles if(limite>tailleMax+4) return;if(strlen(number) != tailleMax)
void palindromesLoop(combiARG* args){
    int tailleMax = args->nombreChiffre;
    char* number = malloc(sizeof(char) * 22);
    for(int num2 = 0;num2 < limite;num2++){
        addCharX(number,'2',num2,args);
        sauverlesmeubles
        for(int num3 = 0;num3 < limite;num3++){
            addCharX(number,'3',num3,args);
            sauverlesmeubles
            for(int num4 = 0;num4 < limite;num4++){
                addCharX(number,'4',num4,args);
                sauverlesmeubles
                for(int num5 = 0;num5 < limite;num5++){
                    addCharX(number,'5',num5,args);
                    sauverlesmeubles
                    for(int num6 = 0;num6 < limite;num6++){
                        addCharX(number,'6',num6,args);
                        sauverlesmeubles
                        for(int num7 = 0;num7 < limite;num7++){
                            addCharX(number,'7',num7,args);
                            sauverlesmeubles
                            for(int num8 = 0;num8 < limite;num8++){
                                addCharX(number,'8',num8,args);
                                sauverlesmeubles
                                for(int num9 = 0;num9 < limite;num9++){
                                    addCharX(number,'9',num9,args);
                                    rmChar(number,num9);
                                }
                                rmChar(number,num8);
                            }
                            rmChar(number,num7);
                        }
                        rmChar(number,num6);
                    }
                    rmChar(number,num5);
                }
                rmChar(number,num4);
            }
            rmChar(number,num3);
        }
        rmChar(number,num2);
    }
    free(number);
}

void addCharX(char* string,char elem,int combien,combiARG* args){
    for(int i = 0;i < combien;i++){
        *(string + strlen(string)) = elem;
    }
    if(strlen(string) == args->nombreChiffre){ //On a une nouvelle combinaison
        (args->nombreCombinaisons)++; //On incrémente le nombre de combinaisons
        *((args->combinaisons) + args->nombreCombinaisons - 1) = malloc(sizeof(char) * 22);
        memcpy(*(args->combinaisons + args->nombreCombinaisons - 1),string,strlen(string)); //On ajoute la combinaison à notre liste
    }
}

void rmChar(char* string,int combien){
    for(int i = 0;i < combien;i++){
        *(string + strlen(string) - 1) = 0;
    }
}

void test(){
    combiARG* comb = getCombinaisons(11);
    printf("nombre de combinaisons : %i\n",comb->nombreCombinaisons);
    printf("%s\n",*(comb->combinaisons + comb->nombreCombinaisons - 2));
    printf("%s\n",*(comb->combinaisons + comb->nombreCombinaisons - 4));
    printf("%s\n",*(comb->combinaisons + comb->nombreCombinaisons - 3));
    printf("%s\n",*(comb->combinaisons + comb->nombreCombinaisons - 1));
}

combiARG* getCombinaisons(int digits){
    uint64_t combinaisonsPossibles = ((factorial(8 + digits - 1)) / (factorial(digits) * factorial(8 - 1)));
    printf("%lu\n",combinaisonsPossibles);
    combiARG* args = malloc(sizeof(combiARG));
    args->nombreChiffre = digits;
    args->nombreCombinaisons = 0; //nombre d'éléments dans la liste suivante
    args->combinaisons = (char**) malloc(sizeof(char*) * combinaisonsPossibles);
    palindromesLoop(args);
    return args;
}

uint64_t factorial(unsigned int n){
    if(n < 2){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}


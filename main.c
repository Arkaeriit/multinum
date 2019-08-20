#include "multimulti.h"

void manuel();

int main(int argc,char** argv){
    if(argc > 2){ //On a des arguments
        if(!strcmp(*(argv + 1),"reduce")){ //On demande combien de tours il faut pour réduire un nombre
            if(argc == 3){ //On a ce qu'il faut come arguments
                uint64_t val = 0;
                sscanf(*(argv + 2),"%lu",&val);
                int count = howManyTimes(val);
                printf("%i\n",count);
            }else{
                manuel();
            }
        }
        if(!strcmp(*(argv + 1),"analyse")){
            if(argc == 5 || argc == 6){ //bon nombre d'arguments
                if(argc == 5 || (argc == 6 && !strcmp(*(argv + 5),"1"))){ // 1 seule thread
                    uint64_t start,stop = 0;
                    sscanf(*(argv + 3),"%lu",&start);
                    sscanf(*(argv + 4),"%lu",&stop);
                    sampleAnalyse(*(argv + 2),start,stop,1,0);
                }
            }else{
                manuel();
            }
        }
    }else{ //pas assez d'arguments
        manuel();
    }
    return 0;
}

void manuel(){
    printf("nope\n");
}


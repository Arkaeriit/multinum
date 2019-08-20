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
    }else{ //pas assez d'arguments
        manuel();
    }
    return 0;
}

void manuel(){
    printf("nope\n");
}


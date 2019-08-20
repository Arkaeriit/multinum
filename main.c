#include "multimulti.h"
#include "multithreading.h"

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
        if(!strcmp(*(argv + 1),"analyze")){
            if(argc == 5 || argc == 6){ //bon nombre d'arguments
                if(argc == 5 || (argc == 6 && !strcmp(*(argv + 5),"1"))){ // 1 seule thread
                    uint64_t start,stop = 0;
                    sscanf(*(argv + 3),"%lu",&start);
                    sscanf(*(argv + 4),"%lu",&stop);
                    sampleAnalyse(*(argv + 2),start,stop,1,0);
                }else{ //multithreading
                    uint64_t start,stop = 0;
                    sscanf(*(argv + 3),"%lu",&start);
                    sscanf(*(argv + 4),"%lu",&stop);
                    int maxthread = 0;
                sscanf(*(argv + 5),"%i",&maxthread);
                    launchAnalyzes(*(argv + 2),start,stop,maxthread);
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
    printf("Usage: ./multinum [option] <parameters...>\n\nAvailable options:\n* reduce: Use './multinum reduce [number]' to know how many times you have to reduce 'number' to get a 1 digit number.\n* analyze: Use './multinum analyze [file] [start] [stop] <threads>' to know the witch numbers take the more time to be reduced to a single digit number between 'start' and 'stop'. The results will be stored in 'file' where each interesting number will be stored and the number of steps go reduce them to 1 digit number will be written next to them after a space. The calculation will be spread between 'threads' various threads.\n");
}


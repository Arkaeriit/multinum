#include "multithreading.h"

void* analyzeWraper(void* arg){
    sampleArg* sarg = arg;
    sampleAnalyse(sarg->file,sarg->start,sarg->stop,sarg->threadmax,sarg->threadNumber);
    return NULL;
}

void launchAnalyzes(char* file,uint64_t start,uint64_t stop,int threadmax){
    pthread_t thread[threadmax];
    sampleArg* threadsArg = malloc(sizeof(sampleArg) * threadmax);
    for(int i=0;i<threadmax;i++){
        (threadsArg + i)->file = file;
        (threadsArg + i)->start = start;
        (threadsArg + i)->stop = stop;
        (threadsArg + i)->threadmax = threadmax;
        (threadsArg + i)-> threadNumber = i;
        pthread_create(&thread[i],NULL,analyzeWraper,(void*) (threadsArg + i));
    }
    free(threadsArg);
    for(int i=0;i<threadmax;i++){
        pthread_join(thread[i],NULL);
    }
}


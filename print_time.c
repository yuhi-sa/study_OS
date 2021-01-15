#include<stdio.h> 
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *func(void *arg){
    time_t now;
    struct tm *tmnow;

    while(1){
        now=time(NULL);
        tmnow=localtime(&now);
        printf("\r%02d:%02d:%02d",tmnow->tm_hour,tmnow->tm_min,tmnow->tm_sec);
          fflush(stdout);
          sleep(1);
     }
    return NULL;
}

int main(){
    pthread_t thread_id;

    if(pthread_create(&thread_id,NULL,func,NULL) != 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
getc(stdin);
pthread_cancel(thread_id);
pthread_join(thread_id,NULL);
exit(EXIT_SUCCESS);
}
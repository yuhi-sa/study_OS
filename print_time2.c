#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

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

void ctrlc(){
    static int n=0;
    printf("Ctrl-C pressded %d time\nSend SIGUSR1\n",++n);
    if(n==1000)
        exit(EXIT_SUCCESS);      
}

int main(){
    pid_t pid;
    unsigned int c=0;

    if((pid=fork())==0){
        execl("kill-child","kill-child",NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }do{
    if(signal(SIGINT,(void*)ctrlc)==SIG_ERR){
        perror("signal");
        kill(pid,SIGUSR1);
    }
  }while(c!=EOF);
return 0;
}
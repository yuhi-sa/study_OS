#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int n=0;

void alarmreceived(){
    ++n;
    printf("SIGALRM received. \n");
}

void ctrlc(){
    n=0;
    static int i=0;
    printf("Ctrl-C pressded %d time\nReset count\n",++i);
    if(i==1000)
        exit(EXIT_SUCCESS);      
}

int main(){
    if(signal(SIGALRM,(void*)alarmreceived)==SIG_ERR){
        perror("signai");
        exit(EXIT_FAILURE);
    }

    while(n<3){
    if(signal(SIGINT,(void*)ctrlc)==SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }
    alarm(5);
        printf("Alarm has set.\n");
        pause();
      
    }
    exit(EXIT_SUCCESS);
}
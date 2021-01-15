#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

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
    printf("Send signal (ctrlc)?\n");
    if(signal(SIGINT,(void*)ctrlc)==SIG_ERR){
        perror("signal");
        kill(pid,SIGUSR1);
    }
  }while(c!=EOF);
return 0;
}
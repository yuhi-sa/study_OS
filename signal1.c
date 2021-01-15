#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
void ctrlc(){
    static int n=0;
    printf("Ctrl-C pressded %d time\n",++n);
    if(n==10)
        exit(EXIT_SUCCESS);      
}

int main(){
    if(signal(SIGINT,(void*)ctrlc)==SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }
    for(;;){}
}
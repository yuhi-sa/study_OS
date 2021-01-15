#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t child_pid1,child_pid2;
	
	child_pid1=fork(); //子プロセス1を生成
	if(child_pid1==0){
		printf("i am a first child with pid = %d. My parent pid is %d.\n",getpid(),getppid());
		child_pid2=fork(); //孫プロセスを生成
	}

	if(child_pid2==0){
		printf("i am a child with pid = %d. My parent pid is %d.\n",getpid(),getppid());	
		}
		
	exit(EXIT_SUCCESS);
}

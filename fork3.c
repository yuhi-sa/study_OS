#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t child_pid1,child_pid2,child_pid3;
	
	child_pid1=fork(); //子プロセス1を生成
	if(child_pid1==0){
		printf("i am a first child with pid = %d. My parent pid is %d.\n",getpid(),getppid());
	}else{
	child_pid2=fork(); //子プロセス2を生成
	if(child_pid2==0){
		printf("i am a second child with pid = %d. My parent pid is %d.\n",getpid(),getppid());	
		}else{
	child_pid3=fork(); //子プロセス3を生成
	if(child_pid3==0){
		printf("i am a third child with pid = %d. My parent pid is %d.\n",getpid(),getppid());	
		}else{
			printf("I am a parent with pid=%d. My first ,second and third children are %d,%d and %d.\n",
			getpid(),child_pid1,child_pid2,child_pid3);
		}
		}
	}
	exit(EXIT_SUCCESS);
}
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv){
int fd;
int i, n;
char buffer[512];
fd = open(argv[1], O_RDWR); //コマンドラインに入力したファイルを読み書き可で開く

while((n=read(fd,buffer,sizeof(buffer)))>0){
	for(i=0;i<n;++i)
		if((buffer[i] >='a' )&&  (buffer[i] <= 'z')){
		buffer[i]=buffer[i]-('a'-'A'); //小文字を大文字に変換
		lseek(fd, -n,SEEK_CUR);
		write(fd,buffer,n);
		}
		else if((buffer[i] >='A' )&&  (buffer[i] <= 'Z')){		
		buffer[i]=buffer[i]+('a'-'A'); //大文字を小文字に変換
		lseek(fd, -n,SEEK_CUR);
		write(fd,buffer,n);
		}
}
close(fd);
exit(0);
}
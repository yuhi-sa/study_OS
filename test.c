#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>
main(int argc, char **argv){
	struct stat sbuf;
	if(stat(argv[1], &sbuf)==-1){
		perror("stat");
	}else{
	printf("最終アクセス時刻=%s\n",ctime(&sbuf.st_atime));
	printf("最終変更時刻=%s\n",ctime(&sbuf.st_mtime));
	printf("最終ステータス時刻=%s\n",ctime(&sbuf.st_ctime));
 	}
}

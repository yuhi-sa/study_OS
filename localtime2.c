#include<stdio.h>
#include<time.h>
main(){
	int a;
	scanf("%d",&a); //コマンドラインから秒数を入力する
	time_t now;
	struct tm *tmnow;
	now=time(NULL)+a;  //入力した秒数分、時間を進める
	tmnow=localtime(&now);

	
printf("%d/%d/%d %d:%d:%d\n",
			tmnow->tm_year+1900, tmnow->tm_mon+1, tmnow->tm_mday,
			tmnow->tm_hour, tmnow->tm_min,tmnow->tm_sec); 
}
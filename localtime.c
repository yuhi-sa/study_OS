#include<stdio.h>
#include<time.h>
main(){
	time_t now;
	struct tm *tmnow;
	now=time(NULL);
	tmnow=localtime(&now);

	char *wday[] = {"日","月","火","水","木","金","土"};
	// tm_wdayでは日曜日が0とする
	
 printf("曜日: %s\n",wday[tmnow->tm_wday]);
 
}
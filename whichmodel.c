#include <stdio.h>
int main( ) {
		 
char * data;
if (sizeof(data)==8) // 64bit OS
{
	if(sizeof(int)==8)
			printf("IP64\n");
	else if(sizeof(long)==8)
			printf("LP64\n");
	else if(sizeof(long)==4)
			printf("LLP64\n");
}
else if (sizeof(data)==4) //32bit OS
{
	if(sizeof(int)==4)
			printf("ILP32\n");
	else if(sizeof(int)==2)
			printf("LP32\n");
}
else if(sizeof(data)==2)
	printf("16 bit OS\n");
}
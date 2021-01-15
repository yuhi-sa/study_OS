 #include<stdio.h>
 int main(){
     int i,a[10],*p;

     for(i=1;i<=10;i++){
         a[i]=i;
     }

p= &a[2];

printf("%d\n",a[4]);
printf("%d\n",*(a+4));
printf("%d\n",5[a]);
printf("%d\n",p[-1]);
p += 4;
printf("%d\n",p[-1]);
printf("%d\n",a[4]);
 }
 
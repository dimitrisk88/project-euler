#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,k,l,m,n,o,counter=1;
	for(i=0;i<=2;i++)
	for(j=0;j<=4-i*2;j++)
	for(k=0;k<=10-i*5-j*2;k++)
	for(l=0;l<=20-i*10-j*5-k*2;l++)
	for(m=0;m<=40-i*20-j*10-k*4-l*2;m++)
	for(n=0;n<=100-i*50-j*25-k*10-l*5-m*2;n++)
	for(o=0;o<=200-i*100-j*50-k*20-l*10-m*5-n*2;o++)
	if(i*100+j*50+k*20+l*10+m*5+n*2+o==200)
	counter++;
	printf("%d\n",counter);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

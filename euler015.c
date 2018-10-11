#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC,a=1;
	int i,j;
	for(i=1;i<=20;i++)
	{
		a=a*(i+20)/i;
	}
	printf("%.0f\n",a);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

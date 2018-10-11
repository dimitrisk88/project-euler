#include<stdio.h>
#include<time.h>
int notDevided(int a)
{
	int i;
	for(i=3;i<=20;i++)
	if(a%i)
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i;
	for(i=20;notDevided(i);i+=20);
	printf("%d\n",i);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

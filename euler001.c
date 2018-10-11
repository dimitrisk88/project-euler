#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,sum=0;
	for(i=0;i<1000;i++)
	if(i%3==0 || i%5==0)
	sum+=i;
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

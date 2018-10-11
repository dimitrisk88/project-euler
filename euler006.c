#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,sum1=0,sum2=0;
	for(i=1;i<=100;i++)
	{
		sum1+=i*i;
		sum2+=i;
	}
	sum2*=sum2;
	printf("%d\n",sum2-sum1);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

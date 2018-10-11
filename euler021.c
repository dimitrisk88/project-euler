#include<stdio.h>
#include<time.h>
int sumDivisors(int a)
{
	int b=a/2+1,i,sum=0;
	for(i=1;i<b;i++)
	if(!(a%i))
	sum+=i;
	return sum;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,sum=0,div;
	for(i=0;i<10000;i++)
	{
		div=sumDivisors(i);
		if(div>i && sumDivisors(div)==i)
		sum+=div+i;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

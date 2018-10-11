#include<stdio.h>
#include<time.h>
int isPrime(int a)
{
	int i;
	for(i=2;i<a;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i=1,j=0,sum,max=0,maxPrime,pin[552];
	for(i=0;i<4000;i++)
	if(isPrime(i))
	pin[j++]=i;
	for(i=0;i<552;i++)
	{
		sum=0;
		for(j=i;j<552 && sum<1000000;j++)
		{
			sum+=pin[j];
			if(j-i>max && sum<1000000 && isPrime(sum))
			{
				max=j-i;
				maxPrime=sum;
			}
		}
	}
	printf("%d\n",maxPrime);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

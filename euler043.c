#include<stdio.h>
#include<time.h>
#define A 10
#define B A-1
long long sum=0;
int isDivisible(int pin1[])
{
	static int pin2[8]={2,3,5,7,11,13,17};
	int i,j,temp;
	for(i=1;i<=7;i++)
	{
		temp=0;
		for(j=0;j<3;j++)
		temp=temp*10+pin1[i+j];
		if(temp%pin2[i-1])
		return 0;
	}
	return 1;
}
void perm(int pin[],int a)
{
	int i,j;
	for(i=0;i<A;i++)
	{
		for(j=0;j<a;j++)
		if(pin[j]==i)
		break;
		if(j!=a)
		continue;
		pin[a]=i;
		if(a<B)
		perm(pin,a+1);
		else if(isDivisible(pin))
		{
			long long temp=0;
			for(j=0;j<10;j++)
			temp=temp*10+pin[j];
			sum+=temp;
		}
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int pin[10];
	perm(pin,0);
	printf("%lld\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<math.h>
#include<time.h>
int nextPrime(int a)
{
	long long b,i,j;
	if(a==2)
	return 3;
	for(i=a+2;1;i+=2)
	{
		b=sqrt(i);
		for(j=3;j<=b;j++)
		if(i%j==0)
		break;
		if(j>b)
		return i;
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	long long a=600851475143,i;
	for(i=nextPrime(0);i<=a;i=nextPrime(i))
	{
		while(a%i==0)
		a/=i;
		if(a==1)
		printf("%d\n",i);
	}
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

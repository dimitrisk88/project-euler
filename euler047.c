#include<stdio.h>
#include<time.h>
#define PRIMES 130
int isPrime(int a)
{
	int i;
	for(i=2;i<a;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int power(int a,int b)
{
	int temp=1,i;
	for(i=0;i<b;i++)
	temp*=a;
	return temp;
}
int factors(int a,int b,int c,int d,int e)
{
	int i,j,k,l;
	for(i=1;i<4;i++)
	for(j=1;j<4;j++)
	for(k=1;k<4;k++)
	for(l=1;l<4;l++)
	if(a==power(b,i)*power(c,j)*power(d,k)*power(e,l))
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int counter,a=0,i=1,j,temp,primes[PRIMES];
	while(a<PRIMES)
	if(isPrime(++i))
	primes[a++]=i;
	for(a=644;a<1000000;a++)
	{
		counter=0;
		for(j=0;j<4;j++)
		{
			temp=a+j;
			for(i=0;i<PRIMES;i++)
			if(!(temp%primes[i]))
			{
				counter++;
				while(!(temp%primes[i]))
				temp/=primes[i];
			}
		}
		if(counter==16)
		break;
	}
	printf("%d\n",a);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

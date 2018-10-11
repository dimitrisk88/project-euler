#include<stdio.h>
#include<time.h>
#define PRIMES 1100
int isPrime(int a)
{
	int b=sqrt(a)+1,i;
	for(i=2;i<b;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int con(int a,int b)
{
	int c=b;
	while(c)
	{
		a*=10;
		c/=10;
	}
	return a+b;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,b,i,j,k,l,m,n,o,flag=1,primes[PRIMES];
	j=2;
	k=0;
	primes[PRIMES-1]=0;
	while(!primes[PRIMES-1])
	if(isPrime(++j))
	primes[k++]=j;
	for(i=0;i<PRIMES && flag;i++)
	for(j=i+1;j<PRIMES && flag;j++)
	{
		if(!isPrime(con(primes[i],primes[j])) || !isPrime(con(primes[j],primes[i])))
		continue;
		for(k=j+1;k<PRIMES && flag;k++)
		{
			if(!isPrime(con(primes[i],primes[k])) || !isPrime(con(primes[j],primes[k])) || !isPrime(con(primes[k],primes[i])) || !isPrime(con(primes[k],primes[j])))
			continue;
			for(l=k+1;l<PRIMES && flag;l++)
			{
				if(!isPrime(con(primes[i],primes[l])) || !isPrime(con(primes[j],primes[l])) || !isPrime(con(primes[k],primes[l])) || !isPrime(con(primes[l],primes[i])) || !isPrime(con(primes[l],primes[j])) || !isPrime(con(primes[l],primes[k])))
				continue;
				for(m=l+1;m<PRIMES && flag;m++)
				if(isPrime(con(primes[i],primes[m])) && isPrime(con(primes[j],primes[m])) && isPrime(con(primes[k],primes[m])) && isPrime(con(primes[l],primes[m])) && isPrime(con(primes[m],primes[i])) && isPrime(con(primes[m],primes[j])) && isPrime(con(primes[m],primes[k])) && isPrime(con(primes[m],primes[l])))
				flag=0;
			}
		}
	}
	printf("%d\n",primes[i-1]+primes[j-1]+primes[k-1]+primes[l-1]+primes[m-1]);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

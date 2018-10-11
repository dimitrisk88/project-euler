#include<stdio.h>
#include<time.h>
int notPrime(int a)
{
	int i;
	for(i=2;i<a;i++)
	if(!(a%i))
	return 1;
	return 0;
}
int isOddComposite(int a)
{
	int i;
	if(!(a%2))
	return 0;
	for(i=2;i<a;i++)
	if(!(a%i))
	return 1;
	return 0;
}
int check(int a)
{
	int i,j;
	for(i=2;i<5000;i++)
	{
		while(notPrime(i))
		i++;
		for(j=1;j<100;j++)
		if(i+2*j*j==a)
		return 0;
	}
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i;
	for(i=3;i<1000000;i++)
	if(isOddComposite(i) && check(i))
	break;
	printf("%d\n",i);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

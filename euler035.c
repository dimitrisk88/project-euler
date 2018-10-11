#include<stdio.h>
#include<time.h>
int notPrime(int a)
{
	int b=sqrt(a),i;
	for(i=2;i<=b;i++)
	if(!(a%i))
	return 1;
	return 0;
}
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int isCircular(int a)
{
	int b,i=0,temp=0;
	b=a;
	while(b)
	{
		b/=10;
		i++;
	}
	b=i-1;
	while(i--)
	{
		a=a%10*power(b)+a/10;
		if(notPrime(a))
		return 0;
	}
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,i,j,temp,count=0;
	for(i=2;i<1000000;i++)
	{
		count+=isCircular(i);
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

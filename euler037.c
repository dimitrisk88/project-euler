#include<stdio.h>
#include<time.h>
int notPrime(int a)
{
	int b=sqrt(a),i;
	if(a==1)
	return 1;
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
int isTruncatable(int a)
{
	int i=0;
	while(a/power(i))
	if(notPrime(a/power(i++)))
	return 0;
	while(i)
	if(notPrime(a%power(--i)))
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i=10,sum=0,count=0;
	while(count<11)
	if(isTruncatable(++i))
	{
		sum+=i;
		count++;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

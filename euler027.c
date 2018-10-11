#include<stdio.h>
#include<time.h>
int isPrime(int a)
{
	int i;
	if(a<=1)
	return 0;
	for(i=2;i<a;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int check(int a,int b)
{
	int i=0;
	while(isPrime(i*i+i*a+b))
	i++;
	if(i==1011)
	printf("%d %d\n",a,b);
	return i;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,product,max=0;
	for(i=-999;i<1000;i++)
	for(j=-999;j<1000;j++)
	if(check(i,j)>=max)
	{
		max=check(i,j);
		product=i*j;
	}
	printf("%d\n",product);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

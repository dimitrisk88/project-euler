#include<stdio.h>
#include<time.h>
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int phi(int a)
{
	int i,sum=0;
	for(i=1;i<a;i++)
	if(gcd(a,i)==1)
	sum++;
	return sum;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,n=1;
	float temp,max=0;
	for(i=2;i<=1000000;i+=n)
	{
		temp=phi(i);
		temp=((float)i)/temp;
		if(temp>max)
		{
			max=temp;
			n=i;
		}
	}
	printf("%d\n",n);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

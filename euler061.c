#include<stdio.h>
#include<time.h>
int isTriangle(int a)
{
	int i=44;
	while(++i*(i+1)/2<a);
	if(i*(i+1)/2==a)
	return i;
	return 0;
}
int isSquare(int a)
{
	int i=31;
	while(++i*i<a);
	if(i*i==a)
	return i;
	return 0;
}
int isPentagonal(int a)
{
	int i=26;
	while(++i*(3*i-1)/2<a);
	if(i*(3*i-1)/2==a)
	return i;
	return 0;
}
int isHexagonal(int a)
{
	int i=22;
	while(++i*(2*i-1)<a);
	if(i*(2*i-1)==a)
	return i;
	return 0;
}
int isHeptagonal(int a)
{
	int i=20;
	while(++i*(5*i-3)/2<a);
	if(i*(5*i-3)/2==a)
	return i;
	return 0;
}
int isOctagonal(int a)
{
	int i=18;
	while(++i*(3*i-2)<a);
	if(i*(3*i-2)==a)
	return i;
	return 0;
}
int anadromic(int next,int temp,int sum,int i)
{
	int a,b,j;
	for(j=10;j<100;j++)
	{
		next=next/100*100+j;
		if(isTriangle(next) || isSquare(next) || isPentagonal(next) || isHexagonal(next) || isHeptagonal(next) || isOctagonal(next))
		{
			a=temp;
			b=sum+next;
			if(isTriangle(next) && temp&1)
			temp-=1;
			else if(isSquare(next) && temp&2)
			temp-=2;
			else if(isPentagonal(next) && temp&4)
			temp-=4;
			else if(isHexagonal(next) && temp&8)
			temp-=8;
			else if(isHeptagonal(next) && temp&16)
			temp-=16;
			else if(isOctagonal(next) && temp&32)
			temp-=32;
			if(a==temp)
			continue;
			if(temp)
			sum=anadromic(next%100*100,temp,b,i);
			else if(next%100==i)
			return b;
			if(b!=sum)
			return sum;
			temp=a;
			sum-=next;
		}
	}
	return sum;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i=9,sum=0;
	while(!sum && ++i<100)
	sum=anadromic(i*100,63,0,i);
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

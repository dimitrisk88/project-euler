#include<stdio.h>
#include<time.h>
int isPrime(long long a)
{
	int i,b=sqrt(a)+1;
	for(i=2;i<=b;i++)
	if(a%i==0)
	return 0;
	return 1;
}
void perm(int pin1[],int pin2[],int a,int b)
{
	int i,j;
	long long temp;
	for(i=1;i<=b;i++)
	{
		for(j=0;j<a;j++)
		if(pin1[j]==i)
		break;
		if(j!=a)
		continue;
		pin1[a]=i;
		if(a<b-1)
		perm(pin1,pin2,a+1,b);
		else
		{
			for(j=0;j<7;j++)
			temp=0;
			for(j=0;j<b;j++)
			temp=temp*10+pin1[j];
			if(isPrime(temp))
			for(j=0;j<10;j++)
			pin2[j+1]=pin1[j];
			pin2[0]=b-1;
		}
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int pin1[10],pin2[11],i;
	for(i=1;i<10;i++)
	perm(pin1,pin2,0,i);
	for(i=1;i<pin2[0];i++)
	printf("%d",pin2[i]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

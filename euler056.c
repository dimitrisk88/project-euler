#include<stdio.h>
#include<time.h>
void power(int a,int b,char pin[])
{
	int temp,i,j;
	for(i=1;i<200;i++)
	pin[i]=0;
	pin[0]=1;
	for(i=0;i<b;i++)
	{
		temp=0;
		for(j=0;j<200;j++)
		{
			temp+=pin[j]*a;
			pin[j]=temp%10;
			temp/=10;
		}
	}
}
int add(char pin[])
{
	int i,sum=0;
	for(i=0;i<200;i++)
	sum+=pin[i];
	return sum;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,max=0;
	char pin[200];
	for(i=2;i<100;i++)
	for(j=5;j<100;j++)
	{
		power(i,j,pin);
		if(add(pin)>max)
		max=add(pin);
	}
	printf("%d\n",max);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

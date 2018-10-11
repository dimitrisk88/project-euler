#include<stdio.h>
#include<time.h>
#define SIZE 60
void add(char pin1[],char pin2[])
{
	int i,j;
	for(i=0;i<SIZE;i++)
	{
		pin1[i]+=pin2[i];
		j=i;
		while(pin1[j]>9)
		{
			pin1[j]-=10;
			pin1[++j]++;
		}
	}
}
void mul(char pin[],int a)
{
	int i,temp=0;
	for(i=0;i<SIZE;i++)
	{
		temp+=pin[i]*a;
		pin[i]=temp%10;
		temp/=10;
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=0,i,j;
	char num[SIZE],pre[SIZE],temp[SIZE];
	for(i=1;i<SIZE;i++)
	{
		num[i]=0;
		pre[i]=0;
	}
	num[0]=1;
	pre[0]=1;
	for(i=1;i<=100;i++)
	{
		for(j=0;j<SIZE;j++)
		temp[j]=num[j];
		if(!(i%3))
		{
			a+=2;
			mul(num,a);
		}
		add(num,pre);
		for(j=0;j<SIZE;j++)
		pre[j]=temp[j];
	}
	a=0;
	for(i=0;i<SIZE;i++)
	a+=num[i];
	printf("%d\n",a);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

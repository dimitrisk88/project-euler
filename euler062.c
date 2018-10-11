#include<stdio.h>
#include<time.h>
#define SIZE 20
void cube(char pin[],int a)
{
	int b=a,i=0,temp;
	while(b)
	{
		pin[i]=b%10;
		b/=10;
		i++;
	}
	while(i<SIZE)
	pin[i++]=0;
	for(b=0;b<2;b++)
	{
		temp=0;
		for(i=0;i<SIZE;i++)
		{
			temp+=pin[i]*a;
			pin[i]=temp%10;
			temp/=10;
		}
	}
}
int digits(char pin[])
{
	int i=SIZE;
	while(!pin[--i]);
	return i;
}
int isPermutation(char pin1[],char pin2[])
{
	int i,j,dig=digits(pin1);
	char pin3[SIZE];
	for(i=0;i<SIZE;i++)
	pin3[i]=pin2[i];
	for(i=0;i<=dig;i++)
	{
		for(j=0;j<=dig;j++)
		if(pin3[j]==pin1[i])
		{
			pin3[j]=-1;
			break;
		}
		if(j>dig)
		return 0;
	}
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,count;
	char pin1[SIZE],pin2[SIZE];
	for(i=0;i<10000000;i++)
	{
		cube(pin1,i);
		j=i+1;
		count=0;
		cube(pin2,j);
		while(digits(pin1)==digits(pin2))
		{
			if(isPermutation(pin1,pin2))
			count++;
			cube(pin2,++j);
		}
		if(count==4)
		break;
	}
	for(i=digits(pin1);i>=0;i--)
	printf("%d",pin1[i]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

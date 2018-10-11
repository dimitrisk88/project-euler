#include<stdio.h>
#include<time.h>
int digits(char pin[])
{
	int i=25;
	while(!pin[--i]);
	return i;
}
void power(int a,int b,char pin[])
{
	int i,j,temp;
	for(i=1;i<25;i++)
	pin[i]=0;
	pin[0]=1;
	for(i=0;i<b;i++)
	{
		temp=0;
		for(j=0;j<25;j++)
		{
			temp+=pin[j]*a;
			pin[j]=temp%10;
			temp/=10;
		}
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,count=0;
	char pin[25];
	for(i=0;i<10;i++)
	for(j=0;j<25;j++)
	{
		power(i,j,pin);
		if(digits(pin)+1==j)
		count++;
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
void iterate(char pin[])
{
	char temp[30];
	int a=30,i,j;
	while(!pin[--a]);
	for(i=0;i<=a;i++)
	temp[i]=pin[a-i];
	for(i=0;i<=a;i++)
	{
		pin[i]+=temp[i];
		j=i;
		while(pin[j]>9)
		{
			pin[j]-=10;
			pin[++j]++;
		}
	}
}
int isPalindrome(char pin[])
{
	int a=30,b,i;
	while(!pin[--a]);
	b=a/2;
	for(i=0;i<=b;i++)
	if(pin[i]!=pin[a-i])
	return 0;
	return 1;
}
void convert(char pin[],int a)
{
	int i=0;
	while(a)
	{
		pin[i++]=a%10;
		a/=10;
	}
	while(i<30)
	pin[i++]=0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,flag,count=0;
	char pin[30];
	for(i=10;i<10000;i++)
	{
		convert(pin,i);
		flag=1;
		for(j=0;j<50;j++)
		{
			iterate(pin);
			if(isPalindrome(pin))
			{
				flag=0;
				break;
			}
		}
		if(flag)
		count++;
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

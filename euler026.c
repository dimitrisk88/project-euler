#include<stdio.h>
#include<time.h>
int check(char pin[])
{
	int i;
	for(i=0;i<100;i++)
	if(pin[i])
	return 1;
	return 0;
}
int getInt(char pin[])
{
	int a=0,b=1,i;
	for(i=0;i<4;i++)
	{
		a+=pin[i]*b;
		b*=10;
	}
	return a;
}
int divide(int a)
{
	char pin[4];
	int b=-1,c,d,i,nums[1000];
	for(i=1;i<4;i++)
	pin[i]=0;
	pin[0]=1;
	do{
		while(getInt(pin)<a)
		{
			for(i=3;i>0;i--)
			pin[i]=pin[i-1];
			pin[0]=0;
			nums[++b]=getInt(pin);
			for(i=0;i<b;i++)
			if(nums[i]==nums[b])
			return b-i;
		}
		do{
			c=1;
			for(i=0;i<4;i++)
			{
				pin[i]-=a/c%10;
				c*=10;
				d=i;
				while(pin[d]<0)
				{
					pin[d]+=10;
					pin[++d]--;
				}
			}
		}while(getInt(pin)>=a);
	}while(check(pin));
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,max=0,maxi;
	for(i=1;i<1000;i++)
	if(divide(i)>max)
	{
		max=divide(i);
		maxi=i;
	}
	printf("%d\n",maxi);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

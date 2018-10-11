#include<stdio.h>
#include<time.h>
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int bits(int a)
{
	int i=0;
	while(a)
	{
		a/=10;
		i++;
	}
	return i;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int flag=0,temp,i=0,counter=0,res=1;
	while(counter<1000000)
	{
		counter++;
		if(!flag)
		{
			temp=bits(++i);
			flag=1;
		}
		temp--;
		if(counter==1 || counter==10 || counter==100 || counter==1000 || counter==10000 || counter==100000 || counter==1000000)
		res*=i/power(temp)%10;
		if(!temp)
		flag=0;
	}
	printf("%d\n",res);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,sum=0,temp,facs[10];
	for(i=9;i>=0;i--)
	{
		facs[i]=1;
		for(j=2;j<=i;j++)
		facs[i]*=j;
	}
	for(i=3;i<10000000;i++)
	{
		temp=i;
		j=0;
		while(temp)
		{
			j+=facs[temp%10];
			temp/=10;
		}
		if(j==i)
		sum+=i;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

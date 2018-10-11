#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,b,i,sum=0,temp;
	for(i=11;i<1000000;i++)
	{
		temp=i;
		b=0;
		while(temp)
		{
			a=temp%10;
			temp/=10;
			a*=a*a*a*a;
			b+=a;
		}
		if(b==i)
		sum+=i;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

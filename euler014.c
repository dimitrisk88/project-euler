#include<stdio.h>
#include<time.h>
int chain(long long n)
{
	int count=1;
	while(n!=1)
	{
		if(n%2)
		n=3*n+1;
		else
		n/=2;
		count++;
	}
	return count;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int n,i,max=0,res;
	for(i=1;i<1000000;i++)
	{
		n=chain(i);
		if(n>max)
		{
			max=n;
			res=i;
		}
	}
	printf("%d\n",res);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

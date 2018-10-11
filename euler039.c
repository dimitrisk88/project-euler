#include<stdio.h>
#include<time.h>
int solutions(int a)
{
	int i,j,k,sum=0;
	for(i=0;i<a;i++)
	for(j=i+1;j<a;j++)
	{
		k=a-i-j;
		if(i*i+j*j==k*k && k>j)
		sum++;
	}
	return sum;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,max=0,maxi;
	for(i=0;i<=1000;i++)
	if(solutions(i)>max)
	{
		max=solutions(i);
		maxi=i;
	}
	printf("%d\n",maxi);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

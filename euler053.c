#include<stdio.h>
#include<time.h>
int calc(int n,int r)
{
	int a=n-r,pin[a];
	double res=1;
	while(n>r)
	{
		res*=n--;
		while(a>1 && res>1000000)
		res/=a--;
		if(a==1 && res>1000000)
		return 1;
	}
	while(a>1)
	res/=a--;
	if(res>1000000)
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,sum=0;
	for(i=1;i<=100;i++)
	for(j=1;j<i;j++)
	if(calc(i,j))
	sum++;
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

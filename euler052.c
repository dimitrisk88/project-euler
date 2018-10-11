#include<stdio.h>
#include<time.h>
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int diffDigits(int a,int b)
{
	int c=0,i,j;
	char pin[10];
	while(a/power(c) && b/power(c))
	c++;
	if(a/power(c) || b/power(c))
	return 1;
	for(i=0;i<c;i++)
	pin[i]=b/power(i)%10;
	for(i=0;i<c;i++)
	{
		for(j=0;j<c;j++)
		if(a/power(i)%10==pin[j])
		{
			pin[j]=-1;
			break;
		}
		if(j==c)
		return 1;
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j;
	for(i=1;i<1000000;i++)
	{
		for(j=1;j<=6;j++)
		if(diffDigits(i,i*j))
		break;
		if(j==7)
		break;
	}
	printf("%d\n",i);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

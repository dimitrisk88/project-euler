#include<stdio.h>
#include<time.h>
#define A 10
#define B A-1
int count=0;
int perm(char pin[],int a)
{
	int i,j;
	for(i=0;i<A;i++)
	{
		for(j=0;j<a;j++)
		if(pin[j]==i)
		break;
		if(j!=a)
		continue;
		pin[a]=i;
		if(a<B)
		{
			if(perm(pin,a+1))
			return 1;
		}
		else if(++count==1000000)
		return 1;
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	char i,pin[A];
	perm(pin,0);
	for(i=0;i<A;i++)
	printf("%d",pin[i]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

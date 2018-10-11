#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=1,b=0,i,j;
	for(i=0;i<=100;i++)
	for(j=0;j<12;j++)
	{
		if(j==1)
		{
			if(!(i%4)&&i)
			a+=29;
			else
			a+=28;
		}
		else if(j<7&&!(j%2)||j>6&&j%2)
		a+=31;
		else
		a+=30;
		if(!(a%7) && i)
		b++;
	}
	printf("%d\n",b);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

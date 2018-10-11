#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=1,b=1,i,j;
	for(i=10;i<100;i++)
	for(j=10;j<i;j++)
	{
		if(i%10==0)
		break;
		else if(j%10==0)
		continue;
		else if(i/10==j/10 && (float)j/i==(float)(j%10)/(i%10) || i/10==j%10 && (float)j/i==(float)(j/10)/(i%10) || i%10==j/10 && (float)j/i==(float)(j%10)/(i/10) || i%10==j%10 && (float)j/i==(float)(j/10)/(i/10))
		{
			a*=j;
			b*=i;
		}
	}
	printf("%d\n",b/a);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

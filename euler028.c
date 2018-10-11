#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=2,i,j,temp=1,sum=1;
	for(i=0;i<500;i++)
	{
		for(j=0;j<4;j++)
		{
			temp+=a;
			sum+=temp;
		}
		a+=2;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

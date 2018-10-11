#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,i1=1,sum=0;
	for(i=2;i<4000000;i+=i1)
	{
		i1=i-i1;
		if(i%2==0)
		sum+=i;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

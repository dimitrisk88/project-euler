#include<stdio.h>
#include<time.h>
#define SIZE 23
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,kratoumeno=0,sum=0,pin[SIZE];
	for(i=0;i<SIZE;i++)
	pin[i]=0;
	pin[0]=1;
	for(i=2;i<100;i++)
	for(j=0;j<SIZE;j++)
	{
		pin[j]*=i;
		if(kratoumeno)
		{
			pin[j]+=kratoumeno;
			kratoumeno=0;
		}
		if(pin[j]>9999999)
		{
			kratoumeno=pin[j]/10000000;
			pin[j]-=kratoumeno*10000000;
		}
	}
	for(i=0;i<SIZE;i++)
	sum+=pin[i]%10+pin[i]/10%10+pin[i]/100%10+pin[i]/1000%10+pin[i]/10000%10+pin[i]/100000%10+pin[i]/1000000%10+pin[i]/10000000;
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

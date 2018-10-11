#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,i,j,k,kratoumeno;
	char temp[10],sum[10];
	for(i=0;i<10;i++)
	sum[i]=0;
	for(i=1;i<=1000;i++)
	{
		for(j=0;j<10;j++)
		temp[j]=0;
		temp[0]=i%10;
		temp[1]=i/10%10;
		temp[2]=i/100%10;
		temp[3]=i/1000;
		for(j=1;j<i;j++)
		{
			a=0;
			for(k=0;k<10;k++)
			{
				a+=temp[k]*i;
				temp[k]=a%10;
				a/=10;
			}
		}
		kratoumeno=0;
		for(j=0;j<10;j++)
		{
			sum[j]+=temp[j]+kratoumeno;
			kratoumeno=0;
			if(sum[j]>9)
			{
				sum[j]-=10;
				kratoumeno=1;
			}
		}
	}
	for(i=9;i>=0;i--)
	printf("%d",sum[i]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

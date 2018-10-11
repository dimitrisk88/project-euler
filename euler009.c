#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,k;
	for(i=0;i<1000;i++)
	for(j=i+1;j<1000;j++)
	for(k=j+1;k<1000;k++)
	if(i*i+j*j==k*k && i+j+k==1000)
	{
		printf("%d\n",i*j*k);
    	printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
		getch();
		exit(0);
	}
}

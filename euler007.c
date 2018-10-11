#include<stdio.h>
#include<math.h>
#include<time.h>
int nextPrime(int a)
{
	int b,i,j;
	if(a==2)
	return 3;
	for(i=a+2;1;i+=2)
	{
		b=sqrt(i);
		for(j=3;j<=b;j++)
		if(i%j==0)
		break;
		if(j>b)
		return i;
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j=0;
	for(i=0;i<10001;i++)
	j=nextPrime(j);
	printf("%d\n",j);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

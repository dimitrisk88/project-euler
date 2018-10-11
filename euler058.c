#include<stdio.h>
#include<time.h>
int isPrime(int a)
{
	int b=sqrt(a)+1,i;
	for(i=2;i<b;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=0,b=0,temp=1,i,j=2;
	do{
		for(i=0;i<4;i++)
		{
			temp+=j;
			if(isPrime(temp))
			a++;
			b++;
		}
		j+=2;
	}while((float)a/b>=0.1);
	printf("%d\n",j-1);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

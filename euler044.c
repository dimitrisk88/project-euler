#include<stdio.h>
#include<time.h>
int pentagonal(int a)
{
	return a*(3*a-1)/2;
}
isPentagonal(int a)
{
	int i=0;
	while(pentagonal(++i)<a);
	if(pentagonal(i)==a)
	return 1;
	return 0;
}
int main()
{
	int i,j;
	double time=(double)clock()/CLOCKS_PER_SEC;
	for(i=1000;i<3000;i++)
	{
		for(j=i+1;j<3000;j++)
		if(isPentagonal(pentagonal(j)-pentagonal(i)) && isPentagonal(pentagonal(j)+pentagonal(i)))
		break;
		if(isPentagonal(pentagonal(j)-pentagonal(i)) && isPentagonal(pentagonal(j)+pentagonal(i)))
		break;
	}
	printf("%d\n",pentagonal(j)-pentagonal(i));
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

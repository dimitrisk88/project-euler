#include<stdio.h>
#include<time.h>
int check(int a)
{
	int i,count=0;
	for(i=1;a%i || a/i>a/(a/i);i++)
	if(a%i==0)
	count++;
	count*=2;
	if(a/i==a/(a/i))
	count++;
	if(count>500)
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,triangle=1;
	check(10);
	check(36);
	for(i=2;check(triangle);i++)
	triangle+=i;
	printf("%d\n",triangle);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

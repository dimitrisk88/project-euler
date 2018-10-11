#include<stdio.h>
#include<time.h>
int isPalindrome(int a)
{
	char b[7];
	int c,i=0;
	for(c=1;a/c>0;c*=10)
	b[i++]=a/c%10;
	b[i]=0;
	for(c=0;c<i-c-1;c++)
	if(b[c]!=b[i-c-1])
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,max=0;
	for(i=100;i<1000;i++)
	for(j=i;j<1000;j++)
	if(isPalindrome(i*j))
	if(i*j>max)
	max=i*j;
	printf("%d\n",max);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

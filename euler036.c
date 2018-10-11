#include<stdio.h>
#include<time.h>
isPalindromic(char pin[],int a)
{
	int i=0;
	while(!pin[a])
	a--;
	while(i<a)
	if(pin[i++]!=pin[a--])
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,i,sum=0;
	char dec[6],bin[20];
	for(i=0;i<20;i++)
	{
		if(i<6)
		dec[i]=0;
		bin[i]=0;
	}
	for(i=0;i<1000000;i++)
	{
		a=0;
		dec[a]++;
		bin[a]++;
		while(dec[a]>9)
		{
			dec[a]=0;
			dec[++a]++;
		}
		a=0;
		while(bin[a]>1)
		{
			bin[a]=0;
			bin[++a]++;
		}
		if(isPalindromic(dec,5) && isPalindromic(bin,19))
		sum+=i+1;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

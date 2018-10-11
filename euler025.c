#include<stdio.h>
#include<time.h>
void add(char a[],char b[])
{
	int i,kratoumeno=0;
	for(i=0;i<1000;i++)
	{
		a[i]+=b[i]+kratoumeno;
		kratoumeno=0;
		if(a[i]>9)
		{
			kratoumeno=1;
			a[i]-=10;
		}
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	char pin1[1000],pin2[1000];
	int i;
	for(i=0;i<1000;i++)
	{
		pin1[i]=0;
		pin2[i]=0;
	}
	pin1[0]=1;
	pin2[0]=1;
	i=2;
	do{
		if(i%2)
		add(pin1,pin2);
		else
		add(pin2,pin1);
		i++;
	}while(!pin1[999] && !pin2[999]);
	printf("%d\n",i);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

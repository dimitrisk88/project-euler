#include<stdio.h>
#include<time.h>
void add(char pin1[],char pin2[])
{
	int a,i;
	for(i=0;i<500;i++)
	{
		pin1[i]+=pin2[i];
		a=i;
		while(pin1[a]>9)
		{
			pin1[a]-=10;
			pin1[++a]++;
		}
	}
}
int compare(char pin1[],char pin2[])
{
	int i=500;
	while(!pin1[--i] && !pin2[i]);
	if(!pin1[i] || !pin2[i])
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,count=0;
	char pin1[500],pin2[500];
	for(i=1;i<500;i++)
	{
		pin1[i]=0;
		pin2[i]=0;
	}
	pin1[0]=3;
	pin2[0]=2;
	for(i=1;i<1000;i++)
	{
		if(i%2)
		{
			add(pin1,pin2);
			add(pin2,pin1);
		}
		else
		{
			add(pin2,pin1);
			add(pin1,pin2);
		}
		if(compare(pin1,pin2))
		count++;
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

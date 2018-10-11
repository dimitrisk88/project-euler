#include<stdio.h>
#include<time.h>
int check(char pin[10000][200],char temp[200],int count)
{
	int i,j;
	for(i=0;i<count;i++)
	{
		j=0;
		while(pin[i][j]==temp[j++] && j<200);
		if(j==200 && pin[i][199]==temp[199])
		return count;
	}
	for(j=0;j<200;j++)
	pin[i][j]=temp[j];
	return count+1;
}
void power(int a,int b,char pin[])
{
	int i,j,temp=0;
	pin[0]=a%10;
	pin[1]=a/10%10;
	pin[2]=a/100;
	for(i=3;i<200;i++)
	pin[i]=0;
	for(i=1;i<b;i++)
	for(j=0;j<200;j++)
	{
		temp+=pin[j]*a;
		pin[j]=temp%10;
		temp/=10;
	}
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,b,i,count=0;
	char pin[10000][200],temp[200];
	for(a=2;a<=100;a++)
	for(b=2;b<=100;b++)
	{
		power(a,b,temp);
		count=check(pin,temp,count);
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

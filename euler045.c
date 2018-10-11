#include<stdio.h>
#include<time.h>
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
void polygonal(int a,char pin[],int b,int c,int d)
{
	int i,kratoumeno=0,temp=0;
	for(i=0;i<10;i++)
	pin[i]=a/power(i)%10;
	for(i=0;i<10;i++)
	{
		pin[i]*=b;
		pin[i]+=kratoumeno;
		kratoumeno=0;
		if(pin[i]>9)
		{
			kratoumeno=pin[i]/10;
			pin[i]%=10;
		}
	}
	pin[0]+=c;
	i=0;
	while(pin[i]>9)
	{
		pin[i]-=10;
		pin[++i]++;
	}
	while(pin[i]<0)
	{
		pin[i]+=10;
		pin[++i]--;
	}
	for(i=0;i<10;i++)
	{
		temp+=pin[i]*a;
		pin[i]=temp%10;
		temp/=10;
	}
	temp=0;
	kratoumeno=0;
	if(d)
	for(i=9;i>=0;i--)
	{
		if(temp)
		{
			kratoumeno=5;
			temp=0;
		}
		if(pin[i]%2)
		temp=1;
		pin[i]/=2;
		pin[i]+=kratoumeno;
		kratoumeno=0;
	}
}
int check(char pina[],char pinb[])
{
	int i=9;
	while(pina[i]==pinb[i] && i)
	i--;
	if(pina[i]>pinb[i])
	return 1;
	else if(pina[i]<pinb[i])
	return -1;
	else
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a=286,b=1,c=1,i;
	char pina[10],pinb[10],pinc[10];
	do{
		polygonal(a,pina,1,1,1);
		polygonal(b,pinb,3,-1,1);
		polygonal(c,pinc,2,-1,0);
		if(check(pina,pinb)<0 || check(pina,pinc)<0)
		a++;
		else if(check(pinb,pina)<0 || check(pinb,pinc)<0)
		b++;
		else if(check(pinc,pina)<0 || check(pinc,pinb)<0)
		c++;
	}while(check(pina,pinb) || check(pina,pinc));
	for(a=9;a>=0;a--)
	printf("%d",pinb[a]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

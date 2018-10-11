#include<stdio.h>
#include<time.h>
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int digits(int a)
{
	int i=0;
	while(a)
	{
		i++;
		a/=10;
	}
	return i;
}
void pandigital(int a,int b,int pin[])
{
	int flag,i=0,j,temp,pro;
	pro=a*b;
	i+=digits(a);
	i+=digits(b);
	i+=digits(pro);
	if(i!=9)
	return;
	i=digits(b);
	a*=power(i);
	a+=b;
	i=digits(pro);
	a*=power(i);
	a+=pro;
	for(i=1;i<10;i++)
	{
		flag=1;
		for(j=0;j<9;j++)
		if(a/power(j)%10==i)
		flag=0;
		if(flag)
		break;
	}
	j=-1;
	if(i==10)
	{
		while(pin[++j] && pin[j]!=pro);
		if(!pin[j])
		pin[j]=pro;
	}
		
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,j,pin[1000];
	for(i=0;i<1000;i++)
	pin[i]=0;
	for(i=2;i<2000;i++)
	for(j=2;j<2000;j++)
	pandigital(i,j,pin);
	i=0;
	j=0;
	while(pin[i])
	j+=pin[i++];
	printf("%d\n",j);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

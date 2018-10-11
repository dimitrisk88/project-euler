#include<stdio.h>
#include<time.h>
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int pandigital(int a)
{
	int flag,b,c=0,i=1,j,temp;
	while(c>=0 && c<1000000000)
	{
		b=a*i++;
		j=0;
		temp=b;
		while(temp)
		{
			j++;
			temp/=10;
		}
		c*=power(j);
		c+=b;
		for(j=1;j<10;j++)
		{
			flag=1;
			for(temp=0;temp<9;temp++)
			if(c/power(temp)%10==j)
			flag=0;
			if(flag)
			break;
		}
		if(c>987654321)
		return 0;
		if(j==10)
		return c;
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,max=0;
	for(i=1;i<10000;i++)
	if(pandigital(i)>max)
	max=pandigital(i);
	printf("%d\n",max);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

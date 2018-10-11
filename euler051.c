#include<stdio.h>
#include<time.h>
int isPrime(int a)
{
	int b=sqrt(a)+1,i;
	for(i=2;i<b;i++)
	if(!(a%i))
	return 0;
	return 1;
}
int power(int a)
{
	int b=1,i;
	for(i=0;i<a;i++)
	b*=10;
	return b;
}
int check(int a)
{
	int b,i,j,k,m,digits=0,temp=a/10,count;
	while(temp)
	{
		digits++;
		temp/=10;
	}
	for(i=0;i<digits;i++)
	for(j=0;j<digits;j++)
	for(k=0;k<digits;k++)
	{
		b=1;
		if(i && i<j && j<k || !i && j && j<k || !i && !j && k || !i && !j && !k)
		while(a/power(b+k))
		{
			if(a/power(b+i)%10==a/power(b+j)%10 && a/power(b+i)%10==a/power(b+k)%10 && a/power(b+i)%10<3)
			{
				temp=a;
				count=0;
				for(m=a/power(b+i)%10;m<10;m++)
				{
					if(isPrime(temp))
					count++;
					temp+=power(b+i);
					if(j)
					temp+=power(b+j);
					if(k)
					temp+=power(b+k);
				}
				if(count==8)
				return 1;
			}
			b++;
		}
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i;
	for(i=11;i<10000000;i+=2)
	if(check(i))
	break;
	printf("%d\n",i);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

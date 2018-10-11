#include<stdio.h>
#include<time.h>
int notPrime(int a)
{
	int b=sqrt(a)+1,i;
	for(i=2;i<b;i++)
	if(!(a%i))
	return 1;
	return 0;
}
int notPermutation(int a,int b)
{
	int i,j,flag;
	char pin1[4],pin2[4];
	for(i=0;i<4;i++)
	{
		pin1[i]=a%10;
		pin2[i]=b%10;
		a/=10;
		b/=10;
	}
	for(i=0;i<4;i++)
	{
		flag=1;
		for(j=0;j<4;j++)
		if(pin1[i]==pin2[j])
		{
			pin2[j]=-1;
			flag=0;
			break;
		}
		if(flag)
		break;
	}
	if(i==4)
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int flag,a,i=1487,j;
	do{
		i+=2;
		for(j=1;j<4500;j++)
		{
			if(i+2*j>9999)
			break;
			flag=1;
			for(a=0;a<3;a++)
			if(notPrime(i+j*a))
			{
				flag=0;
				break;
			}
			for(a=1;a<3;a++)
			if(notPermutation(i,i+a*j))
			{
				flag=0;
				break;
			}
			if(flag)
			{
				break;
			}
		}
	}while(!flag);
	for(a=0;a<3;a++)
	printf("%d",i+j*a);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
#define PIN 80
int notSquare(int a)
{
	int i=0;
	while(++i*i<a);
	if(i*i==a)
	return 0;
	return 1;
}
void square(char pin[])
{
	int a,i,j,k;
	char temp[PIN];
	for(i=0;i<PIN;i++)
	{
		temp[i]=pin[i];
		pin[i]=0;
	}
	for(i=0;i<PIN/2;i++)
	{
		a=0;	
		for(j=0;j<PIN/2;j++)
		{
			a+=temp[i]*temp[j];
			pin[j+i]+=a%10;
			a/=10;
			k=j+i;
			while(pin[k]>9)
			{
				pin[k]-=10;
				pin[++k]++;
			}
		}
	}	
}
void mul(char pin[],int a)
{
	int i,temp=0;
	for(i=0;i<PIN;i++)
	{
		temp+=pin[i]*a;
		pin[i]=temp%10;
		temp/=10;
	}
}
int check(char pin1[],char pin2[])
{
	int i,kratoumeno=0;
	char temp[PIN];
	for(i=0;i<PIN;i++)
	{
		temp[i]=pin1[i]-pin2[i]-kratoumeno;
		kratoumeno=0;
		if(temp[i]<0)
		{
			temp[i]+=10;
			kratoumeno=1;
		}
	}
	if(temp[0]!=1)
	return 0;
	for(i=1;i<PIN;i++)
	if(temp[i])
	return 0;
	return 1;
}
void init(char pin1[],char pin2[],int a)
{
	int i;
	for(i=1;i<PIN;i++)
	{
		pin1[i]=0;
		pin2[i]=0;
	}
	pin1[0]=1;
	i=0;
	while(a)
	{
		pin2[i++]=a%10;
		a/=10;
	}
}
void mulAdd(char pin1[],char pin2[],int a)
{
	int i,j,temp=0;
	char pin[PIN];
	for(i=0;i<PIN;i++)
	{
		temp+=pin2[i]*a;
		pin[i]=temp%10;
		temp/=10;
	}
	for(i=0;i<PIN;i++)
	{
		pin1[i]+=pin[i];
		j=i;
		while(pin1[j]>9)
		{
			pin1[j]-=10;
			pin1[++j]++;
		}
	}				
}
int isGreater(char pin1[],char pin2[])
{
	int i=PIN;
	while(pin1[--i]==pin2[i]);
	if(pin1[i]>pin2[i])
	{
		for(i=0;i<PIN;i++)
		pin2[i]=pin1[i];
		return 1;
	}
	return 0;	
}					
int x(int a,int b,char max[])
{
	int c=b,d=1,i,ptr=1,pin[1000];
	char pin1[PIN],pin2[PIN];
	pin[0]=b;
	do{
		d=(a-c*c)/d;
		pin[ptr]=0;
		while((c-d*(pin[ptr]+1))*(-1)<=b)
		pin[ptr]++;
		c-=d*pin[ptr];
		c=-c;
		if(ptr%2)
		init(pin1,pin2,pin[ptr]);
		else
		init(pin2,pin1,pin[ptr]);
		for(i=ptr++-1;i>=0;i--)
		if(i%2)
		mulAdd(pin2,pin1,pin[i]);
		else
		mulAdd(pin1,pin2,pin[i]);
		square(pin1);
		square(pin2);
		mul(pin2,a);
	}while(!check(pin1,pin2));
	if(isGreater(pin1,max))
	return 1;
	return 0;
}
int root(int a)
{
	int i=0;
	while(++i*i<a);
	if(i*i==a)
	return 0;
	return i-1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,i,maxi;
	char max[PIN];
	for(i=0;i<PIN;i++)
	max[i]=0;
	for(i=2;i<1000;i++)
	if(root(i) && x(i,root(i),max))
	maxi=i;
	printf("%d\n",maxi);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

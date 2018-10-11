#include<stdio.h>
#include<time.h>
int odd(int a,int b)
{
	int c=b,d=1,e,f,count=0;
	do{
		d=(a-c*c)/d;
		e=0;
		while((c-d*(e+1))*(-1)<=b)
		e++;
		c-=d*e;
		c=-c;
		count++;
	}while(e!=2*b);
	return count%2;
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
	int a,i,count=0;
	for(i=2;i<10000;i++)
	{	
		a=root(i);
		if(!a)
		continue;
		if(odd(i,a))
		count++;
	}
	printf("%d\n",count);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

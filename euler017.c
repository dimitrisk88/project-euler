#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int a,i,sum=11,h,d,u;
	for(i=1;i<1000;i++)
	{
		h=i/100;
		d=i/10%10;
		u=i%10;
		if(d==1)
		{
			a=i%100;
			if(a==10)
			sum+=3;
			else if(a==17)
			sum+=9;
			else if(a==11 || a==12)
			sum+=6;
			else if(a==15 || a==16)
			sum+=7;
			else
			sum+=8;
		}
		else
		{
			if(d==7)
			sum+=7;
			else if(d==4 || d==5 || d==6)
			sum+=5;
			else if(d)
			sum+=6;
			if(u==1 || u==2 || u==6)
			sum+=3;
			else if(u==3 || u==7 || u==8)
			sum+=5;
			else if(u)
			sum+=4;
		}
		if(h==1 || h==2 || h==6)
		sum+=13;
		else if(h==3 || h==7 || h==8)
		sum+=15;
		else if(h)
		sum+=14;
		if(h && !d && !u)
		sum-=3;
	}
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

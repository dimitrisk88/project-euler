#include<stdio.h>
#include<time.h>
void read(int pin[][100])
{
	FILE*triangle=fopen("triangle.txt","r");
	int a=10,i=0,j=0,temp;
	do{
		temp=getc(triangle);
		if(temp==32)
		{
			j++;
			a=10;
			pin[i][j]=0;
		}
		else if(temp==10)
		{
			j=0;
			i++;
			a=10;
			pin[i][j]=0;
		}
		else
		{
			pin[i][j]+=(temp-48)*a;
			a=1;
		}
	}while(temp!=EOF);
}
int maxSum(int pin[][100])
{
	int a,b,c,d,i,j,sum,max=6800,temp;
	for(i=99;i>0;i--)
	for(j=0;j<i;j++)
	{
		if(pin[i][j]>pin[i][j+1])
		pin[i-1][j]+=pin[i][j];
		else
		pin[i-1][j]+=pin[i][j+1];
	}
	return pin[0][0];
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int pin[100][100],i,j;
	read(pin);
	printf("%d\n",maxSum(pin));
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}
 

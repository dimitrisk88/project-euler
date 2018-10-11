#include<stdio.h>
#include<time.h>
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	FILE*file=fopen("13.txt","r");
	char a[100][50],b[52];
	int i,j,sum;
	for(i=0;i<52;i++)
	b[i]=0;
	for(i=0;i<100;i++)
	for(j=0;j<51;j++)
	a[i][j]=fgetc(file);
	fclose(file);
	for(j=49;j>=0;j--)
	{
		sum=0;
		for(i=0;i<100;i++)
		sum+=a[i][j]-48;
		b[j+2]+=sum%10;
		b[j+1]+=sum/10%10;
		b[j]+=sum/100;
	}
	for(i=51;i>0;i--)
	if(b[i]>9)
	{
		b[i-1]+=b[i]/10;
		b[i]%=10;
	}
	for(i=0;i<10;i++)
	printf("%d",b[i]);
	printf("\n");
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
int different(char*a,int b,int c)
{
	int i,j;
	for(i=b;i<c;i++)
	for(j=i+1;j<c;j++)
	if(a[i]==a[j])
	return 0;
	return 1;
}
int isMagic(char*a)
{
	int b=a[4]+a[5]+a[9],i;
	for(i=0;i<4;i++)
	if(b!=a[i]+a[i+5]+a[i+6])
	return 0;
	return 1;
}
void toString(char*a,char*b)
{
	int i,j=0;
	for(i=0;i<5;i++)
	{
		b[j++]=a[i]+48;
		b[j++]=a[i+5]+48;
		if(i<4)
		b[j++]=a[i+6]+48;
	}
	b[j++]=a[5]+48;
	b[16]=0;
	do
	{
		b[j]=b[j-1];
		j--;
	}while(b[j-1]!=58);
	b[j-1]=49;
	b[j]=48;
}
int greater(char*a,char*b)
{
	int i;
	for(i=0;i<16;i++)
	if(a[i]!=b[i])
	break;
	if(a[i]>b[i])
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	char i[10],pin[17],max[17];
	for(i[0]=0;i[0]<16;i[0]++)
	max[i[0]]=0;
	i[0]=6;
	for(i[1]=7;i[1]<11;i[1]++)
	for(i[2]=7;i[2]<11;i[2]++)
	for(i[3]=7;i[3]<11;i[3]++)
	for(i[4]=7;i[4]<11;i[4]++)
	if(different(i,1,5))
	for(i[5]=1;i[5]<6;i[5]++)
	for(i[6]=1;i[6]<6;i[6]++)
	for(i[7]=1;i[7]<6;i[7]++)
	for(i[8]=1;i[8]<6;i[8]++)
	for(i[9]=1;i[9]<6;i[9]++)
	if(different(i,5,10))
	if(isMagic(i))
	{
		toString(i,pin);
		if(greater(pin,max))
		toString(i,max);
	}
	puts(max);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

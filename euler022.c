#include<stdio.h>
#include<time.h>
#define S 46451
int check(char*a,char*b)
{
	int i=0;
	while(a[i]==b[i] && (b[i]!=0 || a[i]!=0))
	i++;
	if(a[i]==0 && b[i]==0)
	return 0;
	else if(a[i]<b[i] || a[i]==0)
	return -1;
	else return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	FILE*names=fopen("names.txt","r");
	int a,i,j,name=0,sum1=0,sum2;
	char pin[S],name1[30]="",name2[30],name3[30];
	fread(pin,S,1,names);
	fclose(names);
	for(j=0;j<5163;j++)
	{
		for(i=0;i<30;i++)
		name3[i]='Z';
		for(i=0;i<S;i++)
		{
			if(!name)
			{
				if(pin[i]<65)
				continue;
				else if(pin[i]>64 || i==46446)
				{
					name=1;
					if(check(name2,name1)>0 && check(name2,name3)<0)
					do{
						name3[a]=name2[a];
					}while(name2[a++]!=0);
					a=0;
				}
			}
			if(name)
			{
				if(pin[i]>64)
				name2[a++]=pin[i];
				else
				{
					name2[a]=0;
					name=0;
					a=0;
				}
			}
		}
		sum2=0;
		do{
			name1[a]=name3[a];
			if(name1[a]!=0)
			sum2+=name1[a]-64;
		}while(name3[a++]!=0);
		sum2*=j+1;
		sum1+=sum2;
	}
	printf("%d\n",sum1);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
int triangle(int a)
{
	return a*(a+1)/2;
}
int isTriangle(int a)
{
	int i=0;
	while(triangle(++i)<a);
	if(triangle(i)==a)
	return 1;
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	FILE*words=fopen("words.txt","r");
	int i,word=0,triangle=0,sum;
	char pin[16345];
	fread(pin,16345,1,words);
	for(i=0;i<16345;i++)
	{
		if(!word)
		{
			if(pin[i]<65)
			continue;
			else if(pin[i]>64 || i==16345)
			{
				word=1;
				if(isTriangle(sum))
				triangle++;
				sum=0;
			}
		}
		if(word)
		{
			if(pin[i]>64)
			sum+=pin[i]-64;
			else
			word=0;
		}
	}
	printf("%d\n",triangle);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
int nextWord(char wor[],char word[])
{
	static int i=1;
	int j=0;
	while(wor[i]>64)
	word[j++]=wor[i++];
	word[j]=0;
	i+=3;
	if(i>16345)
	{
		i=1;
		return 0;
	}
	return 1;
}
int chars(char word[])
{
	int i=0;
	while(word[++i]);
	return i;
}
int searchWord(char word[],char test[])
{
	int a=chars(word),b=1201-a,i,j;
	for(i=0;i<b;i++)
	if(word[0]+32==test[i] || word[0]==test[i])
	{
		j=1;
		while((word[j]+32==test[i+j] || word[j]==test[i+j]) && ++j<a);
		if((word[j-1]+32==test[i+j-1] || word[j-1]==test[i+j-1]) && j==a)
		return 1;
	}
	return 0;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	FILE*cipher=fopen("cipher1.txt","r"),*words=fopen("words.txt","r");
	char key[3]={'a','a','a'},cip[1201],test[1201],wor[16345],word[15],temp;
	int i,j=0,sum=0;
	fread(wor,16345,1,words);
	fclose(words);
	for(i=0;i<1201;i++)
	cip[i]=0;
	for(i=0;i<3202;i++)
	{
		fread(&temp,1,1,cipher);
		if(temp==',')
		j++;
		else
		{
			cip[j]*=10;
			cip[j]+=(temp-48);
		}
	}
	fclose(cipher);
	do{
		i=0;
		key[i]++;
		while(key[i]>122)
		{
			key[i]=97;
			key[++i]++;
		}
		for(i=0;i<1201;i++)
		test[i]=cip[i]^key[i%3];
		while(nextWord(wor,word))
		{
			if(chars(word)<6)
			continue;
			if(searchWord(word,test))
			{
				j=0;
				break;
			}
		}
	}while((key[0]!=122 || key[1]!=122 || key [2]!=122) && j);
	for(i=0;i<1201;i++)
	sum+=test[i];
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

#include<stdio.h>
#include<time.h>
int rank(char pin[])
{
	int i,j,straight=0,flush=0;
	char cards[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	for(i=0;i<15;i+=3)
	for(j=0;j<13;j++)
	if(pin[i]==cards[j])
	cards[j]=0;
	i=0;
	j=4;
	while(cards[i++] && i<13);
	while(!cards[i++] && j && i<13)
	j--;
	if(!j)
	straight=1;
	for(i=1;i<12;i+=3)
	if(pin[i]!=pin[i+3])
	break;
	if(i==13)
	flush=1;
	if(straight && flush)
	{
		for(i=0;i<15;i+=3)
		if(pin[i]=='A')
		return 9;
		return 8;
	}
	if(pin[0]==pin[3]&&pin[0]==pin[6]&&pin[0]==pin[9] || pin[0]==pin[3]&&pin[0]==pin[6]&&pin[0]==pin[12] || pin[0]==pin[3]&&pin[0]==pin[9]&&pin[0]==pin[12] || pin[0]==pin[6]&&pin[0]==pin[9]&&pin[0]==pin[12] || pin[3]==pin[6]&&pin[3]==pin[9]&&pin[3]==pin[12])
	return 7;
	if(pin[0]==pin[3]&&pin[6]==pin[9]&&pin[9]==pin[12] || pin[0]==pin[6]&&pin[3]==pin[9]&&pin[9]==pin[12] || pin[0]==pin[9]&&pin[3]==pin[6]&&pin[6]==pin[12] || pin[0]==pin[12]&&pin[3]==pin[6]&&pin[6]==pin[9] || pin[3]==pin[6]&&pin[0]==pin[9]&&pin[9]==pin[12] || pin[3]==pin[9]&&pin[0]==pin[6]&&pin[6]==pin[12] || pin[3]==pin[12]&&pin[0]==pin[6]&&pin[6]==pin[9] || pin[6]==pin[9]&&pin[0]==pin[3]&&pin[3]==pin[12] || pin[6]==pin[12]&&pin[0]==pin[3]&&pin[3]==pin[9] || pin[9]==pin[12]&&pin[0]==pin[3]&&pin[3]==pin[6])
	return 6;
	if(flush)
	return 5;
	if(straight)
	return 4;
	if(pin[0]==pin[3]&&pin[3]==pin[6] || pin[0]==pin[3]&&pin[3]==pin[9] || pin[0]==pin[3]&&pin[3]==pin[12] || pin[0]==pin[6]&&pin[6]==pin[9] || pin[0]==pin[6]&&pin[6]==pin[12] || pin[0]==pin[9]&&pin[9]==pin[12] || pin[3]==pin[6]&&pin[6]==pin[9] || pin[3]==pin[6]&&pin[6]==pin[12] || pin[3]==pin[9]&&pin[9]==pin[12] || pin[6]==pin[9]&&pin[9]==pin[12])
	return 3;
	if(pin[0]==pin[3]&&(pin[6]==pin[9]||pin[6]==pin[12]||pin[9]==pin[12]) || pin[0]==pin[6]&&(pin[3]==pin[9]||pin[3]==pin[12]||pin[9]==pin[12]) || pin[0]==pin[9]&&(pin[3]==pin[6]||pin[3]==pin[12]||pin[6]==pin[12]) || pin[0]==pin[12]&&(pin[3]==pin[6]||pin[3]==pin[9]||pin[6]==pin[9]) || pin[3]==pin[6]&&(pin[0]==pin[9]||pin[0]==pin[12]||pin[9]==pin[12]) || pin[3]==pin[9]&&(pin[0]==pin[6]||pin[0]==pin[12]||pin[6]==pin[12]) || pin[3]==pin[12]&&(pin[0]==pin[6]||pin[0]==pin[9]||pin[6]==pin[9]) || pin[6]==pin[9]&&(pin[0]==pin[3]||pin[0]==pin[12]||pin[3]==pin[12]) || pin[6]==pin[12]&&(pin[0]==pin[3]||pin[0]==pin[9]||pin[3]==pin[9]) || pin[9]==pin[12]&&(pin[0]==pin[3]||pin[0]==pin[6]||pin[3]==pin[6]))
	return 2;
	if(pin[0]==pin[3] || pin[0]==pin[6] || pin[0]==pin[9] || pin[0]==pin[12] || pin[3]==pin[6] || pin[3]==pin[9] || pin[3]==pin[12] || pin[6]==pin[9] || pin[6]==pin[12] || pin[9]==pin[12])
	return 1;
	return 0;
}
int higher(char pin1[],char pin2[])
{
	char cards[13]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	int i,j,k,temp=13,max1=0,max2=0;
	if(rank(pin1)==1 || rank(pin1)==3 || rank(pin1)==7)
	for(i=0;i<15;i+=3)
	for(j=i+3;j<15;j+=3)
	{
		if(pin1[i]==pin1[j])
		max1=pin1[i];
		if(pin2[i]==pin2[j])
		max2=pin2[i];
	}
	else if(rank(pin1)==2)
	for(i=0;i<15;i+=3)
	for(j=i+3;j<15;j+=3)
	{
		if(pin1[i]==pin1[j] && max1<pin1[i])
		max1=pin1[i];
		if(pin2[i]==pin2[j] && max2<pin2[i])
		max2=pin2[i];
	}
	else if(rank(pin1)==6)
	for(i=0;i<15;i+=3)
	for(j=i+3;j<15;j+=3)
	for(k=j+3;k<15;k+=3)
	{
		if(pin1[i]==pin1[j] && pin1[i]==pin1[k])
		max1=pin1[i];
		if(pin2[i]==pin2[j] && pin2[i]==pin2[k])
		max2=pin2[i];
	}
	for(i=0;i<13;i++)
	{
		if(max1==cards[i])
		max1=i;
		if(max2==cards[i])
		max2=i;
	}
	if(max1>max2)
	return 1;
	else if(max2>max1)
	return 0;
	do{
		max1=0;
		max2=0;
		for(i=0;i<5;i++)
		for(j=0;j<temp;j++)
		{
			if(pin1[i*3]==cards[j] && max1<j)
			max1=j;
			if(pin2[i*3]==cards[j] && max2<j)
			max2=j;
		}
		temp=max1;
	}while(max1==max2);
	if(max1>max2)
	return 1;
	return 0;
}	
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	FILE*poker=fopen("poker.txt","r");
	char pin[1000][30];
	int i,one=0;
	fread(pin,30000,1,poker);
	fclose(poker);
	for(i=0;i<1000;i++)
	if(rank(pin[i])>rank(pin[i]+15) || rank(pin[i])==rank(pin[i]+15)&&higher(pin[i],pin[i]+15))
	one++;
	printf("%d\n",one);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

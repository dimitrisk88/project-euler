#include<stdio.h>
#include<time.h>
typedef struct num
{
	int a;
	struct num*next;
	struct num*prev;
}Num;
Num*push(Num*head,int a)
{
	if(head==NULL)
	{
		head=malloc(sizeof(Num));
		head->prev=NULL;
		head->next=NULL;
		head->a=a;
	}
	if(a>28123)
	return head;	
	Num*temp;
	while(head->a<a && head->next)
	head=head->next;
	while(head->a>a)
	head=head->prev;
	if(head->a<a)
	{
		temp=head->next;
		head->next=malloc(sizeof(Num));
		if(temp)
		temp->prev=head->next;
		head->next->next=temp;
		head->next->prev=head;
		head->next->a=a;
	}
	return head;
}
int isAbundant(int a)
{
	int b=a/2+1,i,sum=0;
	for(i=1;i<b;i++)
	if(!(a%i))
	sum+=i;
	if(sum>a)
	return 1;
	return 0;
}
int exists(Num*head,int a)
{
	while(head->a<a)
	head=head->next;
	if(head->a==a)
	return 0;
	return 1;
}
int main()
{
	double time=(double)clock()/CLOCKS_PER_SEC;
	int i,sum=0;
	Num*head=NULL,*head2=NULL,*temp;
	for(i=1;i<28123;i++)
	if(isAbundant(i))
	head=push(head,i);
	while(head->prev)
	head=head->prev;
	for(temp=head;temp->next;temp=temp->next)
	for(head=temp;head;head=head->next)
	head2=push(head2,head->a+temp->a);
	while(head2->prev)
	head2=head2->prev;
	for(i=1;i<28123;i++)
	if(exists(head2,i))
	sum+=i;
	printf("%d\n",sum);
    printf("%.3f sec\n",(double)clock()/CLOCKS_PER_SEC-time);
	getch();
}

/*
 * PROGRAM:Find the largest element & smallest element from the SLL
 * FILE:large_small.c
 * CREATED BY:Santosh Hembram
 * DATED:17/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	struct link
	{
		int data;
		struct link *next;
	};
	
//	int large(struct link *);
//	int small(struct link *);
	struct link *first=NULL,*last,*curr;
	int main()
	{
		int num,lar,sma;
		char ch='y';
		void create(int);
		void display(struct link *);
	int large(struct link *);
	int small(struct link *);
	
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to enter more number ? (Y/N):-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		display(first);
		lar=large(first);
		sma=small(first);
		printf("\nThe largest & smallest element from the SLL is :%d\t%d",lar,sma);
		return 0;
	}
	void create(int num)
	{
		curr=(struct link *)malloc(sizeof(struct link));
		curr->data=num;
		curr->next=NULL;
		if(first==NULL)
			first=curr;
		else
			last->next=curr;
		last=curr;
	}
	void display(struct link *N)
	{
		while(N!=NULL)
		{
			printf("\n%d",N->data);
			N=N->next;
		}
	}
	int large(struct link *x)
	{
		int temp=0;
		while(x!=NULL)
		{
			if(x->data >= temp)
				temp = x->data;
			x = x->next;
		}
		return temp;
	}
	int small(struct link *y)
	{
		int temp;
		while(y!=NULL)
		{
			if(y->data<=temp)
				temp=y->data;
			y=y->next;
		}
		return temp;
	}
		
		
			

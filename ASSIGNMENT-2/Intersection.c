/*
 * PROGRAM:Create 2 sll consisting of an integers find their intersection and store in 3rd
 * FILE:intersection.c
 * CREATED BY:Santosh Hembram
 * DATED:17/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>

	typedef struct link
	{
		int data;
		struct link *next;
	}sl;
	
	sl *first=NULL,*last,*curr,*first2,*first3;
	
	void create(int);
	void display(sl *);
	void intersection(sl *,sl *);
	
	int main()
	{
		int num,num2;
		char ch = 'y';
		while(ch=='y' || ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node:[y/n]:- ");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nDisplaying the 1st link list:-\n");
		display(first);
		printf("\n");

		first2=first;
		first=NULL;
		ch = 'y';

		while(ch=='y' || ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num2);
			create(num2);
			printf("\nDo you want to create another node-[y/n]-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nDisplaying the 2nd link list:-\n");
		display(first);

		first3=first;
		first=NULL;

		intersection(first2,first3);
		printf("\n");printf("intersection list-\n");
		
		display(first);
		

			
	}
	void create(int num)
	{
		curr = (sl *)malloc(sizeof(sl));
		curr->data=num;
		curr->next=NULL;
		if(first==NULL)
			first=curr;
		else
			last->next=curr;	
		last=curr;
	}
	void display(sl *ptr)
	{
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}	
	void intersection(sl *n,sl *n1)
	{
		sl *a,*b;int count=0;
	
		for(a=n; a!=NULL ; a=a->next)
		{
			for(b=n1; b!=NULL; b=b->next)
			{
				if( a->data == b->data){
					create(a->data);
					count=1;}
			
			}
		
		}
		if(count!=1)
		{
			printf("\nIntersection = 0 ");
			exit(1);
		}
		
	}
		

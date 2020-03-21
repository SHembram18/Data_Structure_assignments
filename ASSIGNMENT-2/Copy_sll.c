/*
 * PROGRAM:Create a singlie list and copy the list
 * FILE:copy_sll.c
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
	sl *first=NULL,*last,*curr,*first2;
	void create(int );
	void display(sl *);
	void copy_sll(sl *);

	int main()
	{
		int num;
		char ch='y';
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a number-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node:-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		first2=first;
		first=NULL;

		printf("Display the  list-\n");
		display(first2);
		
		printf("\n");

		printf("Display the copy of the list-\n");
		copy_sll(first2);
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
	void display(sl *n)
	{
		while(n!=NULL)
		{
			printf("\n%d",n->data);
			n=n->next;
		}
	}
	void copy_sll(sl *pt)
	{
		while(pt!=NULL)
		{
			create(pt->data);
			pt=pt->next;
		}
	
	}
	
			
	 

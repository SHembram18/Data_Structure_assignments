/*
 * PROGRAM   :To find out even and odd elements from Double link list then extract odd elements & even elements separately & keep them               in 2 auxilary linked list.
 * FILE      :odd_even_dll.c
 * CREATED BY:Santosh Hembram
 * DATED     :26/02/2020
 */

	#include<stdio.h>
	#include<stdlib.h>

	typedef struct d_link_list
	{
		int data;
		struct d_link_list *prev;
		struct d_link_list *next;
	}dll;

	void create(int num);
	void display(dll *);
	void odd_list(dll *);
	void even_list(dll *);

	dll *first=NULL,*last,*curr,*first2,*first3;

	int main()
	{
		int num;
		char ch ='y';

		while(ch=='y' || ch=='Y')
		{
			printf("Enter a number-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node [Y/N]-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nDisplay the list-\n");
		display(first);

		first2=first;
		first=NULL;

		odd_list(first2);

		first3=first2;
		first=NULL;

		even_list(first3);

	}
	void create(int num)
	{
		curr=(dll *)malloc(sizeof(dll ));
		curr->data=num;
		curr->next=NULL;
		curr->prev=NULL;

		if(first==NULL)
			first=curr;
		else
		{
			last->next=curr;
			curr->prev=last;
		}
		last=curr;
	}
	void display(dll *n)
	{
		while(n!=NULL)
		{
			printf("\t%d",n->data);
			n=n->next;
		}
	}
	void odd_list(dll *ptr)
	{
		while(ptr!=NULL)
		{
			if(ptr->data % 2 == 1)
				create(ptr->data);
			ptr=ptr->next;
		}
		printf("\nDisplaying the odd number present in the list-\n");
		display(first);
	}
	void even_list(dll *ptr2)
	{
		while(ptr2!=NULL)
		{	
			if(ptr2->data % 2 == 0 )
				create(ptr2->data);
			ptr2=ptr2->next;
		}
		printf("\nDisplaying the even number present in the list-\n");
		display(first);
	}
		
		

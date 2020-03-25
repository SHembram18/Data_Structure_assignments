/*
 * PROGRAM   :To sort and display a double link list
 * FILE      :sorting_dll.c
 * CREATED BY:Santosh Hembram
 * DATED     :26/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	typedef struct d_link_list
	{
		int data;
		struct d_link_list *next;
		struct d_link_list *prev;
	}dll;
	
	dll *first=NULL,*last,*curr;

	void create(int num);
	void display(dll *);
	void sorting(dll *);

	int main()
	{
		int num;
		char ch='y';

		while(ch=='y' || ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node [y/n]-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nDisplay before sorting-\n");
		display(first);

		sorting(first);
	}
	void create(int num)
	{
		curr=(dll *)malloc(sizeof(dll));
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
	void display(dll *ptr)
	{
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
	}
	void sorting(dll *n)
	{
		dll *n2; int temp;
		
		
		
		while(n!=NULL)
		{
			n2 = n->next;
			while(n2!=NULL)
			{
				if(n->data > n2->data)
				{
					temp = n->data;
					n->data = n2->data;
					n2->data = temp;
				}
				n2=n2->next;
			}
			n=n->next;
		}
		printf("\n");
		printf("\nAfter sorting the list-\n");
		display(first);
	}     

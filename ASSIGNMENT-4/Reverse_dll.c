/*
 * PROGRAM  :To create double link list where each node of double link list will hold one integer as information & display the double link list in reverse order
 * FILE      :reverse_dll.c
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

	dll *first=NULL,*last,*curr;
		
	void create(int);
	void display(dll *);
	void reverse_display(dll *);
	
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
		printf("\nDisplaying the list:-\n");
		display(first);
		printf("\n");
		printf("\nDisplaying the list in reverse order:-\n");
		reverse_display(last);
		return 0;
	}
	void create(int num)
	{
		curr = (dll *)malloc(sizeof(dll));
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
	void reverse_display(dll *ptr2)
	{
		while(ptr2!=NULL)
		{
			printf("\t%d",ptr2->data);
			ptr2=ptr2->prev;
		}
	}

		
	

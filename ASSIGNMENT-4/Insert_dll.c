/*
 * PROGRAM   :To insert a node before a particular node in a double link list
 * FILE      :insert_dll.c
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

	void create(int);
	void display(dll *);
	void insert(dll *,int);

	int main()
	{
		int num,node;
		char ch='y';
		
		while(ch=='y'||ch=='Y')
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
	
		printf("\nEnter the node to search:-");
		scanf("%d",&node);
	
		insert(first,node);	
	
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
	void insert(dll *ptr,int node)
	{		
		dll *ptr2;  int num2,count=0;
		while(ptr->data == node)
		{
			ptr2=ptr;

			printf("\nEnter the new data-");
			scanf("%d",&num2);

			curr = (dll *)malloc(sizeof(dll));
			curr->data=num2;
			curr->prev=NULL;
			curr->next=ptr2;
			ptr->prev=curr;

			first = curr;
		
			printf("\nDisplay the list after insert the new node:-");
			display(first);
			return ;
		}

		while(ptr!=NULL)
		{
			if(ptr->data == node)
			{
				ptr2=ptr;
				count++;
			}
			
			ptr=ptr->next;
		}
		
		if(count==1)
	{	

		last=ptr2->prev;		
		printf("\nEnter the new data:-");
		scanf("%d",&num2);
		curr=(dll *)malloc(sizeof(dll ));
		curr->data=num2;
		curr->next=ptr2;
		curr->prev=last;
		
		last->next=curr;
		ptr2->prev=curr;

		printf("\nDisplay the list after insert the new node:-");
		display(first);
	}
	else
		printf("\nNode is not found in the list------");

      
		


	}

		
		
	
		

		
		

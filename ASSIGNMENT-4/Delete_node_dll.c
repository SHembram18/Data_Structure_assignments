/*
 * PROGRAM:To delete a node after a given node using Double link list
 * FILE:delete_node_dll.c
 * CREATED BY:Santosh Hembram
 * DATED:26/02/2020
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
	void delete_node(dll *,int);

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
		printf("\nDispalying the list-");
		display(first);
		
		printf("\n");

		printf("\nEnter the node to search [It  delete a node which is present after this node ]:-");
		scanf("%d",&node);
		delete_node(first,node);
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
	void display(dll *ptr)
	{
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
	}
	void delete_node(dll *ptr2,int node)
	{
		dll *ptr3,*ptr4,*ptr5,*ptr6; int count=0;
		
		
		ptr5=ptr2;
		ptr6=ptr2;

		while(ptr6!=NULL)
		{
			if(  (ptr6->data == node) && (ptr6->next==NULL) )
			{
				printf("\nNo node present after this [This is the last node---]");
				return ;
			}
			ptr6=ptr6->next;
		}
		
		
		
		while(ptr5!=NULL)
		{
			if( (ptr5->data == node) && ( (ptr5->next)->next ==NULL) )
			{
		
				ptr5->next=NULL;
			printf("\nAfter delete a node-\n");
				display(first);
				return;
			}
			
			ptr5=ptr5->next;
		}	

		while(ptr2!=NULL)
		{
			if(ptr2->data==node)
			{
				ptr3=ptr2->next;
				ptr4=ptr2;
				count++;
			}
			

			ptr2=ptr2->next;
		}
		if(count==1)
		{
			ptr4->next = ptr3->next;
			(ptr3->next)->prev = ptr4;
			
		
			printf("\n");
			printf("\nAfter delete a node-\n");
			display(first);
		}
		else
			printf("\nNode = %d is not present in the list---",node);
	}
			
		
			


		
		

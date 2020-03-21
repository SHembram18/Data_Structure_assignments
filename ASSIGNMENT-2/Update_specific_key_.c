/*
 * PROGRAM:Create a single link list & update a specific key element
 * FILE:update_specific_key.c
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

	sl *first=NULL,*last,*curr;

	void create(int);
	void display(sl *);
	void update_key(sl *,int);

	int main()
	{
		int num,key;
		char ch ='y';
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node:-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("Displaying the list-\n");
		display(first);

		printf("\nEnter the key to serach:-");
		scanf("%d",&key);
		update_key(first,key);
		printf("\t");
		printf("\nAfter updating:-\n");
		display(first);
		
	}
	void create(int num)
	{
		curr=(sl *)malloc(sizeof(sl));
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
			printf("\t%d",n->data);
			n=n->next;
		}
	}
	void update_key(sl *p,int key)
	{
		int u_key;
		while(p!=NULL)
		{
			if (p->data==key )
			{
				printf("\nKey element is found\n");
		
				printf("Enter the new number:-");
				scanf("%d",&u_key);
				p->data=u_key;
				break;
			}
			p=p->next;
		}
	}
	
	

	
			
		
		
				
	
	
		

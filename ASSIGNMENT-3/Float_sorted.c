/*
 * PROGRAM:Write a program to create a single sorted linked list in decending order while each & every node can store a floating point value . Display the list.
 * FILE:float_sorted.c
 * CREATED BY:Santosh Hembram
 * DATED:24/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	
	typedef struct link
	{
		float data;
		struct link *next;
	}sl;
	
	sl *first;

	void create(sl **,float);
	void display(sl *);

	int main()
	{
		float num;
		char ch='Y';
		
		while(ch=='y' || ch=='Y')
		{
			printf("Enter a number :-");
			scanf("%f",&num);
		
			create(&first,num);
			printf("\nDo you want to create another node [y/n]-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nThe created sorted list is:\n");
		display(first);
	}
	void create(sl **ptr,float num)
	{
		sl *curr = *ptr;
		sl *temp;
		temp = (sl *)malloc(sizeof(sl ));
		temp->data = num;
		temp->next=NULL;
		if(curr==NULL)
		{
			*ptr=temp;
			return;
		}
		if(temp->data > curr->data)
		{
			temp->next = curr;
			*ptr = temp;
			return ;
		}
		while(curr->next!=NULL && temp->data < ( (curr->next)->data ))
			curr = curr->next;
		temp->next=curr->next;
		curr->next=temp;
	}
	void display(sl *n)
	{
		if(first==NULL)
		{
			printf("\nList is already empty!");
			exit(1);
		}
		while(n!=NULL)
		{
			printf("%.2f\t",n->data);
			n=n->next;
		}
	}
		
	
			

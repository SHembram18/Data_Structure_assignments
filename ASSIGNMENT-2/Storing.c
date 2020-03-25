/*
 * PROGRAM:Input numbers into the first list stored the even numbers in 2nd list & odd numbers in the 3rd list
 * FILE:storing.c
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

		int num;
		char ch='Y';
		void create(int);
		void display(sl *);
		void even(sl *);
		void odd(sl *);
	
	int main()
	{	
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a number-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to add data more:-[y/n]:-");
			fgetc(stdin);
			scanf("%c",&ch);
		}
		printf("\nDisplay the data of the list:-\n");
		printf("\n");
		display(first);

		first2=first;
		first=NULL;
		
	
		even(first2);

		first3=first;
		first=NULL;		
		
		odd(first2);
		
	
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
	void display(sl *N)
	{
		while(N!=NULL)
		{
			printf("\t%d",N->data);
			N=N->next;
		}
	}
	void even(sl *x)
	{
		while(x!=NULL)
		{
			if(x->data % 2 == 0 )
				create(x->data);
			x=x->next;
		}
		printf("\n");
		printf("\nDisplaying the even number of the list-\n");
		display(first);
	}
	void odd(sl *ptr)
	{
		while(ptr!=NULL)
		{
			if(ptr->data % 2 == 1 )
				create(ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
		printf("\nDisplaying the odd number of the list-\n");
		display(first);
	}
	
	
		
	
			


	

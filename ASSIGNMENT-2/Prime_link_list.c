/*
 * PROGRAM:Create a single link list consisting of integer. Print the prime numbers present with in the list
 * FILE:prime_link_list.c
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

	void create(int);
	void display(sl *);
	void prime_list(sl *);

	int main()
	{
		char ch='y';
		int num;
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a number:-");
			scanf("%d",&num);
			create(num);
			printf("\nDo you want to create another node:-");
			fgetc(stdin);
			scanf("%c",&ch);
			
		}
		printf("Displaying the list:-\n");
		display(first);

		first2=first;
		first=NULL;
	
		prime_list(first2);
		printf("\n");
		printf("Displaying the prime_list:-\n");
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
	void prime_list(sl *z)
	{
		int i=1,count=0;
		while(z!=NULL)
		{
			for(i=1;i<=z->data;i++)
			{
				if(z->data % i == 0)
					count++;
			}
			if(count==2)
			{
				
				create(z->data);
			}
			count=0;
			z=z->next;
		}
	
	}

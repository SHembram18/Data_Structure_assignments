/*
 * PROGRAM:Input a number stores the digit of the number in a SLL
 * FILE:num_store.c
 * CREATED BY:Santosh Hembram
 * DATED:17/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	struct link
	{
		int data;
		struct link *next;
	};
	struct link *first=NULL,*last,*curr;
	int main()
	{
		int num,temp;
		void create(int);
		void display(struct link *);
		printf("Enter a number:-");
		scanf("%d",&num);
		while(num!=0)
		{
			temp =num%10;
			num/=10;
			create(temp);
		}
		display(first);
	}
	void create(int num)	
	{
		curr=(struct link *)malloc(sizeof(struct link));
		curr->data=num;
		curr->next=NULL;
		if(first==NULL)
			first=curr;
		else
			last->next=curr;
		last=curr;
	}
	void display(struct link *N)
	{
		while(N!=NULL)
		{
			printf("\n%d",N->data);
			N=N->next;
		}
	}
		

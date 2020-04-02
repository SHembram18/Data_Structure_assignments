/*
 * PROGRAM:To create a shorted sll which each & every node are capable of storing a single link list 
 * FILE:string_sorted.c
 * CREATED BY:Santosh Hembram	
 * DATED:24/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>

	typedef struct link
	{
		char w[100];
		struct link *next;
	}sl;
	
	void create(sl **first2,char *s)
	{
		sl *curr = *first2;
		sl *temp = (sl *)malloc(sizeof(sl));
		strcpy(temp->w,s);

		if(curr== NULL)
		{
			*first2 = temp;
			return;
		}
		if(strcmp (temp->w,curr->w)<0)
		{
			temp->next = curr;
			*first2 = temp;
			return;
		}
		while((curr->next != NULL) && (strcmp(temp->w,curr->next->w)>0))
			curr = curr->next;
			temp->next = curr->next;
			curr->next = temp;
	}
	void display(sl *n)
	{
		while(n!=NULL)
		{
			puts(n->w);
			n=n->next;
		}
	}

	int main()
	{
	      char str[100];
		sl *first = NULL;
		char ch='y';
		while(ch=='y'||ch=='Y')
		{
			printf("Enter a string:-");
				fgets(str,100,stdin);
			create(&first,str);
			printf("\nDo you want to enter another string:-\n");
			scanf("%c",&ch);

			getc(stdin);
			fflush(stdin);
		}
		printf("\nAfter sorted the string list-\n");
		display(first);
		return 0;
	}		

			
			
	

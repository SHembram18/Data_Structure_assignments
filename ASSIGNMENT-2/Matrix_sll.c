/*
 * PROGRAM:Create a single link list which contains matrix.Display the elements of the list
 * FILE:matrix_sll.c
 * CREATED BY:Santosh Hembram
 * DATED:17/02/2020
 */
	#include<stdio.h>
	#include<stdlib.h>
	typedef struct link
	{
		int data,row,col;
		struct link *next;
	}sl;

	sl *first=NULL,*last,*curr,*first2;

	void create(int,int,int);
	void display(sl *);
	int r,c;
	
	int main()
	{
		int num,r1,c1;	

		printf("Enter total no. of rows & coloumns:-");
		scanf("%d%d",&r,&c);	
	
		for(r1=0;r1<r;r1++)
		{
			for(c1=0;c1<c;c1++)
			{
				printf("Enter %d row & %d coloumn element :-",r1+1,c1+1);
				scanf("%d",&num);
				create(num,r1,c1);
			}
		}
		
		printf("Display list-\n");
		display(first);
	}
	void create(int num,int r1,int c1)
	{
		curr = (sl *)malloc(sizeof(sl));
		curr->data=num;
		curr->row=r1+1;
		curr->col=c1+1;
		curr->next=NULL;

		if(first==NULL)
			first=curr;
		else
			last->next=curr;
		last = curr;
	}

	void display(sl *n)
	{
		int r1,c1;
    		 for(r1=0;r1<r;r1++)
                     {
                               for(c1=0;c1<c;c1++)
                               {
					printf("%d\t",n->data);
					n=n->next;
				}
			printf("\n");
			}
		
}

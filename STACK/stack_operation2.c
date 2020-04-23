			//STACK  ( Dynamic Implementation )
			
			#include<stdio.h>
			#include<malloc.h>
			#include<stdlib.h>
	//		#include<conio.h>
			
		

			typedef struct nodetype
			{
				int info;
				struct nodetype *next;
			}node;
		
			typedef struct stacktype
			{
				node *top;
			}stack;
	
			void initstack(stack *st)
			{
				st->top = NULL;
			}
			
			void push( stack *st,int val )
			{
				node *newnode = NULL;
				newnode = (node *)malloc(sizeof(node));
				if( newnode == NULL )
				{
					printf("\nMEMORY OVERFLOW-----");
			//		getch();
					return;
				}
				newnode->info = val;
				newnode->next = NULL;
				if(st->top == NULL)
				{
					st->top = newnode;
					printf("\nSTACK PUSH SUCCESFUL-----\n");
					return;
				}
				else
				{
					newnode->next = st->top;
					st->top = newnode;
					printf("\nSTACK PUSH SUCCESFUL-----\n");
				}
				return;
			}
			
			int pop(stack *st)
			{
				int popval=0;

				node *temp = st->top;
				if(st->top == NULL)
				{
					printf("\nSTACK EMPTY-----");
				//	getch();
					exit(0);
				}
				else
				{
					popval = temp->info;
					st->top = st->top->next;
					free(temp);
				}
				return popval;
			}
			int main()
			{
				stack st;
				int num,opt;
			//	char ch='y';
			//	clrscr();
				initstack(&st);

				do
				{
				
					printf("\n\tSTACK MENU\n");
					printf("\n1.PUSH OPERATION\n2.POP OPERATION\n3.QUIT\n");
			
					printf("\nEnter option-");
					scanf("%d",&opt);
		
					switch(opt)
					{
						case 1:
							printf("\nEnter data to push:-");
							scanf("%d",&num);
							push(&st,num);
							break;
						case 2:
							num = pop(&st);
							printf("\nSTACK TOP ELEMENT is %d\n",num);
							break;
						case 3:
							exit(0);
							break;
						default:
							printf("\nInvalid");
					}
				}while(opt >= 1 && opt <= 3 );
				return 0;
			}
					


	

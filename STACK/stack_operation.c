			//STATIC STACK OPERATION [ USING ARRAY ]

		#include<stdio.h>
		#include<string.h>
		#include<stdlib.h>
		#define MAX 30
		
		//STATIC STACK DATA STRUCTURE DEFINITION
		
		typedef struct intstackType
		{
			int arr[MAX];
			int top;
		}intstack;

		//TO INITIALISE STACK

		void initstack(intstack *st)
		{
			st->top = -1;
		}
	
		//TO PUSH ELEMENTS INTO STACK

		void push(intstack *st,int val)
		{
			if( st->top == MAX - 1)//STACK FULL
			{
				printf("\nSTACK OVERFLOW-----");
			//	getch();
				exit(1);
			}
			st->top++;
			st->arr[st->top] = val;
			printf("\nSTACK PUSH SUCESSFUL-----\n");
			return;
		}
	
		//TO POP ELEMENT FROM STACK
		
		int pop(intstack *st)	
		{
			int popval;
			if( st->top == -1 )
			{
				printf("\nSTACK EMPTY-----\n");
				fflush(stdin);
				getc(stdin);
				exit(1);
			}
			popval = st->arr[st->top];
			st->top--;
			return popval;
		}
	
		//IMPLEMENTATION OF STACK
		
		int main()
		{
			intstack st;
			int num,opt;

			initstack(&st);
			while(1)
			{
				printf("\n\tSTACK MENU\n");
				printf("\n1:PUSH OPEARTION ON STACK\n2:POP OPERATION ON STACK\n3:QUIT-\n");
		
				printf("\nEnter option: ");
				scanf("%d",&opt);
		
				switch(opt)
				{
					case 1:
						printf("\nEnter data to PUSH: ");
						scanf("%d",&num);
						push(&st,num);
						break;
			
					case 2:
						num = pop(&st);
						printf("\nSTACK TOP element is: %d\n",num);
						break;
				
					case 3:
						exit(0);
						break;
			
					default :
					        	printf("\nINVALID OPTION:\n");
				}
			}
		}
		

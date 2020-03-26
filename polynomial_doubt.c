//TEATING OF POLYNOMILA

	#include<stdio.h>
	#include<stdlib.h>
	typedef struct link
	{
		int coef,exp;
		struct polynomial *next;
	}poly;
	
	void create(poly **first,int c,int e)
	{
		poly *curr = *first;
		poly *temp = (poly *)malloc(sizeof(poly ));
		if(temp==NULL)
		{
			printf("\nMemory allocation failed!!!");
			return ;
		}
		temp->coef = c;
		temp->exp = e;
		temp->next = NULL;	
		if(curr==NULL)
		{
			*first=temp;
			return ;
		}
		if(temp->exp < curr->exp)
		{
			temp->next=curr;
			*first=temp;
			return ;
		}
		while(curr->next!=NULL && temp->exp > curr->next->exp)
		{
			curr = curr->next;
		}
		temp->next = curr->next;
		curr->next = temp;
	}
	void display(poly *N)
	{
		printf("\n");
		while(N!=NULL)
		{
			printf("%d^%d\t",N->coef,N->exp);
			N=N->next;
		}
		printf("\n");
	}
	void add(poly *p1,poly *p2,poly **p3)
	{
		while( (p1!=NULL) && (p2!=NULL) )
		{
			if( p1->exp == p2->exp )
			{
				create(p3,(p1->coef + p2->coef),p1->exp);
				p1 = p1->next;
				p2 = p2->next;
			}
			else if(p1->exp > p2->exp)
			{
				create(p3,p1->coef,p1->exp);
				p1 = p1->next;
			}
			else if(p2->exp > p1->exp)
			{
				create(p3,p2->coef,p2->exp);
				p2 = p2->next;
			}
		}
	
		while(p1!=NULL)
		{
			create(p3,p1->coef,p1->exp);
			p1=p1->next;
		}
		while(p2!=NULL)
		{
			create(p3,p2->coef,p2->exp);
			p2=p2->next;
		}
	}
	int main()
	{
		int c,e;
		poly *poly1=NULL,*poly2=NULL,*poly3=NULL;
	
		char ch='y';
		printf("For 1st polynomial equation\n\n");
		while(ch=='y' || ch=='Y')
		{
			printf("Enter the coeffcient : ");
			scanf("%d",&c);
			
			
			printf("Enter the exponent : ");
			scanf("%d",&e);

			create(&poly1,c,e);
			fflush(stdin);
			getc(stdin);
		
			printf("Do you want to create another node [y/n] - ");
			scanf("%c",&ch);
		}
		printf("\nPolynomial 1 \n");
		display(poly1);
		
		printf("For 2nd polynomial equation\n\n");
		ch ='y';
		while(ch=='y' || ch=='Y')
		{

			 printf("Enter the coeffcient : ");
                       	 scanf("%d",&c);


                        printf("Enter the exponent : ");
                        scanf("%d",&e);

                        create(&poly2,c,e);
			fflush(stdin);
			getc(stdin);
			printf("Do you want to create another node [y/n] - ");
			scanf("%c",&ch);
		}
		printf("\nPolynomial 2 \n");
		display(poly2);

		add(poly1,poly2,&poly3);
		printf("\nAfer addition \n");
		display(poly3);
		return 0;
	}
		
		
		
		
	

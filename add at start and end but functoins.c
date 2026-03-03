#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct node{
	int data;
	struct node *next;
}node;

int menu()
{
	int choice; 
	
	while(1)
	{
		printf("What would you like to do today?\n");
		printf("[1]Create list\n[2]Show list\n[3]Add item to list at front\n[4]Add item to list at end\n[5]Exit\n");
		printf("\nEnter choice [1-5]: ");
		scanf("%d",&choice);
		
		if(choice>=1 && choice <=5)
		{
			break;
		}
		else
		{
			printf("Invalid input. Please enter 1-5 only..Press any key to continue..");
			getch();
			system("cls");
			continue;
		}
	}
	getchar();
	system("cls");
	return choice;
}

node *createlist()
{
	node *start, *newnode;
	char ans[10];
	int ctr=0;
	
	newnode = (node*)malloc(sizeof(node));
	start=newnode;
	
	while(1)
	{
		printf("Item %d: ",ctr+1);
		scanf("%d",&newnode->data);
		getchar();
		
		while(1)
		{
			printf("Add another item? [y/n]: ");
			scanf("%c",&ans);
			getchar();
				
			if(toupper(ans[0]) == 'Y')
			{
				while(getchar() != '\n');
				newnode->next=(node*)malloc(sizeof(node));
				newnode=newnode->next;
				ctr++;
				break;
			}
		
			else if(toupper(ans[0]) == 'N')
			{
				newnode->next=NULL;
				printf("List created! Press any key to continue..");
				getch();
				system("cls");
				return start;
			}
		
			else
			{
				printf("Invalid input. Please enter [y/n].\n\n");
				while(getchar() != '\n');
			}
		}	
	}
}


void printl(node *start, char name[])
{
	if(start == NULL)
	{
		printf("List empty :(\nPress any key to continue..");
		getch();
		system("cls");
		return;
	}
	node *current;
	int ctr=1;
	current=start;
	
	printf("Here's your list :D\n\n[%s]",name);
	while(current!=NULL)
	{
		printf("\n%d. %d",ctr,current->data);
		current=current->next;
		ctr++;	
	}
	getch();
	system("cls");
}

node *addfront(node *start)
{
	if(start == NULL)
	{
		printf("List empty :(\nPress any key to continue..");
		getch();
		system("cls");
		return start;
	}
	
	node *newnode;
	
	newnode=(node*)malloc(sizeof(node));
	printf("Enter item u wanna add: ");
	scanf("%d",&newnode->data);
	getchar();
	newnode->next=start;
	start=newnode;
	system("cls");
	
	return start;
}

node *addend(node *start)
{
	if(start == NULL)
	{
		printf("List empty :(\nPress any key to continue..");
		getch();
		system("cls");
		return start;
	}
	
	node *newnode, *current;
	
	current=start;
	while(current->next != NULL)
	{
		current = current->next;
	}
	
	newnode=(node*)malloc(sizeof(node));
	printf("Enter item u wanna add: ");
	scanf("%d",&newnode->data);
	getchar();
	newnode->next=NULL;
	current->next=newnode;
	system("cls");
	
	return start;
}

int main()
{
	node *start = NULL;
	int choice;
	char name[100];
	
	do{
		choice=menu();
	
		switch(choice)
		{
			case 1:
				printf("List Creation!!\n\nEnter list name: ");
				gets(name);
				start = createlist();
				break;
			
			case 2:
				printl(start,name);
				break;
				
			case 3:
				start=addfront(start);
				break;
			
			case 4:
				start=addend(start);
				break;
		}		
	}while(choice !=5);
	printf("Thank you for using my program :)");
}

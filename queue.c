#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int ph;
	char name[20];
	char usn[10];
	char branch[20];
	struct node *link;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int ph,char name[20],char usn[10], char branch[20])
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->ph=ph;
	strcpy(newnode->name,name);
	strcpy(newnode->usn,usn);
	strcpy(newnode->branch,branch);
	newnode->link=0;
	if(front==0&&rear==0)
	{
		front=rear=newnode;
	}
	else
	{
		rear->link=newnode;
		rear=newnode;
	}
}
void display()
{
	struct node *temp;
	temp=front;
	if(front==0)
	{
		printf("underflow");
	}
	while(temp!=NULL)
	{
		printf("\nName=%s\nBranch=%s\nPhone=%s",temp->name,temp->usn,temp->branch,temp->ph);
		temp=temp->link;
	}
}
void dequeue()
{
	struct node *temp;
	temp=front;
	if(front==0)
	{
		printf("underflow");
	}
	while(temp!=NULL)
	{
		printf("\nName=%s\nBranch=%s\nPhone=%s",temp->name,temp->usn,temp->branch,temp->ph);
		temp=temp->link;
	free(temp);
	}
}
void main()
{
	int n,choice,ph;
	char name[20],usn[10],branch[20];
	while(1)
	{
	printf("\nMenu\n1.Enqueue\n2.Display\n3.Dequeue\n4.exit");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("enter the number of nodes : ");
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{	
				printf("\nEnter the phone no: ");
				scanf("%d",&ph);		
				printf("\nEnter the name: ");
				scanf("%s",&name);
				printf("\nEnter the usn: ");
				scanf("%s",&usn);
				printf("\nEnter the branch: ");
				scanf("%s",&branch);
				enqueue(ph,name,usn,branch);
			}
			break;
		case 2:display();
		break;
			break;
		case 3:dequeue();
		break;
		case 4:exit(1);
	}	
}
}

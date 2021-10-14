#include<stdio.h>
#define MAX 5
int queue_arr[MAX];
int front=-1;
int rear=-1;
void insert(int item)
{
	if((rear+1)%5==front)//if((front==0&&rear==MAX-1)||(front==rear+1))
	{
		printf("queue overflow\n");
		return;
	}
	if(front==-1)
		front=rear=0;
	else
	{
		if(rear==MAX-1)
			rear=0;
		else
			rear=rear+1;
	}
	queue_arr[rear]=item;
}
void deletion()
{
	if(front==-1)
	{
		printf("queue underflow");
		return;
	}
	printf("element deleted from queue is:%d\n",queue_arr[front]);
	if(front==rear)
		front=rear=-1;
	else
	{
		if(front==MAX-1)
			front=0;
		else
			front=front+1;
	}
}
void display()
{
	for(int i=front;i!=rear;i=(i+1)%MAX)
		printf("%d ",queue_arr[i]);
	printf("%d \n",queue_arr[rear]);
}
int main()
{
	int choice,item;
	printf("1.insert\n2.delete\n3.display\n4.quit\n");
	do
	{
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("input elements to insert:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:deletion();
				break;
			case 3:display();
				break;
			case 4:break;
			default:printf("wrong choice");
				break;
		}
	}while(choice!=4);
	return 0;
}						
																		

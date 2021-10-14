#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int size;
	int front,rear;
	int *Q;
};
void insertrear(struct queue *q,int x)
{
	if((q->rear+1)%q->size==q->front)
	{
		printf("overflow\n");
		return;
	}
	q->rear=(q->rear+1)%q->size;
	q->Q[q->rear]=x;
}
int deletefront(struct queue *q)
{
	int x=-1;
	if(q->rear==q->front)
	{
		printf("underflow\n");
		return x;
	}
	q->front=(q->front+1)%q->size;
	x=q->Q[q->front];
	return x;
}
void insertfront(struct queue *q,int x)
{						
	if((q->rear+1)%q->size==q->front)
	{
		printf("overflow\n");
		return;
	}
	q->Q[q->front]=x;
	q->front=(q->front+q->size-1)%q->size;
}
int deleterear(struct queue *q)
{
	int x=-1;
	if(q->rear==q->front)
	{
		printf("underflow\n");
		return x;
	}
	x=q->Q[q->rear];
	q->rear=(q->rear+q->size-1)%q->size;
	return x;
}
void display(struct queue q)
{
	if(q.front==q.rear)
	{
		printf("empty queue\n");
		return;
	}
	do{
		q.front=(q.front+1)%q.size;
		printf("%d",q.Q[q.front]);
	}while(q.front!=q.rear);
	printf("\n");
}
int main()
{
	struct queue q;
	int c,x;
	q.front=q.rear=0;
	printf("enter the size of DEQUEUE");
	scanf("%d",&q.size);
	q.size+=1;
	q.Q=(int *)malloc(q.size*sizeof(int));
	printf("menu\n1.insert front \n2.insert rear\n3.delete front\n4.delete rear\n5.display\n6.exit\n");
	printf("enter your choice:");
	scanf("%d",&c);
	while(c!=6)
	{
		switch(c)
		{
			case 1: printf("enter the no to be inserted:");
				scanf("%d",&x);
				insertfront(&q,x);
				break;
			case 2:printf("enter the no to  be inserteed:");
				scanf("%d",&x);
				insertrear(&q,x);
				break;
			case 3:printf("deleted element %d\n",deletefront(&q));
				break;
			case 4:printf("deleted element %d\n",deleterear(&q));
				break;
			case 5:display(q);
				break;
			default:printf("wrong choice");
				scanf("%d",&c);
		}
		printf("enter your choice:");
		scanf("%d",&c);
	}
}								
						

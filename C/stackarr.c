 #include<stdlib.h>
#include<stdio.h>
struct stackarr
{
	int capacity;
	int top;
	int *arr;
};
int isfull(struct stackarr *stack)
{
	if(stack->top == stack->capacity-1)
		return 1;
	else
		return 0;
}
int isempty(struct stackarr *stack)
{
	if(stack->top==-1)
		return -1;
	else
		return 0;
}
void push(struct stackarr *stack)
{
	int x;
	printf("enter no to be pushed:");
	scanf("%d",&x);
	if(isfull(stack))
		printf("the stack is full!\n");
	else
		stack->arr[++stack->top]=x;
}
int pop(struct stackarr *stack)
{
	int x;
	if(isempty(stack))
		printf("the stack is empty!\n");
	else
	{
		x=stack->arr[stack->top--];
		printf("popped element is %d\n",x);
	}
	return x;
}
void peek(struct stackarr *stack)
{
	if(!isempty(stack))
		printf("top stack element ::%d\n",stack->arr[stack->top]);
	else
		printf("the stack is empty\n");
}
void main()
{
	int x,n,ch=0,i;
	printf("enter the max no of elements in the stack:");
	scanf("%d",&n);
	struct stackarr stack;
	stack.arr = (int *)malloc(sizeof(int)*n);
	stack.capacity = n;
	stack.top=-1;
	printf("push an element -->1!\n");
	printf("pop an element -->2!\n");
	printf("peek in stack -->3!\n");
	printf("enter -1 to break the loop!\n");
	while(ch!=-1)
	{
		printf("enter choice!\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push(&stack);
				break; 
			case 2: pop(&stack);
				break;
			case 3: peek(&stack);
				break;
			default : break;
		}
	}
}			
	
				

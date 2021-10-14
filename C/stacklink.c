/*#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*top;	
int isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
int isfull()
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	int r=t?1:0;
	free(t);
	return r;
}
int stacktop()
{
	if(top)
		return top->data;
	return -1;
}		
void push(int x)
{
	struct node *t=(struct node*)malloc(sizeof(struct node));
	if(t==NULL)
		printf("stack is full");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}		

}
void display(struct node *p)
{
	if(p)
	{
		printf("%d \t",p->data);
		p=p->next;
		display(p);
	}	
}
int pop()
{
	struct node *p;
	int x=-1;
	if(isempty())
		printf("stack is empty");
	else
	{
		p=top;
		top=top->next;
		x=p->data;
		free(p);
	}
	return x;			
}
int peek(int pos)
{
	struct node *p=top;
	int i;
	for(i=0;p!=NULL&&i<pos-1;i++)
		p=p->next;
	if(p!=NULL)
		return p->data;
	else
		return -1;							
}																				
int main()
{
	int size,data;
	printf("enter sizer of stack:\n");
	scanf("%d",&size);
	printf("enter elements to be pushed:\n");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&data);
		push(data);
	}
	printf("now stack is");
	display(top);
	printf("the element at 2nd position is %d\n",peek(2));
	pop();
	printf("stack after popping\n");
	display(top);
	printf("the stack top is %d\n",stacktop());
	return 0;		
}*/
/*==================================HeapSort==========================================
Sorts list by creating a heap and extracing from heap
PRE : List with one element ,Index to last list element
Post : List sorted for smaller to largest 
Written by deo saju 

#include<stdio.h>
// creating a heap
void reheapUp(int *heap,int newNode){
    int parent,hold;
    if(newNode){
        parent = (newNode - 1)/2;
        if( heap[newNode] > heap[parent]){
            hold = heap[parent];
            heap[parent] = heap[newNode];
            heap[newNode] = hold;
            reheapUp(heap, parent);
        }

    }return;
}

void reheapDown(int* heap,int root,int last){
    int hold,leftKey,rightKey,largeChildKey=0,largeChildIndex;
    if((root * 2 +1) <= last){
        leftKey = heap[root * 2 +1];
        if((root * 2 +2) <= last)
            rightKey = heap[root * 2 +2];
        else
            rightKey = -1;
        if(leftKey > rightKey){
            largeChildKey = leftKey;
            largeChildIndex = root * 2 + 1; 
        }
        else{
            largeChildKey = rightKey;
            largeChildIndex = root * 2 + 2;
        }
        if(heap[root] < heap[largeChildIndex]){
            hold = heap[root];
            heap[root] = heap [largeChildIndex];
            heap[largeChildIndex] = hold;
            reheapDown(heap, largeChildIndex ,last);
        }
    }return;
}

void HeapSort( int list[],int last){
    int sorted,holdData;

    //create the heap from list
    for(int walker=1;walker<=last;walker++){
        reheapUp(list,walker);
    }
    sorted=last;
    while(sorted>0){
        holdData =list[0];
        list[0] = list[sorted];
        list[sorted] = holdData;
        sorted--;

        //removing root and reheaping all others
        reheapDown(list,0,sorted);
    }
    for(int i=0;i<last;i++){
        printf("%d ",list[i]);
    }
    return;
}


int main(){
    int list[]={3,14,15,2,41,1,4,6};
    int lst = 8;
    HeapSort(list,lst);
}
*/
#include<stdio.h>
int main()
{
	int T,k,n,count=0;
	//printf("\nenter test cases:");
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		//printf("\nenter no of integers:");
		scanf("%d",&n);
		//printf("\nenter k");
		scanf("%d",&k);
		int a[n];
		for(int i=1;i<=n;i++)
		{
			count=0;
			scanf("%d",&a[i]);	
			for(int i=1;i<=T;i++)
			{
				if((a[i]+k)%7)
					count++;
			}		
		}
		printf("%d",count);	
	}		
return 0;
}  

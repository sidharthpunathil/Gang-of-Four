#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t full,mutex,empty,x; //Declare semaphore variables
int ful,mut,emp,a;
void producer() //Function to produce an item and add it to buffer
{
	sem_wait(&mutex);
	sem_post(&full);
	sem_wait(&empty);
    	sem_post(&x);
    	sem_getvalue(&x,&a);
	printf("Producer produces item %d\n",a);
	sem_post(&mutex);
}
void consumer() //Function to consume an item and remove it from buffer
{
	sem_wait(&mutex);
	sem_wait(&full);
	sem_post(&empty);
    	sem_getvalue(&x,&a);
	printf("Consumer consumes item %d\n",a);
	sem_wait(&x);
	sem_post(&mutex);
}
void main()
{
    //initializes semaphore variables
    sem_init(&mutex,1,1);
    sem_init(&full,1,0);
    sem_init(&empty,1,10);
    sem_init(&x,1,0);
    int n;
    printf("1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while(1) 
    {
        printf("\nEnter your choice: ");
        scanf("%d",&n);
        sem_getvalue(&mutex,&mut);
        switch(n)
        { 
            case 1:
                sem_getvalue(&empty,&emp);
                if((mut==1)&&(emp!=0))
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:
                sem_getvalue(&full,&ful);
                if((mut==1)&&(ful!=0))
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                //destroys semaphore variables
                sem_destroy(&mutex);
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&x);
                printf("***EXITING***\n\n");
                exit(0);
                break;
        }
    }
}

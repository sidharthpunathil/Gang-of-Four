#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
	int size;
	int top;
	char *s;
};
void push(struct stack *st,int x)
{
	if(st->top==st->size-1)
		printf("stack overflow");
	else
	{
		st->top++;
		st->s[st->top]=x;
	}
}
int pop(struct stack *st)
{
	int x=-1;
	if(st->top==-1)
		printf("stack overflow");
	else
	{
		x=st->s[st->top];
		st->top--;
	}
	return x;
}
int isempty(struct stack st)
{										                                 		         	
	if(st.top==-1)
		return -1;
	else
		return 0;
}
int checkpair(char ch1,char ch2)	
{
	if(ch1=='('&&ch2==')')
		return 1;
	else if(ch1=='{'&&ch2=='}')
		return 1;
	else if(ch1=='['&&ch2==']')
		return 1;
	else
		return 0;
}
int isbalance(char *exp)
{
	struct stack st;
	st.size=strlen(exp);
	st.s=(char *)malloc(st.size*sizeof(char));
	st.top=-1;
	int i=0;
	int a;
	while(exp[i])
	{
		if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
		{
			push(&st,exp[i]);
			a=1;
		}
		else if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
		{
			if(isempty(st))
				a=0;
			else if (!checkpair(pop(&st),exp[i]))
				a=0;
		}
		i++;
	}
	free(st.s);
	return a;
}
int main()
{
	char exp[100]="{([])}";
	if(isbalance(exp))
		printf("balanced");
	else
		printf("not balanaced");
	return 0;
}		
														     
	     								
	     													

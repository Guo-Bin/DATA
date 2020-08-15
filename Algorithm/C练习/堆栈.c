#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int value;
	struct _Node *next;
} node;

//functions
node* create();
void addstack(node *head, int number);
void outputstack(node *head);
int length(node *head);
void freestack(node *head);


int main()
{
	int data;
	node *head = create();
	//create(head);
	
	do
	{
		printf("Please input a value that you want to store:\n");
		scanf("%d",&data);
		if( data != -1)
		{
			addstack(head, data);
		}
		//addstack(head, data);
	}while(data != -1);
	
	outputstack(head);
	printf("The length of the stack is:%d\n",length(head));
	
	freestack(head);
	return 0;
}



//create a empty linkedlist

node* create()
{
	node *s = (node*)malloc(sizeof(node));
	s->next = NULL;
	return s;
}


//the length of the stack
int length(node *head)
{
	node *tmp = head;
	int cont = 0;
	while(tmp->next)
	{
		cont++;
		tmp = tmp->next;
	}
	return cont;
}

//add a stack
void addstack(node *head, int number)
{
	//there is no need to check if the stack is full because the stack is a linked_list
	node *newdata = (node*)malloc(sizeof(node));
	newdata->value = number;
	newdata->next = head->next;
	head->next = newdata;
}

//delete a stack
//now we need to check if the stack is empty
void outputstack(node *head)
{
	int pop;
	node *tmp = head->next;
	if( length(head) != 0)
	{
		pop = tmp->value;
		head->next = tmp->next;
		free(tmp);
		printf("%d\n",pop);
	} else {
		printf("The stack is empty!\n");
	}
}

//free all the stack
void freestack(node *head)
{
	node *p;
	node *q;
	for(p = head; q; p = q)
	{
		q = p->next;
		free(p);
	}
	printf("Free successfully!\n");
}

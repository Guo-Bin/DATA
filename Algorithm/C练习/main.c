#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
	int value;
	struct _Node *next;
} node;


int lengthOflist(node *head);
void freeList(node *head);
int Findindex(int i, node *head);
int Findvalue(int number, node *head);


int main()
{
	node *head = NULL;
	node *last;
	int number,index,findvalue;
	
	do{
		printf("Please input a data:\n");
		scanf("%d",&number);
		node *p = (node*)(malloc(sizeof(node)));
		p->value = number;
		p->next = NULL;
		last = head;	
		if(last)
		{
			while(last->next)
			{
				last = last->next;
			}
			last->next = p;
		} else {
			head = p;
		}

	}while( number != -1);
	
	printf("Length of the list:%d\n",lengthOflist(head));
	/*
	printf("Input the number what you want to know:\n");
	scanf("%d",&index);
	if(Findindex(index, head) != -1)
	{
		printf("The %d linked_list's value is %d.\n",index,Findindex(index, head));
	}
	*/
	printf("Input the value which you want to find:\n");
	scanf("%d",&findvalue);
	if(Findvalue(findvalue,head))
	{
		printf("The value %d you want to find is in the %d linked_list.\n",findvalue,Findvalue(findvalue,head));
	}
	
	freeList(head);
	return 0;
}


//return the length of the list
int lengthOflist(node *head)
{
	int i = 0;
	node *tem = head;
	while(tem->next)
	{
		if(tem)
		{
			tem = tem->next;
			i++;
		}
	}
	return i;
}


//free the linked list
void freeList(node *head)
{
	node *p;
	node *q;
	for(p = head; p; p = q)
	{
		q = p->next;
		free(p);
	}
	printf("Free successfully!\n");
}


//search

//find by the number index
int Findindex(int i, node *head)
{
	node *tmp = head;
	int cont = 0;
	int answer = -1;
	
	if( i <= lengthOflist(tmp) && i > 0 )
	{
		while(tmp->next)
		{
			cont++;
			if(cont == i)
			{
				answer = tmp->value;
				break;
			}
			tmp = tmp->next;
		}
	} else {
		printf("The index is invalid!\n");
	}
	return answer;
}

//find by the value
int Findvalue(int number, node *head)
{
	node *tmp = head;
	int cont = 0;
	int len = lengthOflist(tmp);
	while(cont <= len)
	{
		cont++;
		if(tmp->value == number)
		{
			break;
		}
		tmp = tmp->next;
	}
	return cont;
}

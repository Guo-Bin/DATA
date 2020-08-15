#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
} BST;

typedef struct {
	BST* *data;
	int front;
	int rear;
} queue;

BST* outqueue(queue *q);
void inqueue(queue *q, int number);
queue* createqueue(queue *q);
BST* insert(BST *p, int number);
void levelorder(BST *p);
int isemptyq(queue *q);

int main()
{
	BST *root = NULL;
	printf("Input the number of the node:\n");
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int number;
		printf("Input the data:\n");
		scanf("%d", &number);
		root = insert(root, number);
	}
	levelorder(root);
	return 0;
}

BST* insert(BST *p, int number)
{
	if(!p)
	{
		p = (BST*)malloc(sizeof(BST));
		p->left = p->right = NULL;
		p->value = number;
	} else if(number > p->value){
		p->right = insert(p->right, number);
	} else if(number < p->value){
		p->left = insert(p->left, number);
	}
	return p;
}

queue* createqueue(queue *q)
{
	q = (queue*)malloc(sizeof(queue));
	q->front = -1;
	q->rear = -1;
	q->data = (BST*)malloc((maxsize)*sizeof(BST));
	return q;
}

void inqueue(queue *q, int number)
{
	if((q->rear+1)%maxsize == q->front)
	{
		printf("The queue is full!");
		return;
	}
	q->rear = (q->rear+1)%maxsize;
	q->data[q->rear] = number;
}

BST* outqueue(queue *q)
{
	if(q->rear == q->front)
	{
		printf("The queue is empty!");
		return;
	}
	q->front = (q->front+1)%maxsize;
	return q->data[q->front];
}

void levelorder(BST *p)
{
	queue *q; BST *temp;
	if(!p) return;
	q = createqueue(q);
	inqueue(q, p);
	while(q->rear != q->front)
	{
		temp = outqueue(q);
		printf("%d\t", temp->value);
		if(temp->left) inqueue(q, temp->left);
		if(temp->right) inqueue(q, temp->right);
	}
}

int isemptyq(queue *q)
{
	return ;
}

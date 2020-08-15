#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree{
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
} BT;

typedef struct ROOT{
	BT *root;
} Tree;

typedef struct node{
	BT *data;
	struct node *next;
} stack;

void createtree(Tree *tree, int number);
void preorder(BT *tree);
BT* createstack();
int isempty(stack *s);
void push(stack *s, BT *store);
BT* pop(stack *s);

int main()
{
	Tree tree;
	tree.root = NULL;
	int n;
	printf("Input the number of the node in the BT:\n");
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
	{
		int number;
		printf("Input the number:\n");
		scanf("%d",&number);
		createtree(&tree, number);
	}
	preorder(tree.root);
	return 0;
}

void createtree(Tree *tree, int number)
{
	BT *NODE = (BT*)malloc(sizeof(BT));
	NODE->value = number;
	NODE->left = NULL;
	NODE->right = NULL;
	if(!tree->root)
	{
		tree->root = NODE;
	} else {
		BT *tmp = tree->root;
		while(tmp)
		{
			if(number < tmp->value)
			{
				if(tmp->left != NULL)
				{
					tmp = tmp->left;
				} else {
					tmp->left = NODE;
					return;
				}
			} else {
				if(tmp->right != NULL)
				{
					tmp = tmp->right;
				} else {
					tmp->right = NODE;
					return;
				}
			}
		}
	}
}

void preorder(BT *tree)
{
	BT *tmp = tree;
	stack *s = createstack();
	while(tmp||!isempty(s))
	{
		while(tmp)
		{
			push(s, tmp);
			//printf("%d\t",tmp->value); /* preorder */ 
			tmp = tmp->left;
		}
		if(!isempty(s))
		{
			tmp = pop(s);
			printf("%d\t",tmp->value);    /* inorder */
			tmp = tmp->right;
		}
	}
}

BT* createstack()
{
	stack *s = (stack*)malloc(sizeof(stack));
	s->next = NULL;
	return s;
}

int isempty(stack *s)
{
	return (s->next == NULL);
}

void push(stack *s, BT *store)
{
	stack *tmp = (stack*)malloc(sizeof(stack));
	tmp->data = store;
	tmp->next = s->next;
	s->next = tmp;
}

BT* pop(stack *s)
{
	stack *firstcell = s->next;
	BT *answer = firstcell->data;
	s->next = firstcell->next;
	free(firstcell);
	return answer;
}

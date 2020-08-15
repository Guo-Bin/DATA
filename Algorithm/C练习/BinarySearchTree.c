#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
} BST;

typedef struct NODE{
	BST *data;
	struct NODE *next;
} stack;

//functions
BST* insert(BST *root, int number);
BST* deletenode(BST *root, int number);
BST* find(BST *root, int number);
BST* find(BST *root, int number);
BST* findmin(BST *root);
void freetree(BST *root);


void push(stack *s, BST *root)
{
	if(s)
	{
		stack *tmp = (stack*)malloc(sizeof(stack));
		tmp->data = root;
		tmp->next = s->next;
		s->next = tmp;
	}
}

BST* pop(stack *s)
{
	if(s)
	{
		stack *temp = s->next;
		BST *tmp = temp->data;
		s->next = temp->next;
		free( temp );
		return tmp;
	}
}

stack* createstack()
{
	stack *s = (stack*)malloc(sizeof(stack));
	s->next = NULL;
	return s;
}

int isempty(stack *s)
{
	return (s->next == NULL);
}

void inorder(BST *root)
{
	stack *s = createstack();
	while(root||!isempty(s))
	{
		while(root)
		{
			push(s, root);
			root = root->left;
		}
		if(!isempty(s))
		{
			root = pop(s);
			printf("%d\t", root->value);
			printf("\n");
			root = root->right;
		}
	}
}

int main()
{
	int n, data, number;
	BST *root = NULL;
	
	printf("Input the number of the node:\n");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("Input the data of the node:\n");
		scanf("%d", &data);
		root = insert(root, data);
	}
	
	inorder(root);
	
	/*printf("Input the number that you want to delete:\n");
	scanf("%d", &number);
	root = deletenode(root, number);
	*/
	printf("Input the number that you want to find:\n");
	scanf("%d", number);
	printf("The number is:%d\n", find(root, number));
	
	freetree(root);
	return 0;
}

BST* insert(BST *root, int number)
{
	if(!root)
	{
		BST *treenode = (BST*)malloc(sizeof(BST));
		treenode->value = number;
		treenode->left = treenode->right = NULL;
		root = treenode;
	} else if(number < root->value){
		root->left = insert(root->left, number);
	} else if(number > root->value){
		root->right = insert(root->right, number);
	} else {
		printf("The number has existed!");
		return;
	}
	return root;
}

BST* find(BST *root, int number)
{
	while(root)
	{
		if(number < root->left)
		{
			root = root->left;
		} else if(number > root->right){
			root = root->right;
		} else {
			return root;
		}
	}
	return NULL;
}

BST* findmax(BST *root)
{
	if(root)
	{
		while(root->right)
		{
			root = root->right;
		}
	}
	return root;
}

BST* findmin(BST *root)
{
	if(root)
	{
		while(root->left)
		{
			root = root->right;
		}
	}
	return root;
}

BST* deletenode(BST *root, int number)
{
	if(!root)
	{
		printf("Not Found!");
	} else if(number < root->value){
		root->left = deletenode(root->left, number);
	} else if(number > root->value){
		root->right = deletenode(root->right, number); 
	} else {
		if(root->left && root->right)
		{
			BST *tmp = findmax(root);
			root->value = tmp->value;
			root->right = deletenode(root->right, root->value);
		} else {
			BST *temp = root;
			if(!root->left)
			{
				root = root->right;
			} else if(!root->right){
				root = root->left;
			}
			free( temp );
		}
	}
	return root;
}

void freetree(BST *root)
{
	freetree(root->left);
	freetree(root->right);
	free( root );
}

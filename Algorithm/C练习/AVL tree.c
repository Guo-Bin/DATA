#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	int height;
	struct node *left;
	struct node *right;
} AVL;

AVL* singleleftturn(AVL *root);
AVL* singlerightturn(AVL *root);
AVL* doubleleftrightturn(AVL *root);
AVL* doublerightleftturn(AVL *root);
AVL* insert( AVL *T, int X );
int getheight(AVL *root);
void inorder(AVL *root);
int max(int a, int b);
void freetree(AVL *root);

int main()
{
	int n;
	AVL *root = NULL;
	
	printf("Input the number of the node:\n");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int data;
		printf("Input the data that you want to store:\n");
		scanf("%d", &data);
		root = insert(root, data);
	}
	
	//if(root->left == NULL) printf("yes\t");
	//if(root->right == NULL) printf("yes\t");
	inorder(root);
	freetree(root);
	
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

AVL* singleleftturn(AVL *root)
{
		AVL *tmp = root->left;
		root->left = tmp->right;
		tmp->right = root;
		root->height = max(getheight(root->left), getheight(root->right))+1;   /* updata the height of tree */
		tmp->height = max(getheight(tmp->left), root->height)+1;
		return tmp;
}

AVL* singlerightturn(AVL *root)
{
		AVL *tmp = root->right;
		root->right = tmp->left;
		tmp->left = root;
		root->height = max(getheight(root->left), getheight(root->right))+1;
		tmp->height = max(getheight(tmp->left), root->height)+1;
		return tmp;
}

AVL* doubleleftrightturn(AVL *root)
{
		root->left = singlerightturn(root->left);
		return singleleftturn(root);
}

AVL* doublerightleftturn(AVL *root)
{
		root->right = singleleftturn(root->right);
		return singlerightturn(root);
}

AVL* insert( AVL *T, int X )
{ /* ��X����AVL��T�У����ҷ��ص������AVL�� */
    if ( !T ) { /* ��������������½�����һ�������� */
        T = (AVL*)malloc(sizeof(AVL));
        T->value = X;
        T->height = 0;
        T->left = T->right = NULL;
    } /* if (�������) ���� */
 
    else if ( X < T->value ) {
        /* ����T�������� */
        T->left = insert( T->left, X);
        /* �����Ҫ���� */
        if ( getheight(T->left)-getheight(T->right) == 2 )
            if ( X < T->left->value ) 
               T = singleleftturn(T);      /* ���� */
            else 
               T = doubleleftrightturn(T); /* ��-��˫�� */
    } /* else if (����������) ���� */
     
    else if ( X > T->value ) {
        /* ����T�������� */
        T->right = insert( T->right, X );
        /* �����Ҫ���� */
        if ( getheight(T->left)-getheight(T->right) == -2 )
            if ( X > T->right->value ) 
               T = singlerightturn(T);     /* �ҵ��� */
            else 
               T = doublerightleftturn(T); /* ��-��˫�� */
    } /* else if (����������) ���� */
 
    /* else X == T->Data��������� */
 
    /* �����˸������� */
    T->height = max( getheight(T->left), getheight(T->right) ) + 1;
     
    return T;
}

int getheight(AVL *root)
{
	int hl, hr, max;
	if(root)
	{
		hl = getheight(root->left);
		hr = getheight(root->right);
		max = (hl > hr ? hl:hr);
		return (max + 1);
	}
	return 0;
}

void inorder(AVL *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\t", root->value);
		inorder(root->right);
	}
}

void freetree(AVL *root)
{
	if(root->left) freetree(root->left);
	if(root->right) freetree(root->right);
	free(root);
}

/*AVL* insert(AVL *root, int number)
{
	if(!root)
	{
		root = (AVL*)malloc(sizeof(AVL));
		root->value = number;
		root->left = root->right = NULL;
		root->height = 0;
	}
	else if(number < root->value)
	{
		root->left = insert(root->left, number);
		if(getheight(root->left) - getheight(root->right) == 2)
		{
			if(number < root->left->value)
			{
				root = singleleftturn(root);
			} else if(number > root->right->value){
				root = doubleleftrightturn(root);
			}
		}
	}
	else if(number > root->value){
		root->right = insert(root->right, number);
		if(getheight(root->left) - getheight(root->right) == -2)
		{
			if(number > root->right->value)
			{
				root = singlerightturn(root);
			} else if(number < root->right->value){
				root = doublerightleftturn(root);
			}
		}
	}
	root->height = max(getheight(root->left), getheight(root->right))+1;
	return root;
}*/

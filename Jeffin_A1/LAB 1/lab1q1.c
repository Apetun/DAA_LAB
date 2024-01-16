#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;



node* create(node* root, int x)
{
    if (root == NULL) {

    	node* temp = (node*)malloc(sizeof(node));
    	temp->data = x;
        return temp;
    }
    if (x < root->data) {
        root->left = create(root->left, x);
    }
    else if (x > root->data) {
        root->right = create(root->right, x);
    }
    return root;
}



void preorder(node* root)
{
	if(root)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
	else
	return;	
}



void postorder(node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	else
	return;	
}


void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	else
	return;	
}


void search(node* root,int x)
{
	if(root)
	{	
		if(root->data == x)
		{
			printf("Key found\n");
		}
		else if(x > root->data)
		{
			if(root->right)
			search(root->right, x);
			else{
			printf("Key not found inserting key\n");
			root->right = create(NULL,x);}
		}
		else
		{
			if(root->left)
			search(root->left , x);
			else{
			printf("Key not found inserting key\n");
			root->left = create(NULL,x);}
		}
	}
	
}





int main()
{	
	int x;
	printf("Enter the root:");
	scanf("%d",&x);
	node* tree = NULL;
	tree=create(tree,x);

	printf("Enter the next value in the bst or -1 to exit:\n");
	scanf("%d",&x);
	while(x!=-1)
	{
		tree=create(tree,x);
		scanf("%d",&x);
	}


	printf("Postorder:");
	postorder(tree);
	printf("\n");

	printf("Inorder:");
	inorder(tree);
	printf("\n");


	printf("Enter the key to be searched:");
	scanf("%d",&x);

	search(tree, x);

	printf("Preorder:");
	preorder(tree);
	printf("\n");


	return 0;
}
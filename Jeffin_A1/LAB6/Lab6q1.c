#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* left,* right;
}node;

node *createnode(int key)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=key;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}

static int count=0;

int countnodes(node *root)
{
	if(root!=NULL)
	{
		countnodes(root->left);
		count++;
		countnodes(root->right);
	}
	return count;
}


int main()
{
	node *newnode=createnode(25);
	newnode->left=createnode(27);
	newnode->right=createnode(19);
	newnode->left->left=createnode(17);
	newnode->left->right=createnode(91);
	newnode->right->left=createnode(13);
	newnode->right->right=createnode(55);
	printf("number of nodes in the tree 1 = %d",countnodes(newnode));
	printf("\n");
	count=0;
}


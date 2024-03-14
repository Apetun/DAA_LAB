#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{	int value;
	struct hash* nvalue;
}hash;

int opcount = 0;

void createhash(hash* openhash[],int m)
{	
	for(int i=0; i<m;i++)
	{
		hash* temp = (hash*)malloc(sizeof(hash));
		temp->value = 0;
		temp->nvalue = NULL;
		openhash[i]= temp;
	}
}


void addvalue(int arr[],hash* openhash[],int m,int n)
{
	for(int i= 0;i<n;i++)
	{
		int key = arr[i]%m;
		hash* curr = openhash[key];
		while(curr->nvalue!=NULL)
		{
			curr = curr->nvalue;
		}
		curr->value = arr[i];
		hash* temp = (hash*) malloc(sizeof(hash));
		temp->value = 0;
		temp->nvalue = NULL;
		curr->nvalue = temp;

	}
}

void printhash(hash* openhash[],int m)
{
	for(int i =0;i<m;i++)
	{
		hash* curr = openhash[i];
		while(curr->nvalue)
		{
			printf("%d ->",curr->value);
			curr=curr->nvalue;
		}
		printf("\n");
	}
}

void search(hash* openhash[],int value,int m)
{
	hash* curr = openhash[value%m];
	opcount++;

	while(curr->value != value && curr->nvalue)
	{
		curr=curr->nvalue;
		opcount++;
	}

	if(curr)
	{
		printf("value found");
	}
	else
	{
		printf("value not found");
	}

	printf("\nopcount: %d\n",opcount);

}

int main(){
	int n,m;
	printf("Enter the value of n:");
	scanf("%d",&n);
	printf("Enter the value of m:");
	scanf("%d",&m);
	hash* openhash[m];
	createhash(openhash,m);
	int arr[n];
	printf("Enter the values:");
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&arr[i]);
	}
	addvalue(arr,openhash,m,n);
	printhash(openhash,m);
	int value;
	printf("Enter the value to be searched:");
	scanf("%d",&value);
	search(openhash,value,m);
	return 0;
}
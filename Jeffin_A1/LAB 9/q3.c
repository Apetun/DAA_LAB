#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{	int value;
}hash;

int opcount = 0;

void createhash(hash* openhash[],int m)
{	
	for(int i=0; i<m;i++)
	{
		hash* temp = (hash*)malloc(sizeof(hash));
		temp->value = 0;
		openhash[i]= temp;
	}
}


void addvalue(int arr[],hash* openhash[],int m,int n)
{

	for(int i= 0;i<n;i++)
	{
		
		int key = arr[i]%m;
		hash* curr = openhash[key];
		while(curr->value != 0)
		{
			key++;
			curr = openhash[key%m];
		}
		curr->value = arr[i];

	}
}

void printhash(hash* openhash[],int m)
{
	for(int i = 0;i<m;i++)
	{
		hash* curr = openhash[i];
		printf("%d ->",curr->value);
	}
}

void search(hash* openhash[],int value,int m)
{	int key= value%m;
	hash* curr = openhash[key];
	opcount++;
	int i =0;
	while(curr->value != value && i < m)
	{
		key++;
		hash* curr = openhash[key%m];
		i++;
	}

	if(curr->value == value)
	{
		printf("value found");
	}
	else
	{
		printf("value not found");
	}

	printf("\nopcount: %d\n",opcount);

}


void tochar(int arr[],char val[][20],int n)
{
	for(int i=0;i<n;i++)
	{
		

	}
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
	char val[n][20];
	printf("Enter the values:");
	for(int i=0;i<n;i++)
	{	
		scanf(" %s",&val[i][0]);
	}

	for(int i=0;i<n;i++)
	{	
		printf(" %s",val[i]);
	}


	tochar(arr,val,n);
	addvalue(arr,openhash,m,n);
	printhash(openhash,m);
	int value;
	printf("\nEnter the value to be searched:");
	scanf(" %d",&value);
	search(openhash,value,m);
	return 0;*/
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash
{	int value;
	char str[20];
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


void addvalue(int arr[],char val[][20],hash* openhash[],int m,int n)
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
		strcpy(curr->str,val[i]);

	}
}

void printhash(hash* openhash[],int m)
{
	for(int i = 0;i<m;i++)
	{
		hash* curr = openhash[i];
		printf("%s ->",curr->str);
	}
}

void search(hash* openhash[],char value[],int ascii,int m)
{	int key= ascii%m;
	hash* curr = openhash[key];
	opcount++;
	int i =0;
	while(strcmp(curr->str,value)!=0 && i < m)
	{
		key++;
		hash* curr = openhash[key%m];
		i++;
	}

	if(strcmp(curr->str,value)==0)
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
		int j=0;
		char ch = val[i][j];
		int sum = 0;
		while(ch!='\0')
		{
			sum+=(int)ch;
			j++;
			ch = val[i][j];
		}

		arr[i]=sum;
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

	tochar(arr,val,n);

	addvalue(arr,val,openhash,m,n);
	printhash(openhash,m);
	char value[20];
	printf("\nEnter the value to be searched:");
	scanf(" %s",value);

	int j=0;
		char ch = value[j];
		int ascii = 0;
		while(ch!='\0')
		{
			ascii+=(int)ch;
			j++;
			ch = value[j];
		}


	search(openhash,value,ascii,m);
	return 0;
}
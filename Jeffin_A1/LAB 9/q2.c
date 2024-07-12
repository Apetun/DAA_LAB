#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash
{
	char str[20];
	struct hash* next;
}hash;

int opcount = 0;

void createhash(hash* openhash[],int m)
{	
	for(int i=0; i<m;i++)
	{
		hash* temp = (hash*)malloc(sizeof(hash));
		temp->next = NULL;
		openhash[i]= temp;
	}
}


void addvalue(int arr[],char val[][20],hash* openhash[],int m,int n)
{

	for(int i= 0;i<n;i++)
	{
		
		int key = arr[i]%m;
		hash* curr = openhash[key];
		while(curr->next != NULL)
		{
			curr= curr->next;
		}
		strcpy(curr->str,val[i]);
		hash* temp = (hash*)malloc(sizeof(hash));
		temp->next = NULL;
		curr->next = temp;

	}
}

void printhash(hash* openhash[],int m)
{
	for(int i = 0;i<m;i++)
	{
		hash* curr = openhash[i];
		while(curr->next!=NULL)
		{printf("%s ->",curr->str);
		curr=curr->next;
		}
		printf("\n");
	}
}

void search(hash* openhash[],char value[],int ascii,int m)
{	int key= ascii%m;
	hash* curr = openhash[key];
	opcount++;
	int i =0;
	while(strcmp(curr->str,value)!=0 && curr!=NULL)
	{
		curr=curr->next;
		opcount++;
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
		char ch = val[i][0];
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

	printf("The ascii value array:");
	for(int i=0;i<n;i++)
	{	
		printf("%d ->",arr[i]);
	}


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
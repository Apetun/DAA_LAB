#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash
{
	char str[20];
}hash;

int opcount = 0;

void createhash(hash* closedhash[],int m)
{	
	for(int i=0; i<m;i++)
	{
		hash* temp = NULL;
		closedhash[i]= temp;
	}
}


void addvalue(int arr[],char val[][20],hash* closedhash[],int m,int n)
{

	for(int i= 0;i<n;i++)
	{
		
		int key = arr[i]%m;

		while(closedhash[key] !=NULL)
		{	
			key = (key+1)%m;
		}
		hash* curr = (hash*)malloc(sizeof(hash));
		strcpy(curr->str,val[i]);
		closedhash[key] = curr;

	}
}

void printhash(hash* closedhash[],int m)
{
	for(int i = 0;i<m;i++)
	{
		hash* curr = closedhash[i];
		if(curr)
		printf("%s ->",curr->str);
		else
		printf("NULL ->");
	}
}

void search(hash* closedhash[],char value[],int ascii,int m)
{	int key= ascii%m;
	hash* curr = closedhash[key];
	opcount++;

	int i =0;
	if(curr)
{while(strcmp(curr->str,value)!=0&&i<m)
	{
		key = (key + 1)%m;
		curr = closedhash[key];
		i++;
		opcount++;

		if(curr == NULL)
		continue;
	}
}

if(curr)
	{if(strcmp(curr->str,value)==0)
	{
		printf("value found");
	}
	else
	{
		printf("value not found");
	}}
	else printf("value not found");

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
	hash* closedhash[m];
	createhash(closedhash,m);
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


	addvalue(arr,val,closedhash,m,n);
	printhash(closedhash,m);
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


	search(closedhash,value,ascii,m);
	return 0;
}
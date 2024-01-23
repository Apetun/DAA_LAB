#include<stdio.h>
#include<stdlib.h>

int opcount = 0;

int StringMatch(char *T, unsigned int n,char *P , unsigned int m)
{
opcount = 0;
unsigned int i,j;

for(i= 0;i<n-m;i++)
{

	j=0;
	while(j<m && P[j] == T[i+j])
	{
		opcount++;
		j++;
	}
	if(j==m)return i;
}

return -1;
}



int main() {
char *T;
char *P;
int i,n = 5;
for (int j=0; j < 4; j++) 
{
T = (char *)malloc(sizeof(char)*n);
P = (char *)malloc(sizeof(char)*n);
for (int k=0; k< n; k++)
T[k] = (char)65+k; 
for(int k=0; k<n-3;k++)
P[k] = (char)65+3+k;


printf("\nElements are :");
for(i=0;i<n;i++)
printf("%c",T[i]);
printf("\n");

printf("\nSearching for :");
for(i=0;i<n-1;i++)
printf("%c",P[i]);
printf("\n");

printf("Match: %d",StringMatch(T,n,P,(n-3)));

printf("Opcount %d",opcount);

free(T);
free(P);
n = n + 5; 
}
return 0;
}

#include<stdio.h>
#include<stdlib.h>


void BubbleSort(int *a, unsigned int n)
{
unsigned int i,j;
int temp,opcount=0,swapcount=0;

for(i= 0;i<n-1;i++)
{

for(j=0;j<n-i-1;j++)
{
++opcount;
if(a[j]>a[j+1])
{
++swapcount;
temp = a[j];
a[j] = a[j+1];
a[j+1]=temp;
}

}
}
printf("\nOperation Count %d\n",opcount);
printf("\nSwap Count %d\n",swapcount);
printf("\nTotal %d\n",opcount+swapcount);
}



int main() {
int *a;
int i,n = 5;
// generate worst case input of different input size
for (int j=0; j < 4; j++) // repeat experiment for 4 trials
{
a = (int *)malloc(sizeof(int)*n);
for (int k=0; k< n; k++)
a[k] = k+1; // descending order list
printf("Elements are ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
BubbleSort(a,n);
printf("Elements after bubble sort ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
free(a);
n = n + 5; // try with a new input size
}
return 0;
}

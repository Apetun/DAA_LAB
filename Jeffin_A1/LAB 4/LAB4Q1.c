#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define p 4
int *v ;
int mat[p][p];
int res[p];
int sum = INT_MAX;

void print(const int *v, const int size)
{  
    int ctr= 0;
  if (v != 0) {
    for (int i = 0; i < size; i++) {   
      ctr+=mat[i][v[i]-1];
    }

    if(ctr<=sum)
    {
        sum=ctr;
         for (int i = 0; i < size; i++) {   
     res[i]=mat[i][v[i]-1];
        }   
    }
  }

}


void swap(int *v, const int i, const int j)
{
  int t;
  t = v[i];
  v[i] = v[j];
  v[j] = t;
}


void rotateLeft(int *v, const int start, const int n)
{
  int tmp = v[start];
  for (int i = start; i < n-1; i++) {
    v[i] = v[i+1];
  }
  v[n-1] = tmp;
} 


void permute(int *v, const int start, const int n)
{
  print(v, n);
  if (start < n) {
    int i, j;
    for (i = n-2; i >= start; i--) {
      for (j = i + 1; j < n; j++) {
    swap(v, i, j);
    permute(v, i+1, n);
      } 
      rotateLeft(v, i, n);
    } 
  }
} 


void init(int *v, int N)
{
  for (int i = 0; i < N; i++) {
    v[i] = i+1;
  }
} 




int main()
{   
    
    int *v = (int*) malloc(p*sizeof(int));

    init(v, p);

    for (int i = 0; i < p ; i++) {
        for (int j = 0 ; j < p ; j++) {
            scanf("%d",&mat[i][j]);
        }
    }


    printf("\nThe matrix is:\n");
    for (int i = 0; i < p ; i++) {
        for (int j = 0 ; j < p ; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    permute(v, 0, p);
    printf("The solution is: \n");
    for(int i=0;i<p;i++)
    {
        printf("%d ",res[i]);
    }
    printf("\nThe minimum cost is %d\n", sum);

}

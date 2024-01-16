
#include <stdio.h>
#include <math.h>
#define MAX 100

int a[MAX],b[MAX],res[MAX];
int opcount=0;



int isPrime(int n)
{	
	int ctr=0;
	for(int i = 2; i<=pow(n,0.5);i++)
	{
		opcount++;
		if(n%i==0)
		{
			ctr++;
		}
	}
	if (ctr==2)
	{
		return 1;
	}
	else 
		return 0;

}


void primefactors(int n, int a[])
{
	int i= 2,j=0;
	while(i<=n)
	{
		if(isPrime(i))
		{
			opcount++;
			if(n%i==0)
			{
				a[j++]=i;
			}
			else
				i++;
		}
		else
			i++;
	}



	a[j]=-1;
}




void intersection(int a[],int b[])
{
	int * ptr1= a;
	int * ptr2= b;
	int j=0;
	while(*ptr1!=-1&&*ptr2!=-1)
	{
		if(*ptr1==*ptr2)
		{
			res[j++]=*ptr1;
			ptr1++;
			ptr2++;
		}
		else
		{
			*ptr1>*ptr2?*ptr2++:*ptr1++;
		}
	}

	res[j]=-1;
}





int GCD(int m, int n) {
primefactors(m,a);
primefactors(n,b);
intersection(a,b);

int j=0;
int gcd=1;

while(res[j]!=-1)
{
	gcd*=res[j];
}

return gcd;
}
int main() {
	int m,n;
	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("sum of numbers = %d\n",m+n);
	printf("GCD of two numbers %d and %d using Consecutive Integer method is %d \n",
	m,n,GCD(m,n));
	return 0;
}
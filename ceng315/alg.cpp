#include "stdio.h"
#include "math.h"

//Determine the number of print statements that will be executed for the following functions
// That corresponds to the complexities of these functions
// Determine the complexities in terms of the input parameter value (not input size); i.e., in terms of n

// Same output with g,  linear complexity

void f( int n)
{ 
	int m,i,j;
	m=2*n; i=0;
	while (m>0)
	{
		m=m/2; i++;
		for (j=1;j<=m;j++)
 			printf("%d %d\n",i,j);
   }

}

// Same output with f, exponential complexity

void g(int n)
{ 
	int m,i,j;
	m=pow(2,n+1); 
	for (i=0;i<=n;i++)
	{
		m=m/2; 
		for (j=1;j<=m;j++)
 			printf("%d %d\n",i+1,j);
   }

}

// Different one

void h(int n)
{ 
	int m,i,j;
	m=log2(n); 
	for (j=1;j<=m;j++)
	{
		for (i=1;i<=n;i++)
 			printf("%d %d\n",i,j);
 		n=n-2;
   }

}


main()
{
	int n;
	scanf("%d",&n); //8
	f(n);
	scanf("%d",&n); //3
	g(n);
	scanf("%d",&n); //8
	h(n);		
	scanf("%d",&n);
}

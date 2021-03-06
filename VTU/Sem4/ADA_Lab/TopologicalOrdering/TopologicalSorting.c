/******************************************************************************
*File		: TopologicalSorting.c
*Description	: Program to find Topological ordering of nodes in a DAG 
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: 11 Nov 2013
******************************************************************************/
#include <stdio.h>

const int MAX = 10;
void fnTopological(int a[MAX][MAX], int n);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int a[MAX][MAX],n;
	int i,j;

	printf("Topological Sorting Algorithm -\n");
	printf("\nEnter the number of vertices : ");
	scanf("%d",&n);

	printf("Enter the adjacency matrix -\n");
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			scanf("%d",&a[i][j]);

	fnTopological(a,n);
	printf("\n");
	return 0;
}
/******************************************************************************
*Function	: fnTopological
*Description	: Function to find Topological ordering of nodes in a DAG 
*Input parameters:
*	int a[MAX][MAX] - adjacency matrix of the input graph
*	int n	- no of vertices in the graph
*RETURNS	: no value
******************************************************************************/

void fnTopological(int a[MAX][MAX], int n)
{
	int in[MAX], out[MAX], stack[MAX], top=-1;
	int i,j,k=0;

	for (i=0;i<n;i++)
	{
		in[i] = 0;
		for (j=0; j<n; j++)
			if (a[j][i] == 1)
				in[i]++;
	}

	while(1)
	{
		for (i=0;i<n;i++)
		{
			if (in[i] == 0)
			{
				stack[++top] = i;
				in[i] = -1;
			}
		}

		if (top == -1)
			break;

		out[k] = stack[top--];

		for (i=0;i<n;i++)
		{
			if (a[out[k]][i] == 1)
				in[i]--;
		}
		k++;
	}

	printf("Topological Sorting (JOB SEQUENCE) is:- \n");
	for (i=0;i<k;i++)
		printf("%d ",out[i] + 1);
}

/******************************************************************************
Input Graph : 5 vertices
    0 0 1 0 0
    0 0 1 0 0
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0
    
Topological Sorting (JOB SEQUENCE) is:- 
2 1 3 4 5 
    
******************************************************************************/

 //copy paste       //not all inputs get output
 
 #include<stdio.h>
 #include<stdlib.h>
 #define MAX 10
 
 void fnTopological(int graph[MAX][MAX], int n)
 {
    int in[MAX], out[MAX], stack[MAX], top=-1;
    int i,j,k=0;
    for (i=0;i<n;i++)
    {
         in[i] = 0;
         for (j=0; j<n; j++)
             if (graph[j][i] == 1)
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
        for(i=0;i<n;i++)
        {
         if (graph[out[k]][i] == 1)
             in[i]--;
         }
         k++;
     }
     printf("Topological Sorting (JOB SEQUENCE) is:- \n");
     for (i=0;i<k;i++)
         printf("%d\t", out[i] + 1);
     printf("\n");
 }

 int main( int argc, char **argv)
 {
     int graph[MAX][MAX],n;
     int i,j;
     printf("Topological Sorting Algorithm -\n");
     printf("\nEnter the number of vertices : ");
     scanf("%d",&n);
     printf("Enter the adjacency matrix -\n");
     for (i=0; i<n; i++)
         for (j=0; j<n; j++)
             scanf("%d",&graph[i][j]);
     fnTopological(graph,n);
     printf("\n");
     return 0;
 }

/*************
      OUTPUT
2
3 Enter the number of vertices : 5
4 Enter the adjacency matrix -
5
6 0 0 1 0 0
7 0 0 1 0 0
8 0 0 0 1 1
9 0 0 0 0 1
10 0 0 0 0 0
11
12 Topological Sorting (JOB SEQUENCE) is:-
13 2 1 3 4 5
14
15 *************/

/*****************************************

//ISE //logical error

#include<stdio.h>
int temp[10],k=0;
void topo(int n,int in[10],int a[10][10])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(in[i]==0)
        {
            in[i]=1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
                if(a[i][j]==1&&in[j]!=1)
                    in[j]--;
            i=0;
        }
    }    
}
void main()
{
    int i,j,n,in[10],a[10][10];
    printf("Enter no of vertices : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        in[i]=0;
    printf("\nEnter adjacency matrix :\n");
    for (i=0; i<n; i++)
         for (j=0; j<n; j++)
         {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                in[j]++;  
         }
         topo(n,in,a);
         if(k!=n)
            printf("\ntoptological sorting is not possible\n");       //for all
         else
         {
            printf("\ntopological ordering\n");            //if u comment if block, output is few o's
            for(i=0;i<k;i++)
                printf(" %d ",temp[i]);  
         }   
}
*/

//***5.a)  DFS Traversal***

#include<stdio.h>
#include<stdlib.h>

int count=0,n;

void dfs(int a[n][n],int start,int visited[])
{
    int i;
    visited[start]=++count;
    for(i=0; i<n; i++)
    {
        if( a[start][i]==1 && visited[i]==0 )
            dfs(a,i,visited);
    }
}

int main()
{
    int i,j;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);

    int a[n][n];
    printf("\nEnter the %d elements into matrix : \n",n*n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    int visited[n];
    for(i=0; i<n; i++)
        visited[i]=0;

    int start;
    printf("\nEnter the Starting vertex : ");
    scanf("%d",&start);

    dfs(a,start-1,visited);

    for(i=0; i<n; i++)
    {
        if(visited[i]!=0)
            printf("\n vertex %d is reachable from %d\n",i+1,start);
        else
            printf("\n vertex %d is not reachable from %d\n",i+1,start);
    }
    return 0;
}

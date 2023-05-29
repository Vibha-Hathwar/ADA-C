#include<stdio.h>
#include<stdlib.h>
#define max 100
void dfs(int c,int v[max],int g[max][max],int n)
{
    int i;
    v[c]=1;
    for(i=0;i<n;i++)
        if(g[c][i]==1&&v[i]==0)
            dfs(i,v,g,n);
}
int main()
{
    int i,j,k;
    int visited[max],graph[max][max],num,ver;
    printf("Enter no of vertices : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
        visited[i]=0;
    printf("Enter adjacency matrix :\n");
    for(i=0;i<num;i++)
        for(j=0;j<num;j++)
            scanf("%d",&graph[i][j]);
    printf("Enter source vertex : ");
    scanf("%d",&ver);
    dfs(ver,visited,graph,num);
    for(k=0;k<num;k++)
    {
        if(visited[k])
            printf("vertex %d is reachable\n",k+1);
        else
            printf("vertex %d is NOT reachable\n",k+1);
    }
    return 0;
}

/*
ISE 

#include<stdio.h>
int g[10][10],visit[10],n;
//void g[10][10],visit[10],n;
void main()
{
    int i,j;
    printf("Enter no of vertices : ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);
        for(i=0;i<n;i++)
            visit[i]=0;
    }
    dfs(0);
}
void dfs(int i)
{
    int j;
    printf(" %d ",i+1);
    visit[i]=1;
    for(j=0;j<n;j++)
    if(!visit[j]&&g[i][j]==1)
    dfs(j);
}
*/

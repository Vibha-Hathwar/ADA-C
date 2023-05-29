#include<stdio.h>
int main()
{
    int cost[10][10],visited[10]={0},i,j,n,m=1,min,a,b,min_cost=0;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    printf("Enter cost in form of adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
              cost[i][j]=1000;
        }
    }
    visited[1]=1;.                                                                               
    while(m<n)
    {
        min=1000;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(visited[b]==0)
        {
            printf("\n%d to %d  cost=%d",a,b,min);
            min_cost=min_cost+min;
            m++;
        }
        visited[b]=1;
        cost[a][b]=cost[b][a]=1000; 
    }
    printf("\n\nminimum weight is %d\n",min_cost);
    return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,m,n,i,j;
int ne=1,mincost=0,visited[10]={0},cost[10][10];
int main()
{
    printf("\nEnter no of verticies : ");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    visited[1]=1;
    while(ne<n)
    {
        for(i=1;i<99;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<m)
                    if(visited[i]!=0)
                    {
                        m=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                    if(visited[u]==0||visited[v]==0)
                    {
                        printf("Edge %d(%d,%d) -> cost %d\n",ne+1,a,b,m);
                        mincost+=m;visited[b]=1;
                    }
        cost[a][b]=cost[b][a]=99;
    }
    printf("\nminimunm cost %d\n",mincost);
    return 0;
}*/

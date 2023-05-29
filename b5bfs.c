#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],vi[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
    for(i=0;i<n;i++)
        if(a[v][i]&&!vi[i])
            q[++r]=i;
    if(f<=r)
    {
        vi[q[f]]=1;
        bfs(q[f++]);
    }
}
int main()
{
    int v;
    printf("\nEnter no of vertices : ");
    scanf("%d",&n);
     printf("Enter adjacency matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter source vertex : ");
    scanf("%d",&v);
    for(i=0;i<n;i++)
    {
        q[i]=0;
        vi[i]=0;
    }
    bfs(v);
    for(i=0;i<n;i++)
    {
        if(vi[i])
          printf("vertex %d is reachable\n",i+1);//printf(" %d ",i+1);
        else
            printf("\nvertex %d is NOT reachable\n",i+1);
    }
    return 0;
}

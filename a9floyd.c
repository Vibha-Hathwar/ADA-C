#include<stdio.h>
#define max 100                  //ERRRORRRRRRR      //whenever input is infinity
void floyd(int g[max][max],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(g[i][j]>g[i][k]+g[k][j])
                    g[i][j]=g[i][k]+g[k][j];           
}
int main()
{
    int i,j,n,graph[max][max];
    printf("enter no of verticies : ");
    scanf("%d",&n);
    printf("enter weight matrix (cost adjaccency) matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    floyd(graph,n);
     printf("All pair shortest path of given graph is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("  %d",graph[i][j]);
        printf("\n");
     }
    return 0;
}

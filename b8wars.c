#include<stdio.h>
#define max 100
void warshall(int graph[max][max],int n)
{
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(graph[i][j]||(graph[i][k]&&graph[k][j]))
                    graph[i][j]=1;
}
int main()
{
    int i,j,n,graph[max][max];
    printf("enter no of verticies : ");
    scanf("%d",&n);
    printf("enter adjaccency matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    warshall(graph,n);
    printf("Transitive closure of given graph is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d  ",graph[i][j]);
        printf("\n");
    }
    return 0;
}

//***5.b)  BFS Traversal*** 

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int count,n;

typedef struct queue
{
    int item[MAX];
    int f,r;
}QUEUE;

QUEUE q;

int isempty(QUEUE q)
{
    if(q.f==-1)
        return 1;
    return 0;
}

void PUSH(QUEUE *q,int data)
{
    q->item[++q->r]=data;
    if(q->f==-1)
        q->f=0;
}

int POP(QUEUE *q)
{
    int data=q->item[q->f];
    if(q->f==q->r)
        q->f=q->r=-1;
    else
        q->f++;
    return data;
}

void bfs(int a[n][n],int start,int visited[])
{
    int i,first_vertex;
    visited[start]=++count;
    PUSH(&q,start);
    while(!isempty(q))
    {
        first_vertex=POP(&q);
        for(i=0; i<n; i++)
        {
            if( a[first_vertex][i]==1 && visited[i]==0 )
            {
                visited[i]=++count;
                PUSH(&q,i);
            }
        }
    }
}

int main()
{
    int i,j;
    q.f=q.r=-1;
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

    bfs(a,start-1,visited);

    for(i=0; i<n; i++)
    {
        if(visited[i]!=0)
            printf("\n vertex %d is reachable from %d\n",i+1,start);
        else
            printf("\n vertex %d is not reachable from %d\n",i+1,start);
    }
    return 0;
}

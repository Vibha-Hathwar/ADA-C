#include<stdio.h>
#include<stdlib.h>
int visited[10],d[10],cost[10][10],j,n,v;
int choose()
{                                               //works
    int m=9999,w;
    for(j=0;j<n;j++)
        if(d[j]<m&&!visited[j])
        {
            m=d[j];
            w=j;    
        }
    return w;
}
void jikstra()
{
    int i,j,u;
    printf("\nEnter source vertex : ");
    scanf("%d",&v);
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        d[i]=cost[v][i];
    }
    visited[v]=1;
    d[v]=0;
    i=2;
    while(i<n)
    {
        int w;
        u=choose();
        visited[u]=1;
        i++;
        for(w=0;w<n;w++)
            if((d[u]+cost[u][w])<d[w]&&!visited[w])
                d[w]=d[u]+cost[u][w];
    }
}
int main()
{
    int i,j;
    printf("Eter no of nodes ");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    jikstra();
    printf("\n");
    for(i=0;i<n;i++)
        if(i!=v)
            printf("(%d,%d) = %d\n",v,i,d[i]);
    return 0;
}


/*****************_*******************_********************_****************_***************/

/*
#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijikstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1)
	{
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
		  printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}
void main(){
	int G[MAX][MAX], i, j, n, u;
	//clrscr();
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	dijikstra(G,n,u);
	printf("\n");
	//getch();
}

/**************_********************_********************_*****************_***************** /


#include<stdio.h>
#include<stdlib.h>                               //error
const int max=10,inf=9999;
void jikstra(int c[max][max],int d[max],int p[max],int s[max],int so,int de,int n)
{
    int i,j,a,b,min;
    for(i=0;i<n;i++)
    {
        s[i]=0;
        d[i]=c[so][i];
        p[i]=so;
    }
    s[so]=1;
    for(i=1;i<n;i++)
    {
        min=inf;
        a=-1;
        for(j=0;j<n;j++)
           if(s[j]==0)
                if(d[j]<min)
                {
                    min=d[j];
                    a=j;
                }
        if(a==-1)return;
        s[a]=1;
        if(a==de)return;
        for(b=0;b<n;b++)
            if(s[b]==0)
                if(d[a]+c[a][b]<d[b])
                {
                    d[b]=d[a]+c[a][b];
                    p[b]=a;
                }
}}
int main()
{
    int n,cost[max][max],dist[max][max],visited[max],path[max],i,j,source,destin;
    printf("Eter no of nodes ");
    scanf("%d",&n);
    printf("Enter cost matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    for(source=0;source<n;source++)
    {
        printf("Source vertex %d\n",source);
        for(destin=0;destin<n;destin++)
        {
            if(jikstra(cost,dist,path,visited,source,destin,n);
                if(dist[destin]==inf)
                    printf("Not Reachable\n");
                else
                {
                    printf("\n");
                    i=destin;
                    do
                    {
                        printf("%d -- ",i);
                        i=path[i];
                    }
                    while(i!=source);
                }
        }
    }
    return 0;
}
                         */

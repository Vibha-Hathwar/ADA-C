//***4.a) Topological Order - Using Source Removal Method***//

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct stack
{
    int items[MAX];
    int top;
}STACK;

int isempty(STACK s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

void PUSH(STACK *s,int data)
{
    s->items[++s->top]=data;
}

int POP(STACK *s)
{
    return s->items[s->top--];
}

void indegree(int a[MAX][MAX],int vtx,int indg[])
{
     int i,j,k;
     for(i=0;i<vtx;i++)
     {
        k=0;
        for(j=0;j<vtx;j++)
           if(a[j][i]==1)
              k++;
        indg[i]=k;
     }
}

int main()
{
    int i,j,vtx;
    STACK s;
    s.top=-1;

    printf("\nEnter the number of vertex : ");
    scanf("%d",&vtx);

    int a[vtx][vtx];//int a[MAX][MAX];
    printf("\nEnter the %d elements into matrix : \n",vtx*vtx);
    for(i=0;i<vtx;i++)
        for(j=0;j<vtx;j++)
            scanf("%d",&a[i][j]);

    int indg[vtx],popoff[vtx],k=0;

    indegree(a,vtx,indg);

    for(i=0;i<vtx;i++)
        if(indg[i]==0)
            PUSH(&s,i);

    while(!isempty(s))
    {
        int v=POP(&s);
        popoff[k++]=v;
        for(i=0;i<vtx;i++)
        {
            if(a[v][i]==1)
            {
                indg[i]--;
                if(indg[i]==0)
                    PUSH(&s,i);
            }
        }
    }

    printf("\nTopological Order : ");
    for(i=0;i<vtx;i++)
        printf("%5d",popoff[i]+1);
    printf("\n");
    return 0;
}

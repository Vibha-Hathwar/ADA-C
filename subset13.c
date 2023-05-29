/*#include <stdio.h>                         //works
#define MAX 100
int stk[MAX], set[MAX];
int size, top = -1, count = 0;

int Subset(int pos, int sum)
{
    int i;
    static int foundSoln = 0;
    if (sum>0)
    {
        for (i=pos; i<=size; i++)
        {
            stk[++top]=set[i];//push(set[i]);
            Subset(i+1, sum - set[i]);
            top--;//pop();
        }
     }
    if (sum == 0)
    {
        printf("\nSolution #%d \t{ ",++count);
        for (i=0; i<=top; i++)
            printf("%d ",stk[i]);
        printf("}\n");
        foundSoln = 1;
    }
    return foundSoln;
}
int main(void)
{
    int i,sum;
    printf("Enter the number of elements : ");
    scanf("%d",&size);
    printf("Enter elements : \n");
    for (i=1; i<=size; i++)
        scanf("%d",&set[i]);
    printf("Enter required total : ");
    scanf("%d",&sum);
    if (!Subset(1, sum))
        printf("\nThe given problem instance has NO solution.\n");
    return 0;
}

/*******************************************************************************************/

#include<stdio.h>
int sum=0,n,i,d,c=0;
int set[20],a[20];                           //works for successful
void check()
{
    if(c==0)
        printf("\nNot possible\n");
}
void sm(int s,int k,int r)
{
    a[k]=1;
    if(s+set[k]==d)
    {
        printf("subset (");
        for(i=0;i<=k;i++)
            if(a[i]==1)
            {
                printf(" %d",set[i]);
                c=1;
            }
        printf(" ) \n");
    }
    else if(s+set[k]+set[k+1]<=d)
        sm(s+set[k],k+1,r-set[k]);
    if((r+s-set[k]>=d)&&(s+set[k+1]<=d))
    {
        a[k]=0;
        sm(s,k+1,r-set[k]);
    }
    
}
int main()
{
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter elements : \n");
    for (i=0;i<n; i++)
    {
        scanf("%d",&set[i]);
        sum=sum+set[i];
        a[i]=0;
    }
    printf("Enter required total : ");
    scanf("%d",&d);
    sm(0,0,sum);
    check();
    return 0;
}

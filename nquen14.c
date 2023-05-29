#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
int board[10][10], flag=0;
int posible(int row,int col,int n)
{   
    int i,j;
    for(i=row-1;i>=0;i--)
        if(board[i][col]==1)                //works
            return 0;
    for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        if(board[i][j]==1)
            return 0;
    for(i=row-1,j=col+1;i>=0&&j<n;i--,j++)    
        if(board[i][j]==1)
            return 0;
    return 1;
}
void place(int n,int row)
{
    int i,j;
    if(row==n)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]==0)
                    printf("# ");
                else
                    printf("Q ");
            }
            printf("\n");
        }
        printf("\n");
    }
    for(j=0;j<n;j++)
        if(posible(row,j,n))
        {
            board[row][j]=1;
            place(n,row+1);
            board[row][j]=0;;
        }
}
int main()
{
    int n,row[10];
    printf("Enter no of queens ");
    scanf("%d",&n);
    printf("\n");
    place(n,0);
    if(flag==0)
        printf("no soln\n");
    return 0;
}

/**************************************************************************************
                 *********************************************
                 *********************************************
*************************************************************************************/

#include<stdio.h>
#include<stdlib.h>                           // works 
#include<stdbool.h>
const int max = 10;
int soln=0;
void chess(int n,int row[max])
{
    printf("solution %d\n",soln+1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
              if(j==row[i])
                printf("Q ");
            else
                printf("# ");
        }
         printf("\n");
       }
       printf("\n");
}
bool check(int k,int col,int row[max])
{
    for(int i=0;i<k;i++)
        if(row[i]==col||abs(row[i]-col)==abs(i-k))
            return false;
        return true;
}
int nq(int k,int n,int row[max])
{
    bool checkp;
    static int flag;
    for(int i=0;i<n;i++)
    {
        if(check(k,i,row)==true)
        {   row[k]=i;
            if(k==n-1)
            {
                chess(n,row);
                soln++;
                flag=1;
                return flag;
            }
            nq(k+1,n,row);
        }
    }
    return flag;
}
int main()
{
    int n,row[max];
    printf("Enter no of queens ");
    scanf("%d",&n);
    if(!nq(0,n,row))
        printf("no soln\n");
    else
        printf("no of soln = %d\n",soln);
    return 0;
}//*/

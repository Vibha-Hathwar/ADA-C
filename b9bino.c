/*#include <stdio.h>                  //anusha b naik
const int MAXSIZE = 10;               // run agutte  //table display agutte
int fnBinomialCoefficient(int n, int k)
{
    int c[MAXSIZE][MAXSIZE], i,j;
    for (i=0; i<=n; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (i=1; i<=n; i++)
        for (j=1; j<i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    printf( "\nThe Binomial matrix is:\n\t");
    /*for (i=0; i<=k; i++)
        printf("%d\t",i);
    printf("\n");
    for (i=0; i<=k+1; i++)
        printf("\n");
     * /for (i=0; i<=n; i++)
    {
        int m=(i<k)?i:k; 
        for (j=0; j<=m; j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return c[n][k];
}
int main(void)
{
    int n, k;
    printf("Binomial Coefficients\n");
    printf( "Enter the value of n : ");
    scanf("%d",&n);
    printf( "Enter the value of k : ");
    scanf("%d",&k);
    if (n<k)
        printf( "\nInvalid Input n should be larger than k!\n");
    else
        printf( "\nThe value of %dC%d is %d\n\n",n,k,fnBinomialCoefficient(n, k) );
return 0;
}
*/

#include<stdio.h>

int bino(int n ,int r)
{
    int c[n+1][r+1],i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            if(j==0||j==i)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1]+c[i-1][j];
    return c[n][r];
}

int main()
{
    int n,r;
    printf("enter values of n and r : ");
    scanf("%d%d",&n,&r);
    if(n<r)
        printf("Invalid input\n");
    else
        printf("\nnCr = %dC%d = %d\n",n,r,bino(n,r));
    return 0;
}

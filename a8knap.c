/*#include<stdio.h>

 int w[10],p[10],v[10][10],n,i,j,cap,x[10]= {0};
 int max(int i,int j)
 {
    return ((i>j)?i:j);
 }
 int knap(int i,int j)
 {
    int value;
    if(v[i][j]<0)
    {
       if(j<w[i])
         value=knap(i-1,j);
       else
        value=max(knap(i-1,j),p[i]+knap(i-1,j-w[i]));
      v[i][j]=value;
   }
   return(v[i][j]);
}

   void main()
   {
      int profit,count=0;
      printf("\nEnter the number of elements\n");
      scanf("%d",&n);
      printf("Enter the profit and weights of the elements\n");
      for (i=1;i<=n;i++)
      {
         printf("For item no %d\n",i);
         scanf("%d%d",&p[i],&w[i]);
      }
      printf("\nEnter the capacity \n");
      scanf("%d",&cap);
      for (i=0;i<=n;i++)
       for (j=0;j<=cap;j++)
        if((i==0)||(j==0))
         v[i][j]=0; else
         v[i][j]=-1;
      profit=knap(n,cap);
      i=n;
      j=cap;
      while(j!=0&&i!=0)
      {
         if(v[i][j]!=v[i-1][j])
         {
            x[i]=1;
            j=j-w[i];
            i--;
         } else
           i--;
      }
      printf("Items included are\n");
      printf("Sl.no\tweight\tprofit\n");
      for (i=1;i<=n;i++)
       if(x[i])
        printf("%d\t%d\t%d\n",++count,w[i],p[i]);
      printf("Total profit = %d\n",profit);
      
}*/
#include<stdio.h>                      //sneha
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knap(int w,int wt[],int val[],int n)
{
    int i,j,k[n+1][w+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=w;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            else if(wt[i-1]<=j)
                k[i][j]=max(k[i-1][j],(val[i-1]+k[i-1][j-wt[i-1]]));
            else
                k[i][j]=k[i-1][j];
        }
return k[n][w];
}
int main()
{
    int i,n,w;
    printf("enter no of objects : ");
    scanf("%d",&n);
    int val[n],wt[n];
    printf("\nenter weights : ");
    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);
    printf("\nenter values : ");
    for(i=0;i<n;i++)
        scanf("%d",&val[i]);
    printf("\nenter max capacity : ");
    scanf("%d",&w);
    int num=sizeof(val)/sizeof(val[0]);
    printf("\ntotal profit earned : %d\n\n",knap(w,wt,val,num));
    return 0;
}

/*               //anusha b naik
int knap(int i,int m)
{
    if(i==n)
        return(wt[n]>m)?0:val[n];
    if(wt[i]>m)
        return knap(i+1,m);
    return max(knap(i+1,m),knap((i+1,m-wt[i]+val[i]);
}
int main()
{
    int i,n,c;
    printf("enter no of objects : ");
    scanf("%d",&n);
    int v[n],w[n];
    printf("enter weight : ");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    printf("enter values : ");
    for(i=0;i<n;i++)
        scanf("%d",&v[i]);
    printf("enter max capacity : ");
    scanf("%d",&c);
    printf("total profit earned : %d\n",knap(1,c));
    return 0;
}*/

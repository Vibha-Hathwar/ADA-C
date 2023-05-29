#include<stdio.h>
#include<stdlib.h>
void maxMin(int a[],int l,int h,int *mx,int *mn)
{
    int m,max1,max2,min1,min2;
    if(h-l==1)
    {
        if(a[l]>a[h])
        {
            *mx=a[l];
            *mn=a[h];
        }
        else
        {
            *mx=a[h];
            *mn=a[l];
        }
    }
    else if(l==h)
        *mx=*mn=a[l];
    else if(l<h)
    {
        m=(l+h)/2;
        maxMin(a,l,m,&max1,&min1);
        maxMin(a,m+1,h,&max2,&min2);
        if(max1>max2)
            *mx=max1;
        else
            *mx=max2;
        if(min1<min2)
            *mn=min1;
        else
            *mn=min2;
    }
}
int main()
{
    int n,i;
    int max=0,min=0;
    printf("Enter array size ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    maxMin(a,0,n-1,&max,&min);
    printf("Max element = %d\nMin element = %d\n",max,min);
    return 0;
}

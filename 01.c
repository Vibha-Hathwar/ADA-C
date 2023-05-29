#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,key,res;
    printf("Enter n  ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements  ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("array elements are : ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\nenter Key to search  ");
    scanf("%d",&key);
    res = sch(a,0,n-1,key);
    if(res<0)
        printf("\nFailure ! key %d not found\n",key);
    else
        printf("\nkey %d is found at position %d\n",key,res);       
}

int sch(int a[],int low,int high,int key)
{
    int mid;
    if(low>high)
        return -1;
    mid=(low+high)/2;
    if(key==a[mid])
        return mid+1;
    if(key<a[mid])
        return(sch(a,low,mid-1,key));
    return(sch(a,mid+1,high,key));
}

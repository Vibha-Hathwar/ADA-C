#include<stdio.h>       //insertion sort
#include<stdlib.h>
#include<time.h>

void insertsort(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void genRan(int a[],int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
        a[i]=rand()%10000;
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%5d\n",a[i]);
}
int main()
{
    int i,n,a[500000];
    printf("\nInsertion sort\n");
                    printf("\nEnter size of array ");
                   scanf("%d",&n);
                   genRan(a,n); 
                  /*
                   printf("Enter array elements : ");
                   for(i=0;i<n;i++)
                      scanf("%d",&a[i]);
                   */
                   printf("Array BEFORE sorting\n"); 
                   display(a,n); 
                   insertsort(a,n); 
                   printf("Array AFTER sorting\n");
                   display(a,n); 
                   return 0;
}



/*************************************************************************************************/




//**4.b)  InsertionSort**

#include <stdio.h>
#include <stdlib.h>

void insertionsort(int a[],int n)
{
    int i,j,v;
    for(i=1; i<n; i++)
    {
        v=a[i];
        j=i-1;

        while(j>=0 && a[j]>v)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=v;
    }
}

int main()
{
    int i,k=0,n,a[5000],ch=1,s,key;
    printf("\n Enter the size of array : ");
    scanf("%d",&n);

    printf("\n Enter the %d elements into the array : ",n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("\n Array elements Before Sorting : ");
    for(i=0; i<n; i++)
        printf("%5d",a[i]);

    insertionsort(a,n);

    printf("\n Array elements After sorting  : ");
    for(i=0; i<n; i++)
        printf("%5d",a[i]);
    return 0;
}

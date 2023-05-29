#include<stdio.h>
#include<stdlib.h>
void selectionSort(int a[],int n)
{
    for (int i=0;i<n;i++)
		{
			int idx=i;
			for (int j=i+1;j<n;j++)
			{
				if (a[j]<a[idx])
				{
					idx=j;
				}
			}
			int temp=a[i];
			a[i]=a[idx];
			a[idx]=temp;
		}
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int i,n;
    printf("Enter n : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Array BEFORE sorting\n"); 
    display(a,n); 
    selectionSort(a,n); 
    printf("Array AFTER sorting\n");
    display(a,n); 
    return 0;
}

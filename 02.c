/*read n integer elements into an array and perform binary search*/

#include<stdio.h>
int main()
{
  int n,key,i,low,mid,high;
  printf("enter n : ");
  scanf("%d",&n);
  int a[n];
  printf("\nenter %d elements : \n",n);
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  printf("\nentered array elements are : ");
  for(i=0;i<n;i++)
     printf("%d\t",a[i]);
  printf("\n");
  printf("\nenter key element to search : ");
  scanf("%d",&key);
  low=0;
  high=n-1;
  while(low<=high)
  {
    mid=(low+high)/2;
    if(key==a[mid])
      {
       printf("\nSUCESS key %d is found at position %d\n",key,mid+1);
       break;
      }
    else if(key<a[mid])
       high=mid-1;
    else
       low=mid+1;       
  }
  if(low>high)
        printf("\nkey %d is NOT found\n",key);
}

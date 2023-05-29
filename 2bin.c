#include<stdio.h>           //binary search
int bins(int a[],int key,int low,int high)
{
	int mid;
	if(low<=high)
	{
	  mid=(low+high)/2;
	  if(key==a[mid])
	      return mid;
	  else if(key<a[mid])
	      return bins(a,key,low,mid-1);
	  else
	      return bins(a,key,mid+1,high);
	}
	else
	   return -1;
}
int main()
{
	int a[20],n,key,i,j,p=0,temp;
	printf("enter size of array ");
	scanf("%d",&n);
	printf("\nEnter array elements\n");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	/*printf("array elments are\t");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);*/
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n-1-i;j++)
	   {
	     if(a[j]>a[j+1])
	     {
	       temp=a[j];
	       a[j]=a[j+1];
	       a[j+1]=temp;
	     }
	   }
	}
	printf("\nArray elements in ascending order\t");
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
	printf("\nEnter key element ");
	scanf("%d",&key);
	p=bins(a,key,0,n-1);
	if(p==-1)
	    printf("\nElement not found\n");
	else
	    printf("\nelement found at position %d\n",p+1);
	return 0;
}

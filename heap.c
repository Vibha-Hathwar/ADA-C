#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void heapify(int a[],int i,int n)
{
    int l,r,largest,temp;
    l=2*i;
    r=(2*i)+1;
    if((l<=n)&&(a[l]>a[i]))
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r]>a[largest]))
       largest=r;
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,largest,n);
    }
}

void build(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
       heapify(a,i,n);
}

void heapSort(int a[],int n)
{ 
    int temp,i;
    build(a,n);
    for(i=n;i>=2;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapify(a,1,i-1);
    }
}
void genRan(int a[],int n)
{
    int i;
    srand(time(NULL));
    for(i=1;i<=n;i++)
        a[i]=rand()%10000;
}
void display(int a[],int n)
{
    int i;
    for(i=1;i<=n;i++)
        printf("%5d\n",a[i]);
}
int main()
{
    FILE *fp;
    struct timeval tv;
    double start,end;
    int i,n,a[500000],choice;
    while(1)
    {    
        printf("\n1 heapsort\n2 Plot graph\n3 Exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter size of array ");
                   scanf("%d",&n);
                   genRan(a,n);
                   printf("Array BEFORE sorting\n");
                   display(a,n);
                   heapSort(a,n);
                   printf("Array AFTER sorting\n");
                   display(a,n); 
                   break;
            case 2:fp=fopen("heap.dat","w");
                   for(i=100;i<100000;i+=100)
                   {
                       genRan(a,i);
                       gettimeofday(&tv,NULL);
                       start=tv.tv_sec+(tv.tv_usec/1000000.0);
                       heapSort(a,i);  
                       gettimeofday(&tv,NULL);
                       end=tv.tv_sec+(tv.tv_usec/1000000.0);
                       fprintf(fp,"%d\t%lf\n",i,end-start);
                   }
                   fclose(fp);
                   break;
            case 3:exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}

#include<stdio.h>           //quick Sort
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int part(int a[],int l,int r)    //partition
{
    int i,j,p;
    p=a[l];
    i=l;
    j=r+1;
    do
    {
        do
        {
             i++;
        }while(a[i]<p&&i<r);
         do
        {
             j--;
        }while(a[j]>p);
        swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

void quicksort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=part(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
}
void genRan(int a[],int n)       //generate_random_inputs
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
    FILE *fp;
    struct timeval tv;
    double start,end;
    int i,n,a[500000],choice;
    while(1)                 //for{;;}
    {    
        printf("\n1 Quicksort\n2 Plot graph\n3 Exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter size of array ");
                   scanf("%d",&n);
                   genRan(a,n);
                   printf("Array BEFORE sorting\n");
                   display(a,n);
                   quicksort(a,0,n-1);
                   printf("Array AFTER sorting\n");
                   display(a,n); 
                   break;
            case 2:fp=fopen("4quick.dat","w");
                   for(i=100;i<100000;i+=100)
                   {
                       genRan(a,i);
                       gettimeofday(&tv,NULL);
                       start=tv.tv_sec+(tv.tv_usec/1000000.0);
                       quicksort(a,0,i-1);  
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

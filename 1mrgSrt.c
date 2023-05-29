#include<stdio.h>       //merge sort
#include<stdlib.h>
#include<sys/time.h>
#include<time.h>

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,b[500000];
    i=k=low;
    j=mid+1;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=high)
        b[k++]=a[j++];
    for(i=low;i<k;i++)
        a[i]=b[i];
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
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
    FILE *fp;
    struct timeval tv;
    double start,end;
    int i,n,a[500000],choice;
    while(1)
    {    
        printf("\n1 Mergesort\n2 Plot graph\n3 Exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter size of array ");
                   scanf("%d",&n);
                   genRan(a,n);                                               //gedit 1mrgSrt.c
                   printf("Array BEFORE sorting\n");                          //gedit 1mrgSr.gpl
                   display(a,n);                                              //gcc 1mrgSrt.c
                   mergesort(a,0,n-1);                                        //./a.out
                   printf("Array AFTER sorting\n");                           //choice 1, 2, 3
                   display(a,n);                                              //(.dat file created) 
                   break;                                                     //either  //gnuplot 1mrgSr.gpl
            case 2:fp=fopen("mergesort.dat","w");                                       //mergesort.png
                   for(i=100;i<100000;i+=100)
                   {                                                            //or    //gnuplot
                       genRan(a,i);                                                     //plot "/mergesort.dat" with lines
                       gettimeofday(&tv,NULL);                                          //mergsort.png
                       start=tv.tv_sec+(tv.tv_usec/1000000.0);                          //lines symbol - liness
                       mergesort(a,0,i-1);                                              //export - save
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

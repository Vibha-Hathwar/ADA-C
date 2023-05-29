#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
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
    FILE *fp;
    struct timeval tv;
    double start,end;
    int i,n,a[500000],choice;
    while(1)
    {    
        printf("\n1 Insertsort\n2 Plot graph\n3 Exit\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter size of array ");
                   scanf("%d",&n);
                   genRan(a,n); 
                   printf("Array BEFORE sorting\n"); 
                   display(a,n); 
                   insertsort(a,n); 
                   printf("Array AFTER sorting\n");
                   display(a,n); 
                   break; 
            case 2:fp=fopen("5ins.dat","w"); 
                   for(i=100;i<100000;i+=100)
                   { 
                       genRan(a,i); 
                       gettimeofday(&tv,NULL); 
                       start=tv.tv_sec+(tv.tv_usec/1000000.0); 
                       insertsort(a,i); 
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

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

int t[max];

void shiftable(char p[])
{
    int m,i,j;
    m=strlen(p);
    for(i=0;i<max;i++)
        t[i]=m;
    for(j=0;j<m;j++)
        t[p[j]]=m+j;
} 
int horspool(char s[],char p[])
{
    int m,n,i,k;
    n=strlen(s);
    m=strlen(p);
    i=m-1;
    while(i<n)
    {
        k=0;
        while(k<m&&(p[m-1-k]==s[i-k]))
            k++;
        if(k==m)
            return i-m+1;
        else
            i=i+t[s[i]];
    }
    return -1;
}
int main()
{
    char text[max],pat[max],stable[max];
    int found;
    printf("Enter source string\n");
    scanf("%s[^\n]",text);//gets(text);
    printf("Enter pattern string\n");
    scanf("%s",pat);
    shiftable(pat);
    found=horspool(text,pat);
    if(found==-1)
        printf("\nmatching NOT found\n");
    else
        printf("\nmatching substring found at position %d\n",found+1);
    return 0;
}

*/
/***********************************************/
//copy paste doc by vin
                         //  SUCCESSFULL run
#include<stdio.h>        //horspool algorithm
#include<string.h>
const int MAX=256;

void genshifttable(char p[], int t[])
{
  int m,i,j;
  m=strlen(p);
  for(i=0; i<MAX;i++)
  {
   t[i]=m;
  }
  for(j=0;j<m-1;j++)
  {
    t[p[j]]= m-1-j;
  }
}

int horsepool(char s[], char p[], int t[])
{
 int i,n,m,k;
 n=strlen(s);
 m=strlen(p);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==s[i-k]))
      k++;
  if(k==m)
      return i-m+1;
  else
      i=i+t[s[i]];
 }
 return -1;
}

int main(void)
{
 char text[MAX];
 char pattern[MAX];
 int shifttable[MAX];
 int found;
 puts("Enter the source string:") ;
 scanf("%s",text);//gets(text);
 puts("Enter the pattern string:");
 scanf("%s",pattern);//gets(pattern);
 genshifttable(pattern, shifttable);
 found=horsepool(text,pattern,shifttable);
 if(found==-1)
   printf("\nMatching substring not found\n");
 else
   printf("\nMatching substring found at position: %d\n",found+1);
   
 return 0;
}


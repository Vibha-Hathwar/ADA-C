#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int count = 1;
int max (int x, int y);
void maxitems (int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]);
void Items (int n, int c, int t[MAX][MAX], int w[MAX], int l[MAX]);
void additem (FILE * fp);
void deleteitem (FILE * fp);
void displayitem (FILE * fp);
void selectitem (FILE * fp);
int max (int x, int y)
{
return x > y ? x : y;
}
void maxitems (int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX])
{
int i, j;
for (j = 0; j <= c; j++)
t[0][j] = 0;
for (i = 0; i <= n; i++)
t[i][0] = 0;
for (i = 1; i <= n; i++)
{
for (j = 1; j <= c; j++)
{
if (j - w[i] < 0)
t[i][j] = t[i - 1][j];
else
t[i][j] = max (t[i - 1][j], p[i] + t[i - 1][j - w[i]]);
}
}
}
void Items (int n, int c, int t[MAX][MAX], int w[MAX], int l[MAX])
{
int i, j;
i = n;
j = c;
while (i >= 1 && j >= 1)
{
if (t[i][j] != t[i - 1][j])
{l[i] = 1;
j = j - w[i];
i--;
}
else
i--;
}
}
void additem (FILE * fp)
{
printf ("\nENTER THE DETAILS OF ITEM(S)\n");
int x = 1, w, p;
char name[50];
while (1)
{
if (x == 1)
{
printf ("\nITEM NAME:");
scanf ("%s", name);
printf ("ITEM PRICE:");
scanf ("%d", &p);
printf ("ITEM Volume:");
scanf ("%d", &w);
fprintf (fp, "%d\t%s\t%d\t%d\n", count++, name, p, w);
printf ("\nItem added to list\n\nSelect 1: Add 2: back \n");
scanf ("%d", &x);
}
else
return;
}
}
void deleteitem (FILE * fp)
{
int x, w, p, a;
char name[50];
FILE *fp1;
count = 0;
fp1 = fopen ("temp", "a");
printf ("\nEnter the item number to deletion: ");
scanf ("%d", &x);
while ((fscanf (fp, "%d%s%d%d", &a, a, &p, &w)) != EOF)
{
if (x == a)
{
printf ("Item %s is deleted \n", a);
}else{
fprintf (fp1, "%d\t%s\t%d\t%d\n", count++, a, p, w);
}
}
count = 1;
while ((fscanf (fp1, "%d%s%d%d", &a, name, &p, &w)) != EOF) {
fprintf (fp, "%d\t%s\t%d\t%d\n", count++, name, p, w);
}
}void displayitem (FILE * fp) {
int w, p, a;
char name[50];
printf ("\nITEM LIST\n");
printf ("SLNO.\tNAME\tPRICE\tVolume\n");
while ((fscanf (fp, "%d%s%d%d", &a, name, &p, &w)) != EOF) {
printf ("%d\t%s\t%d\t%d\n", a, name, p, w);
}
}void selectitem (FILE * fp) {
int i, j, tp, a, p, w;
int Volume[MAX];
int v[MAX];
int capacity, n;
int loaded[MAX];
int table[MAX][MAX];
n = count;
char name[50];
printf ("Reading items details from item file\n");
for (i = 1; i <= n; i++) {
fscanf (fp, "%d%s%d%d", &a, name, &v[i], &Volume[i]);
}
printf ("Enter the maximum capacity\n");
scanf ("%d", &capacity); fclose (fp);
tp = 0;
for (i = 1; i <= n; i++)
loaded[i] = 0;
maxitems (
Volume, v, n, capacity, table);
Items (n, capacity, table, Volume, loaded);
printf ("\nMax items Matrix:\n\n");
for (i = 0; i <= n; i++)
{
for (j = 0; j <= capacity; j++)
{
printf ("%d\t", table[i][j]);
}
printf ("\n");
}
printf ("\nItems which can be loaded are\n");
printf ("NAME\tPRICE\tVOLUME\n");
fp = fopen ("items", "r");
for (i = 1; i <= n; i++)
{
fscanf (fp, "%d%s%d%d", &a, name, &p, &w);
if (loaded[i])
{
printf ("%s\t%d\t%d\n", name, p, w);
tp += v[i];
}
}
printf ("\nTotal price is: %d\n", tp);
}
int main ()
{
int a;
FILE *fp;
while (1)
{
printf ("\nSELECT YOUR CHOICE\n");
printf
("1: ADD ITEM\n2: DELETE ITEM\n3: DISPLAY ITEMS\n4: SELECTEDITEMS\n5: EXIT\n");
scanf ("%d", &a);
switch (a)
{
case 1:
fp = fopen ("items", "a");
if (fp == NULL)
{
printf ("\n ERROR IN OPENING FILE");
}
else
{
additem (fp);
fclose (fp);
}
break;
case 2:
fp = fopen ("items", "a");
if (fp == NULL) {
printf ("\n ERROR IN OPENING FILE");
}
else {
displayitem (fp);
deleteitem (fp); fclose (fp);
}
break;
case 3:
fp = fopen ("items", "r");
if (fp == NULL)
printf ("\nNo items to display !!!");
else {
displayitem (fp); fclose (fp);
}
break;
case 4:
fp = fopen ("items", "r");
if (fp == NULL)
printf ("\nNo items to select !!!");
else {
selectitem (fp); fclose (fp);
}
break;
case 5:
exit (0);
default:
printf ("\n Invalid choice !!!\n");
}
}
return 0;
}

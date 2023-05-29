#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
//#include<Windows.h>

void bubblesort();
int n;
struct as_airline
{
	char passport[6];
	char name[15];
	int seat_num;
	char email[15];
	int date ;
	struct as_airline *following;
}
*begin, *stream;
struct as_airline *dummy;
typedef struct as_airline node;
node s[10];


int main()
{
	void reserve(int x), cancel(),bubblesort(), display(), savefile();
	int choice;
	int i,j,temp;
	int element[5];
	begin = stream = NULL;
	int num = 1;
	do
	{

		printf("\n\n\t\t ************************");
		printf("\n\t\t                   welcome to airline system                   ");
		printf("\n\t\t   ***********************");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2.BUBBLESORT ");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t feel free to ask us");
		printf("\n\n\t\t Enter your choose ");



		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;

        case 2:
            bubblesort();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				savefile();
				break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-5");
			printf("\n\n\t Do not forget to chose from 1-5");
		}
		//getch();
	} while (choice != 5);

}



void details()
{
    int i,j;
    printf("how many no of members  you want to book\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n\t Enter person %d passport number:",i+1);
        scanf("%s",&s[i].passport);
        printf("\n\t Enter person %d name:",i+1);
        scanf("%s",&s[i].name);
        printf("\n\t Enter person %d email address:",i+1);
        scanf("%s",&s[i].email);
        if(i==1)
        {
             printf("\n\t\t %dnd seat number is: Seat A-%d",i+1,i+1);
        }
        else
        {
             printf("\n\t\t %dst seat number is: Seat A-%d",i+1,i+1);
        }
    }
}


void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		begin = stream = (struct as_airline*)malloc(sizeof(struct as_airline));
        details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		stream->seat_num = x;
		return;
	}
	else if (x> 15)
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		while (stream->following)
			stream = stream->following;
		stream->following = (struct as_airline*)malloc(sizeof(struct as_airline));
		stream = stream->following;
		details();
		stream->following = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", x);
		stream->seat_num = x;
		return;
	}
}


void savefile()
{
	FILE *fpointer = fopen("as records", "w");
	if(!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file (as records)");
	fclose(fpointer);
}

void display()
{
	stream = begin;
	int i,j;
	for(i=0;i<n;i++){
      printf("\n Name:%s",s[i].name);
      printf("\n Passport Number : %-6s", s[i].passport);
		printf("\n      email address: %-15s", s[i].email);
		printf("\n      Seat number: A-%d", stream->seat_num);
		printf("\n\n++=====================================================++");
   }

}

/*void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\n Enter passport number to delete record?:");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf(" booking has been deleted");
		Sleep(800);
		return;

	}

	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("has been deleted ");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
	printf("passport number is wrong please check your passport");

}*/
void  bubblesort()
{
    stream=begin;
     int i,j;

    printf("the number of customers to be sorted:");
    node temp;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
    if(strcmp(s[i].name,s[j].name)>0)
    {
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
   }
    for(i=0;i<n;i++){
      printf("\n Name:%s",s[i].name);
      printf("\n Passport Number : %-6s", s[i].passport);
		printf("\n      email address: %-15s", s[i].email);
		printf("\n      Seat number: A-%d", stream->seat_num);
		printf("\n\n++=====================================================++");
   }

}

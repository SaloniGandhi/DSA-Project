/*  <LIBRARY MANAGEMENT- The program manages the records of a library ,it basically demonstrates the working of a library>
    Copyright (C) <2015>  <Saloni Gandhi>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


#include"head.h"
struct thedate
{
	int mm,dd,yy;
};
struct books
{
	int id;
	char stname[20];
	char name[20];
	char Author[20];
	int quantity;
	float Price;
	int count;
	int rackno;
	char *cat;
	struct thedate issued;
	struct thedate duedate;
};
struct books a;
//function prototytpes

void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void issuedetails();
void load();


char catagories[][15]={"Literature","Fiction","Science Fic","Comics","Culinary","Education"};
char ans;
//list of global files that can be accessed form anywhere in the program
FILE *fp,*ft,*fs;

//list of global variable
int s;
char findbook;
void  mainmenu()
{
	load();
	system("clear");
	//   textbackground(13);
	int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB 1. Add Books   ");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB 2. Delete books");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB 3. Search Books");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB 4. Issue Books");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB 5. View Book list");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB 6. Edit Book's Record");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB 7. Exit program");
	gotoxy(20,19);
	printf("------------------------------------------");
	gotoxy(20,20);
	t();
	gotoxy(20,21);
	printf("Enter your choice:");
	switch(getchar())
	{
		case '1':
		addbooks();
		system("clear");
		break;
		case '2':
		deletebooks();
		break;
		case '3':
		searchbooks();
		break;
		case '4':
		issuebooks();
		break;
		case '5':
		viewbooks();
		break;
		case '6':
		editbooks();
		break;
		
		//add functions as you do
		case '7':
		{
			system("clear");
			gotoxy(16,3);
			printf("Thanks for using the Program..");
				gotoxy(10,7);
			printf("Exiting in 5 second...........>");
			delay(5);
			exit(0);
		}
		default:
		{
			gotoxy(10,23);
			printf("\aWrong Entry!!Please re-entered correct option..\n");
			if(getchar())
			mainmenu();
		}
		
	}
	
}

int getdata()
{
	int t;
	gotoxy(20,3);
	printf("Enter the Information Below");
	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[s-1]);
	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		system("clear");
		mainmenu();
		return 0;
	}
	a.id=t;
	gotoxy(21,7);
	printf("Book Name:");gotoxy(33,7);
	scanf("%s",a.name);
	gotoxy(21,8);
	printf("Author:");gotoxy(30,8);
	scanf("%s",a.Author);
	gotoxy(21,9);
	printf("Quantity:");gotoxy(31,9);
	scanf("%d",&a.quantity);
	gotoxy(21,10);
	printf("Price:");gotoxy(28,10);
	scanf("%f",&a.Price);
	gotoxy(21,11);
	printf("Rack No:");gotoxy(30,11);
	scanf("%d",&a.rackno);
	return 1;
}

void addbooks(void)    //funtion that add books
{
	system("clear");
	int i;
	gotoxy(20,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGORIES");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB3 1. Literature");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Fiction");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Science Fic");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Comics");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Culinary");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Education");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);
	printf("Enter your choice:");
	scanf("%d",&s);
	if(s==7)
	
	mainmenu() ;
	system("clear");
	fp=fopen("libnew.dat","ab+");
	if(getdata())
	{
		a.cat=catagories[s-1];
		fseek(fp,0,SEEK_END);
		fwrite(&a,sizeof(a),1,fp);
		fclose(fp);
		system("clear");
		printf("The record is sucessfully saved\n");
		system("clear");
		gotoxy(10,23);
		printf("Save any more?(Y / N):");
		if(getchar()=='N')
		{system("clear");
		mainmenu();}
		else{
			system("clear");
			addbooks();
		}
	}
}
void deletebooks()    //function that delete items from file fp
{
	system("clear");
	int d;
	int flag=1;
	system("clear");
	gotoxy(10,5);
	printf("Enter the Book ID to  delete:");
	scanf("%d",&d);
	fp=fopen("libnew.dat","rb+");
	rewind(fp);
	ft=fopen("rem.dat","wb+");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(a.id!=d)
		{	fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft);
			
		}
		else
		{ flag=0;
		}
	}
	fclose(fp);
	fclose(ft);
	if(flag==1)
	{system("clear");
	printf("book with id number %d is not found",a.id);}
	else{
		system("clear");
		gotoxy(25,4);
		printf("deletion successful...");
		mainmenu();
	}
	
}
void searchbooks()
{
	system("clear");
	int d;
	printf("*****************************Search Books*********************************");
	gotoxy(20,10);
	printf("\xDB\xDB\xDB\xB2 1. Search By ID");
	gotoxy(20,14);
	printf("\xDB\xDB\xDB\xB2 2. Search By Name");
	gotoxy( 15,20);
	system("clear");
	printf("Enter Your Choice");
	fp=fopen("libnew.dat","rb+"); //open file for reading propose
	rewind(fp);   //move pointer at the begining of file
	switch(getchar())
	{
		case '1':
		{
			system("clear");
			gotoxy(25,4);
			printf("****Search Books By Id****");
			gotoxy(20,5);
			system("clear");
			printf("Enter the book id:");
			scanf("%d",&d);
			gotoxy(20,7);
			printf("Searching........");
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(a.id==d)
				{
					
					gotoxy(20,7);
					printf("The Book is available");
					gotoxy(20,8);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					gotoxy(20,9);
					printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
					gotoxy(20,10);
					printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
					gotoxy(20,11);
					printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2");
					gotoxy(20,12);
					printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
					gotoxy(20,13);
					printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
					gotoxy(20,14);
					printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
					gotoxy(20,15);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					findbook='t';
				}
				
			}
			if(findbook!='t')  //checks whether conditiion enters inside loop or not
			{
				gotoxy(20,8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
				gotoxy(20,10);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,9);printf("\aNo Record Found");
			}
			gotoxy(20,17);
			printf("Try another search?(Y/N)");
			if(getchar()=='y')
			searchbooks();
			else
			{mainmenu();
			break;}
		}
		case '2':
		{
			char s[15];
			system("clear");
			gotoxy(25,4);
			printf("****Search Books By Name****");
			gotoxy(20,5);
			printf("Enter Book Name:");
			scanf("%s",s);
			int d=0;
			while(fread(&a,sizeof(a),1,fp)==1)
			{
				if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
				{
					gotoxy(20,7);
					printf("The Book is available");
					gotoxy(20,8);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					gotoxy(20,9);
					printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
					gotoxy(20,10);
					printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
					gotoxy(20,11);
					printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2");
					gotoxy(20,12);
					printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
					gotoxy(20,13);
					printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
					gotoxy(20,14);
					printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
					gotoxy(20,15);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					d++;
				}
				
			}
			if(d==0)
			{
				gotoxy(20,8);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
				gotoxy(20,10);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,9);printf("\aNo Record Found");
			}
			gotoxy(20,17);
			printf("Try another search?(Y/N)");
			if(getchar()=='y')
			searchbooks();
			else
			{mainmenu();
			break;}
		}
		default :
		{getchar();
		searchbooks();}
	}
	fclose(fp);
}
void viewbooks(void)  //show the list of books in the library
{
	int i=0,j;
	system("clear");
	gotoxy(1,1);
	printf("=============================Book List==================================");
	gotoxy(2,2);
	printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
	j=4;
	fp=fopen("libnew.dat","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		gotoxy(4,j);
		printf("%s",a.cat);
		gotoxy(16,j);
		printf("%d",a.id);
		gotoxy(22,j);
		printf("%s",a.name);
		gotoxy(36,j);
		printf("%s",a.Author);
		gotoxy(50,j);
		printf("%d",a.quantity);
		gotoxy(57,j);
		printf("%.2f",a.Price);
		gotoxy(69,j);
		printf("%d",a.rackno);
		printf("\n\n");
		j++;
		i=i+a.quantity;
	}
	gotoxy(3,25);
	printf("Total Books =%d",i);
	fclose(fp);
	gotoxy(35,25);
	returnfunc();
}
void editbooks(void)  //edit information about book
{
	system("clear");
	int c=0;
	int d,e;
	gotoxy(20,4);
	printf("****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("clear");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("libnew.dat","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",a.id);
				gotoxy(15,9);
				printf("Enter shownew.dat name:");scanf("%s",a.name);
				gotoxy(15,10);
				printf("Enter shownew.dat Author:");scanf("%s",a.Author);
				gotoxy(15,11);
				printf("Enter shownew.dat quantity:");scanf("%d",&a.quantity);
				gotoxy(15,12);
				printf("Enter shownew.dat price:");scanf("%f",&a.Price);
				gotoxy(15,13);
				printf("Enter shownew.dat rackno:");scanf("%d",&a.rackno);
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getchar() ;
	}
	returnfunc();
}


void issuebooks(void)  //function that issue books from library
{
	int t;
	
	system("clear");
	printf("********************************ISSUE SECTION**************************");
	gotoxy(10,5);
	printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
	gotoxy(10,7);
	printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
	gotoxy(10,9);
	printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
	gotoxy(10,11);
	printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
	gotoxy(10,14);
	printf("Enter a Choice:");
	switch(getchar())
	{
		case '1':  //issue book
		{
			system("clear");
			int c=0;
			char another='y';
			while(another=='y')
			{
				system("clear");
				gotoxy(15,4);
				printf("***Issue Book section***");
				gotoxy(10,6);
				printf("Enter the Book Id:");
				scanf("%d",&t);
				fp=fopen("libnew.dat","rb");
				fs=fopen("shownew.dat","ab+");
				if(checkid(t)==0) //issues those which are present in library
				{
					gotoxy(10,8);
					printf("The book record is available");
					gotoxy(10,9);
					printf("There are %d unissued books in library ",a.quantity);
					gotoxy(10,10);
					printf("The name of book is %s",a.name);
					gotoxy(10,11);
					printf("Enter student name:");
					scanf("%s",a.stname);
					gotoxy(10,12);
					printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
					gotoxy(10,13);
					printf("The BOOK of ID %d is issued",a.id);
					a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
					a.duedate.mm=a.issued.mm;
					a.duedate.yy=a.issued.yy;
					if(a.duedate.dd>30)
					{
						a.duedate.mm+=a.duedate.dd/30;
						a.duedate.dd-=30;
						
					}
					if(a.duedate.mm>12)
					{
						a.duedate.yy+=a.duedate.mm/12;
						a.duedate.mm-=12;
						
					}
					gotoxy(10,14);
					printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
					fseek(fs,sizeof(a),SEEK_END);
					fwrite(&a,sizeof(a),1,fs);
					fclose(fs);
					c=1;
				}
				if(c==0)
				{
					gotoxy(10,11);
					printf("No record found");
				}
				gotoxy(10,15);
				printf("Issue any more(Y/N):");
				fflush(stdin);
				another=getchar();
				fclose(fp);
			}
			
			break;
		}
		case '2':  //shows issued book list
		{
			system("clear");
			int j=4;
			printf("*******************************Issued book list*******************************\n");
			gotoxy(2,2);
			printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
			fs=fopen("shownew.dat","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				
				gotoxy(2,j);
				printf("%s",a.stname);
				gotoxy(18,j);
				printf("%s",a.cat);
				gotoxy(30,j);
				printf("%d",a.id);
				gotoxy(36,j);
				printf("%s",a.name);
				gotoxy(51,j);
				printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
				gotoxy(65,j);
				printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
				gotoxy(50,25);
				j++;
				
			}
			fclose(fs);
			gotoxy(1,25);
			returnfunc();
		}
		break;
		case '3':   //search issued books by id
		{
			system("clear");
			gotoxy(10,6);
			printf("Enter Book ID:");
			int p,c=0;
			char another='y';
			while(another=='y')
			{
				
				scanf("%d",&p);
				fs=fopen("shownew.dat","rb");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==p)
					{
						issuedetails();
						gotoxy(10,12);
						printf("Press any key.......");
						getchar();
						issuedetails();
						c=1;
					}
					
				}
				fflush(stdin);
				fclose(fs);
				if(c==0)
				{
					gotoxy(10,8);
					printf("No Record Found");
				}
				gotoxy(10,13);
				printf("Try Another Search?(Y/N)");
				another=getchar();
			}
		}
		break;
		case '4':  //remove issued books from list
		{
			system("clear");
			int b;
			FILE *fg;  //declaration of temporary file for delete
			char another='y';
			while(another=='y')
			{
				gotoxy(10,5);
				printf("Enter book id to remove:");
				scanf("%d",&b);
				fs=fopen("shownew.dat","rb+");
				while(fread(&a,sizeof(a),1,fs)==1)
				{
					if(a.id==b)
					{
						issuedetails();
						findbook='t';
					}
					if(findbook=='t')
					{
						gotoxy(10,12);
						printf("Do You Want to Remove it?(Y/N)");
						if(getchar()=='y')
						{
							fg=fopen("record.dat","wb+");
							rewind(fs);
							while(fread(&a,sizeof(a),1,fs)==1)
							{
								if(a.id!=b)
								{
									fseek(fs,0,SEEK_CUR);
									fwrite(&a,sizeof(a),1,fg);
								}
							}
							fclose(fs);
							fclose(fg);
							remove("shownew.dat");
							rename("record.dat","shownew.dat");
							gotoxy(10,14);
							printf("The issued book is removed from list");
							
						}
						
					}
					if(findbook!='t')
					{
						gotoxy(10,15);
						printf("No Record Found");
					}
				}
				gotoxy(10,16);
				printf("Delete any more?(Y/N)");
				another=getchar();
			}
		}
		default:
		gotoxy(10,18);
		printf("\aWrong Entry!!");
		getchar();
		issuebooks();
		break;
	}
	gotoxy(1,30);
	returnfunc();
}
void issuedetails()  //display issued book's information
{
	system("clear");
	gotoxy(10,8);
	printf("The Book has taken by Mr. %s",a.stname);
	gotoxy(10,9);
	printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
	gotoxy(10,10);
	printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
void load()
{
	int loader;
	system("clear");
	gotoxy(20,10);
	printf("WELCOME TO MY LIBRARY........");
	printf("\n\n");
	gotoxy(22,11);
	for(loader=1;loader<20;loader++)
	{
	delay(40000);
        printf("%c",219);
	}
}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
	return 1; //return 1 if it not
	
}

int main(){
	mainmenu();
	return 0;
 }





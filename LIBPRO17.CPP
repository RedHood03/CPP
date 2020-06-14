/*****************************************************
// PROGRAM TO MANAGE A LIBRARY
******************************************************/
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<process.h>
#include<dos.h>
////////////////////////////////////////////////////////////

struct BN
{
 int bn;
};
////////////////////////////////////////////////////////////

struct Date
{
 int d, m, y;
};
///////////////////////////////////////////////////////////////////
class studet
{
 public:
 double adno;
 char name[40];

 int retadno()
 {
  return adno;
 }

 char *retname()
 {
  return name;
 }

 void getdata()
 {
  cout<<"Enter name of student: ";
  gets(name);
  cout<<"Enter admission number(4 digits): ";
  cin>>adno;
 }
};
////////////////////////////////////////////////////////////

class student
{
 public:
 double stdno;
 int Bno;
 char b[21];
 dosdate_t issd;
 Date D;

 int retstdno()
 {
  return stdno;
 }
 int retBno()
 {
  return Bno;
 }
 char *retb()
 {
  return b;
 }
};
//////////////////////////////////////////////////////////////

class LIB
{
 public:
 int bno,edition;
 double ISBN,billno;
 char author[21],lang[10],pubname[25],vndr[30],rsn[40],bname[40],borr[5];

 //////////////////
 int retbno()
 {
  return bno;
 }
 /////////////////
 double retIno()
 {
  return ISBN;
 }
 /////////////////
 double retbillno()
 {
  return billno;
 }
 /////////////////
 char *retbname()
 {
  return bname;
 }
 void display();

/*****************************************************
// FUNCTION TO ADD A BOOK INTO THE LIBRARY
******************************************************/

 void input()
 {
  cout<<"Enter book name: ";
  gets(bname);
  cout<<"Enter author name: ";
  gets(author);
  cout<<"Language: ";
  gets(lang);
  cout<<"Enter edition: ";
  cin>>edition;
  cout<<"Publisher name: ";
  gets(pubname);
  cout<<"Vendor name: ";
  gets(vndr);
  cout<<"Indian Standard Book Number: ";
  cin>>ISBN;
  BN ob;
  ifstream fin("BNO.dat",ios::binary);
  fin.read((char*)&ob,sizeof(ob));
  ob.bn++;
  bno=(ob.bn);
  fin.close();
  ofstream F("BNO.dat",ios::binary);
  F.write((char*)&ob,sizeof(ob));
  F.close();
  cout<<"\nBook Number is: "<<bno;
  cout<<"\nBook added successfully\n";
  getch();
 }

/**********************************************************
// FUNCTION TO DISPLAY BASIC INFO. OF BOOK TO THE STUDENT
**********************************************************/

 int bobk()
 {
  if (strcmp(borr,"no")==0)
  {
   cout<<"Book name: ";
   puts(bname);
   cout<<"Author: ";
   puts(author);
   cout<<"Language: ";
   puts(lang);
   return 1;
  }
  else
   return 0;
 }
};

/*************************************************************
// FUNCTION TO DISPLAY COMPLETE BOOK DETAILS TO THE LIBRARIAN
*************************************************************/

 void LIB:: display()
 {
  student A;
  cout<<"\n\nBook Number: "<<bno;
  cout<<"\nBook name: ";
  puts(bname);
  cout<<"Author: ";
  puts(author);
  cout<<"Language: ";
  puts(lang);
  cout<<"Edition: "<<edition<<"\nPublisher: ";
  puts(pubname);
  cout<<"Vendor: ";
  puts(vndr);
  cout<<"Indian Standard Book Number:"<<ISBN;
  cout<<'\n';
  cout<<"Book borrowed: "<<borr;
  if(strcmp(borr,"yes")==0)
  {
   fstream f;
   f.open("stu.dat",ios::binary|ios::in);
   while(f.read((char*)&A,sizeof(A)))
   {
    if(strcmp(A.retb(),retbname())==0)
    {
     if(strlen(rsn)!=0)
      cout<<"\nBorrowed by: "<<A.stdno;
     else
      cout<<"Lost by: "<<A.stdno;
    }
   }
  }
 }

/*****************************************************
// FUNCTION TO BORROW A BOOK FROM THE LIBRARY
******************************************************/

 void borrow()
 {
  LIB S;
  int bkno;
  student A;
  studet X;
  double stn;
  fstream fout;
  fstream fin;
  fstream f1;
  int pos,flag=0,f=0,a=0;
  fin.open("lib.dat",ios::binary|ios::in|ios::out);
  fout.open("stu.dat",ios::binary|ios::in);
  f1.open("studet.dat",ios::binary|ios::in);
  char ch,name[40];
  cout<<"Enter your admission number:\nTSA\:";
  cin>>stn;
  //////////////
  while(f1.read((char*)&X,sizeof(X)))
  {
   if(stn==X.adno)
   {
    a=1;
    break;
   }
  }
  ///////////
  if(a==0)
   cout<<"Invalid admission number\nPlease try again\n";
  else
  {
    ////////////
    while(fout.read((char*)&A,sizeof(A)))
    {
     if(stn==A.stdno)
     {
      cout<<"You are not allowed to borrow a book.\nPlease return the book you have currently borrowed first\n";
      f=1;
      break;
     }
    }
   ////////////////
   fout.close();
   if(f==0)
   {
    fout.open("stu.dat",ios::binary|ios::app);
    cout<<"Enter the book no. you would like to borrow: "<<'\n';
    cin>>bkno;
    while(fin.read((char*)&S,sizeof(S)))
    {
     pos=fin.tellg()-sizeof(S);
     if(bkno==S.retbno())
     {
      flag=1;
      int x = S.bobk();
      if (x==1)
      {
       cout<<"Is this the book you'd like to borrow (Y/N): ";
       cin>>ch;
       if(ch=='Y'||ch=='y')
       {
	A.stdno=stn;
	A.Bno=S.bno;
	strcpy(A.b,S.bname);
	dosdate_t id;
	_dos_getdate(&id);
	A.D.d=id.day;
	A.D.m=id.month;
	A.D.y=id.year;
	strcpy(S.borr,"yes");
	fin.seekp(pos);
	fin.write((char*)&S,sizeof(S));
	fout.write((char*)&A,sizeof(A));
	cout<<"Book successfully borrowed\n";
       }
       break;
      }
      else
      {
       cout<<"Book already borrowed";
       break;
      }
     }
    }
    if(flag==0)
   {
    cout<<"Book not available in this library\n";
   }
   }
   }
  f1.close();
  fout.close();
  fin.close();
 }

/*********************************************************
// FUNCTION TO WRITE THE BOOK DETAILS INTO THE BINARY FILE
**********************************************************/

  void inpt()
 {
  LIB S;
  student A;
  clrscr();
  S.input();
  strcpy(S.borr,"no");
  ofstream f;
  f.open("lib.dat",ios::binary|ios::app);
  f.write((char*)&S,sizeof(S));
  f.close();
 }
/*******************************************************
// FUNCTION TO DELETE BOOK DETAILS FROM THE BINARY FILE
*******************************************************/

 void deletebk()
 {
  int bkno;
  LIB S;
  student A;
  int flag=0;
  ifstream fin;
  ofstream fout;
  fin.open("lib.dat",ios::binary);
  fout.open("temp.dat",ios::binary);
  cout<<"Enter the book no. that you'd like to remove: ";
  cin>>bkno;
  while(fin.read((char*)&S,sizeof(S)))
   {
    if(bkno!=S.retbno())
     fout.write((char*)&S,sizeof(S));
    else
     flag=1;
    }
  if(flag==0)
   cout<<"Book not found\n";
  else
   cout<<"Book removed\n";
  fin.close();
  fout.close();
  remove("lib.dat");
  rename("temp.dat","lib.dat");
 }
/***********************************************
// FUNCTION TO RETURN A BOOK BACK TO THE LIBRARY
***********************************************/

 void returnb()
 {
  LIB S;
  int pos,fl=0,fl1;
  student A;
  studet X;
  fstream f;
  ifstream fin,f1;
  ofstream fout;
  double stdno;
  fout.open("temp.dat",ios::binary);
  fin.open("stu.dat",ios::binary);
  f.open("lib.dat",ios::binary|ios::in|ios::out);
  f1.open("studet.dat",ios::binary);
  char ch,str[40];
  cout<<"Enter your admission number: ";
  cin>>stdno;
  while(f1.read((char*)&X,sizeof(X)))
  {
   if(stdno==X.adno)
   {
    fl=1;
    break;
   }
  }
  if(fl==1)
  {
   fl1=0;
   while(fin.read((char*)&A,sizeof(A)))
   {
    if(stdno==A.stdno)
    {
     cout<<"Admission number: "<<A.stdno;
     cout<<"\nName of book: ";
     puts(A.b);
     strcpy(str,A.b);
     cout<<"Return the book(Y/N): ";
     cin>>ch;
     if(ch=='Y'||ch=='y')
     {
      while(fin.read((char*)&A,sizeof(A)))
      {
       if(strcmp(str,A.retb())!=0)
	fout.write((char*)&A,sizeof(A));
      }
      while(f.read((char*)&S,sizeof(S)))
      {
       pos=f.tellg()-sizeof(S);
       if(strcmp(str,S.retbname())==0)
       {
	strcpy(S.borr,"no");
	f.seekp(pos);
	f.write((char*)&S,sizeof(S));
       }
      }
      cout<<"Book returned\n";
      remove("stu.dat");
      rename("temp.dat","stu.dat");
     }
     fl1=1;
    }
   }
  }
  if(fl1==0)
   {
    cout<<"You haven't borrowed a book\n";
   }
  if(fl==0)
  {
   cout<<"Admission number not found\n";
  }
   fin.close();
   fout.close();
   f.close();
  }
/**************************************************
// FUNCTION TO DISPLAY ALL THE BOOKS IN THE LIBRARY
**************************************************/

 void disp()
 {
  gotoxy(2,3);
  int flag=0;
  LIB A;
  ifstream fin;
  fin.open("lib.dat",ios::binary);
  do
  {
   fin.read((char*)&A,sizeof(A));
   if(fin.eof())
    break;
   A.display();
   flag++;
   if(flag%2==0)
   {
    cout<<'\n'<<'\n'<<"                     PRESS ANY BUTTON TO SEE MORE BOOKS";
    getch();
    clrscr();
   }
  }while((char*)&A,sizeof(A));
  fin.close();
 }
/*********************************************
// FUNCTION TO DISPLAY BORROWED BOOKS
*********************************************/

 void disbor()
 {
  student A;
  ifstream f;
  f.open("stu.dat",ios::binary);
  clrscr();
  cout<<"\nAdmision No.\tBook Borrowed\tDate issued\n";
  cout<<"------------------------------------------\n";
  while(f.read((char*)&A,sizeof(A)))
  {
   cout<<A.stdno<<"\t\t"<<A.b<<"\t\t"<<A.D.d<<"/"<<A.D.m<<"/"<<A.D.y<<'\n';
  }
  f.close();
 }
/*************************************************
// FUNCTION TO REPORT A LOST BOOK
*************************************************/

 void lost()
 {
  LIB S;
  int f=0,flag=0,flag1=0;
  double n;
  int bkno;
  student A;
  fstream f1,f2,f3;
  f1.open("lib.dat",ios::binary|ios::in|ios::out);
  f2.open("stu.dat",ios::binary|ios::in);
  f3.open("studet.dat",ios::binary|ios::in);
  studet X;
  cout<<"Enter your admission no: ";
  cin>>n;
  while(f3.read((char*)&X,sizeof(X)))
  {
   if(n==X.adno)
   {
    f=1;
    break;
   }
   else
    f=0;
  }
  if(f==0)
   cout<<"Student is not a member of this school\n";
  else
  {
   while(f2.read((char*)&A,sizeof(A)))
   {
    if(n==A.stdno)
    {
     cout<<"Enter Book number of lost book: ";
     cin>>bkno;
     while(f1.read((char*)&S,sizeof(S)))
     {
      if(bkno==S.retbno())
      {
       cout<<"Enter details of new book that is being placed:\n";
       S.input();
       strcpy(S.borr,"no");
       int pos=f1.tellg()-sizeof(S);
       f1.seekp(pos);
       f1.write((char*)&S,sizeof(S));
       flag=1;
       break;
      }
     }
     if(flag==0)
      cout<<"Book no. doesn't exist";
     flag1=1;
     break;
    }
   }
   if (flag1==0)
    cout<<"You haven't even borrowed a book";
  }
  f1.close();
  f2.close();
 }
/****************************************************
// FUNCTION TO ADD STUDENT DETAILS TO THE BINARY FILE
****************************************************/

 void addstu()
 {
  int f=0;
  studet A,B;
  clrscr();
  ofstream fout;
  ifstream fin;
  fin.open("studet.dat",ios::binary);
  cout<<"Enter the details of the new student:\n";
  A.getdata();

  while(fin.read((char*)&B,sizeof(B)))
  {
   if(A.adno==B.retadno())
   {
    cout<<"Admission number already exists\n";
    getch();
    f=1;
    break;
   }
  }
  fin.close();
  if(f!=1)
  {
   fout.open("studet.dat",ios::binary|ios::app);
   fout.write((char*)&A,sizeof(A));
   cout<<"Student successfully admitted\n";
   getch();
   fout.close();
  }
 }

/*********************************************************
// FUNCTION TO DISPLAY ALL THE STUDENTS IN THE BINARY FILE
*********************************************************/

 void dispstu()
 {
  studet A;
  clrscr();
  ifstream f;
  f.open("studet.dat",ios::binary);
  clrscr();
  cout<<"\nAdmision No.\tName of student\n";
  cout<<"------------------------------\n";
  while(f.read((char*)&A,sizeof(A)))
  {
   cout<<A.adno<<"\t\t"<<A.name<<'\n';
  }
  f.close();
 }
/***************************************************
// FUNCTION TO DELETE A STUDENT RECORD FROM THE FILE
***************************************************/

 void delstu()
 {
  clrscr();
  studet F;
  char *sname;
  int flag=0;
  ifstream fin;
  ofstream fout;
  fin.open("studet.dat",ios::binary);
  fout.open("temp.dat",ios::binary);
  cout<<"Enter the name of the student you'd like to remove: ";
  gets(sname);
  while(fin.read((char*)&F,sizeof(F)))
   {
    if(strcmp(sname,F.retname())!=0)
     fout.write((char*)&F,sizeof(F));
    else
     flag=1;
   }
  if(flag==0)
    cout<<"Student doesn't exist\n";
  else
   cout<<"Student removed\n";
  fin.close();
  fout.close();
  remove("studet.dat");
  rename("temp.dat","studet.dat");
 }
////////////////////////////////////////////////////
 void dispboo()
 {
  clrscr();
  LIB S;
  ifstream f1;
  f1.open("lib.dat",ios::binary|ios::in);
  cout<<"|Book Name|\t\t|Book Number|\n";
  cout<<"--------------------------------------"<<'\n';
  while(f1.read((char*)&S,sizeof(S)))
  {
   cout<<S.bname;
   cout<<"\t\t\t"<<S.bno<<'\n';
  }
  f1.close();
 }

/****************
// MAIN FUNCTION
*****************/

 void main()
 {
  int a,b;
  char bname[40];
  clrscr();
  ifstream fin;
  ofstream fout;
  gotoxy(31,7);
  cout<<"THE LIBRARY SOFTWARE";
  gotoxy(29,9);
  cout<<"COMPUTER SCIENCE PROJECT";
  gotoxy(63,20);
  cout<<"By Umang and Deva";
  gotoxy(68,21);
  cout<<"Grade 12";
  gotoxy(30,22);
  cout<<"PRESS ANY KEY TO CONTINUE";
  getch();
  do{
   start:
   int j=5;
   clrscr();
   gotoxy(33,j);
   cout<<"MAIN MENU\n";
   j+=2;
   gotoxy(22,j);
   cout<<"1.Admin Menu\n";
   j++;
   gotoxy(22,j);
   cout<<"2.Student Menu\n";
   j++;
   gotoxy(22,j);
   cout<<"3.Exit"<<'\n';
   j+=2;
   gotoxy(22,j);
   cout<<"Which option would you like(1/2/3): ";
   cin>>b;
   switch(b)
    {
     case 1:
      clrscr();
      char ch,pass[10];
      gotoxy(26,12);
      cout<<"Enter Password: ";
      for(int i=0;i<10;)
      {
       ch=getch();
       if(ch==13)
       {
	pass[i]='\0';
	break;
       }
       else
       if(ch=='\b')
       {
	cout<<"\b \b";
	i--;
       }
       else
       {
	pass[i]=ch;
	cout<<'*';
	i++;
       }
      }
      if(strcmp(pass,"tsastaff")==0)
      {
       do{
	  j=5;
	  clrscr();
	  gotoxy(32,j);
	  cout<<"ADMIN MENU"<<'\n';
	  j+=2;
	  gotoxy(25,j);
	  cout<<"1.Add a book"<<'\n';
	  j++;
	  gotoxy(25,j);
	  cout<<"2.Add a new student\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"3.Display all books\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"4.Display all students\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"5.Display borrowed books"<<'\n';
	  j++;
	  gotoxy(25,j);
	  cout<<"6.Replace a lost book"<<'\n';
	  j++;
	  gotoxy(25,j);
	  cout<<"7.Delete an existing book\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"8.Delete a student\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"9.Main Menu\n";
	  j++;
	  gotoxy(25,j);
	  cout<<"Enter an option: ";
	  cin>>a;
	  switch(a)
	  {
	   case 1:
	   inpt();
	   break;

	   case 2:
	   addstu();
	   break;

	   case 3:
	   clrscr();
	   disp();
	   getch();
	   break;

	   case 4:
	   dispstu();
	   getch();
	   break;

	   case 5:
	   disbor();
	   getch();
	   break;

	   case 6:
	   clrscr();
	   lost();
	   getch();
	   break;

	   case 7:
	   clrscr();
	   deletebk();
	   getch();
	   break;

	   case 8:
	   delstu();
	   getch();
	   break;
	  }
	 }while(a!=9);
	}
      else
      {
       cout<<"\nWrong Password";
       getch();
     }
     break;

     case 2:
     do{
	j=5;
	int a;
	clrscr();
	gotoxy(32,j);
	cout<<"STUDENT MENU\n";
	j+=2;
	gotoxy(25,j);
	cout<<"1.Borrow a book\n";
	j++;
	gotoxy(25,j);
	cout<<"2.Return a book\n";
	j++;
	gotoxy(25,j);
	cout<<"3.Display list of available books\n";
	j++;
	gotoxy(25,j);
	cout<<"4.Main Menu\n";
	j+=2;
	gotoxy(25,j);
	cout<<"Enter your option: ";
	cin>>a;
	switch(a)
	{
	 case 1:
	 clrscr();
	 borrow();
	 getch();
	 break;

	 case 2:
	 clrscr();
	 returnb();
	 getch();
	 break;

	 case 3:
	 clrscr();
	 dispboo();
	 getch();
	 break;

	 case 4:
	 goto start;
	}
       }while(a!=1);
      break;
     }
    }while(b!=3);
   }
///////////////////////////////////////////////////////////////////////////////////////////

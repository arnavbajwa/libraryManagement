

			      /******************************/
			      /********LIBRARY SYSTEM********/
			      /******************************/

#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>

 void addbook();
 long datediff(int ddi,int mmi, int yvi, int ddr,int mmr,int yyr);
 void deletebook();
 void editbook();
 void findbook();
 void addmember();
 void deletemember();
 void editmember();
 void findmember();
 void listallbooks();
 void issuebook();
 void receivebook();
 int isnumber(char *st);
 int findm(int memno);
 int find(int bookno);
 char getkey();
 int deleted=0;
  struct dt
   {
	 int dd,mm,yy;
   };
  struct account
   {
	 long bookno;
	 char title[20];
	 char author[20];
	 char isbn[15];
	 float price;
	 int issued;
	 int memno;
	 char mname[20];
	 char phone[20];
	 char address[20];
	 struct dt doi;
	};
  typedef struct account Account;
  void main()
  {
	int i,x,y=1;
	char items[][25]={"1.  Add New Book\0",
			    "2.  Delete Book Record\0",
			    "3.  Edit Book Record\0",
			    "4.  Issue Book\0",
			    "5.  Receive Book\0",
			    "6.  Find A Book\0",
			    "7.  List All Books\0",
			    "8.  Add New Member\0",
			    "9.  Delete Member Record\0",
			    "10. Edit Member Record\0",
			    "11. Find Member Record\0",
			    "12. Exit\0",};
   char c;

   textmode(C40);
   abc:

   textcolor(BLUE);
   textbackground(BLUE);

	for(i=1;i<=1000;i++)
	 {
	  gotoxy(i,0);
	  cprintf("");
	 }
	textbackground(RED);

	clrscr();
	gotoxy(11,6);
	cprintf("%s",items[1]);
	gotoxy(11,7);
	cprintf("%s",items[2]);
	gotoxy(11,8);
	cprintf("%s",items[3]);
	gotoxy(11,9);
	cprintf("%s",items[4]);
	gotoxy(11,10);
	cprintf("%s",items[5]);
	gotoxy(11,11);
	cprintf("%s",items[6]);
	gotoxy(11,12);
	cprintf("%s",items[7]);
	gotoxy(11,13);
	cprintf("%s",items[8]);
	gotoxy(11,14);
	cprintf("%s",items[9]);
	gotoxy(11,15);
	cprintf("%s",items[10]);
	gotoxy(11,16);
	cprintf("%s",items[11]);
	textcolor(RED);
	textbackground(LIGHTCYAN);
	gotoxy(11,5);
	cprintf("%s",items[0]);
	y=0;
	while(1)
	 {
	  c=getkey();
	  switch(c)
	   {
		case 72:
		 if(y>0)
		  {
		   textcolor(BLUE);
		   textbackground(YELLOW);
		   gotoxy(11,5+y);
		   cprintf("%s",items[y]);
		   y=y-1;
		   textcolor(RED);
		   textbackground(LIGHTCYAN);
		   gotoxy(11,5+y);
		   cprintf("%s",items[y]);
		  }
		  break;
		case 80:
		 if(y<11)
		  {
		   textcolor(BLUE);
		   textbackground(YELLOW);
		   gotoxy(11,5+y);
		   cprintf("%s",items[y]);
		   y=y+1;
		   textcolor(RED);
		   textbackground(LIGHTCYAN);
		   gotoxy(11,5+y);
		   cprintf("%s",items[y]);
		  }
		  break;
		case 13:
		 switch(y)
		  {
		   case 0:
			addbook();
			goto abc;
		   case 1:
			deletebook();
			goto abc;
		   case 2:
			editbook();
			goto abc;
		   case 3:
			issuebook();
			goto abc;
		   case 4:
			receivebook();
			goto abc;
		   case 5:
			findbook();
			goto abc;
		   case 6:
			listallbooks();
			goto abc;
		   case 7:
			addmember();
			goto abc;
		   case 8:
			deletemember();
			goto abc;
		   case 9:
			editmember();
			goto abc;
		   case 10:
			findmember();
			goto abc;
		  case 11:
			exit(1);
			goto abc;
		  }
	   }
	 }
   }


  char getkey()
	  {
	  char x;
	  x=getch();
	  if(x==0)
	   x=getch();
	   return(x);
	  }

	   void addbook()     /********** ADD NEW BOOK **********/
		{
		 char *x;
		 int n1,n2,s,i;
		 char buf[1000];
		 FILE *fp;
		 Account a1;
		 int found;
		 clrscr();
		 textcolor(BLUE);
		 textbackground(YELLOW);
		 for(i=1;i<1000;i++)
		  {
		   gotoxy(i,0);
		   cprintf(" ");
		  }
		  gotoxy(2,3);
		  cprintf("ADD NEW BOOK RECORD");
		  gotoxy(2,4);
		  cprintf("=======================");
		  gotoxy(10,7);
		  cprintf("Book No:");
		  buf[0]=20;
		  bnl:
		  gotoxy(21,7);
		  x=cgets(buf);
		  if(strcmp(x,"")==0)
		   goto bnl;
		  if(isnumber(x))
		  a1.bookno=atol(x);
		  else
		   {
			gotoxy(21,7);
			cprintf("    ");
			goto bnl;
		   }
		  found=find(a1.bookno);
		  if(!found)
		   {
			fp=fopen("library.dat","ab+");
			gotoxy(10,9);
			cprintf("Title:");
			gotoxy(10,11);
			cprintf("Author:");
			gotoxy(10,13);
			cprintf("ISBN NO>:");
			gotoxy(10,15);
			cprintf("Price:");
			buf[0]=20;
			ttl:
			gotoxy(21,9);
			x=cgets(buf);
			if(strcmp(x,"")==0)
			  goto ttl;
			strcpy(a1.title,x);
			buf[0]=20;
			auth:
			gotoxy(21,11);
			x=cgets(buf);
			if(strcmp(x,"")==0)
			  goto auth;
			strcpy(a1.author,x);
			buf[0]=20;
			isbnl:
			gotoxy(21,13);
			x=cgets(buf);
			if(strcmp(x,"")==0)
			  goto isbnl;
			strcpy(a1.isbn,x);
			buf[0]=20;
			prcl:
			gotoxy(21,15);
			x=cgets(buf);
			if(strcmp(x,"")==0)
			  goto prcl;
			if(isnumber(x))
			 a1.price=atof(x);
			 else
			  {
			   gotoxy(21,15);
			   cprintf("    ");
			   goto prcl;
			  }
			   a1.issued=0;
			   a1.memno=0;
			   a1.doi.dd=0;
			   a1.doi.mm=0;
			   a1.doi.yy=0;

			fwrite(&a1,sizeof(a1),1,fp);
			fflush(fp);
			fclose(fp);
			  gotoxy(2,20);
			  cprintf("\n\nBook Record Successfully Added");
			  }
			   else
				{
				 gotoxy(2,20);
				 cprintf("\n\nBook Number already exists");
				}
				 gotoxy(2,22);
				 cprintf("\n\nPress any key to continue......");
				 getch();
				}

	   void deletebook()  /********** DELETE BOOK **********/
	    {
	     char *x;
	     int n1,n2,s,i;
	     char buf[1000];
	     FILE *fp,*temp;
	     account a1;
	     int found;
	     long bookno;
	     clrscr();
	     textcolor(BLUE);
	     textbackground(YELLOW);
	     for(i=1;i<=1000;i++)
	     {
	      gotoxy(i,0);
	      cprintf(" ");
	     }
	      gotoxy(2,3);
	      cprintf("DELETE BOOK RECORD");
	      gotoxy(2,4);
	      cprintf("===================================");
	      gotoxy(10,7);
	      cprintf("Book No:");
	      buf[0]=20;
	      bnl:
	      gotoxy(21,7);
	      x=cgets(buf);
	      if(strcmp(x,"")==0)
	      goto bnl;
	      if(isnumber(x))
	      bookno=atol(x);
	      else
	      {
	       gotoxy(21,7);
	       cprintf("    ");
	       goto bnl;
	      }
	       found=find(bookno);
	       if(found)
	       {
		fp=fopen("Library.dat","rb");
		temp=fopen("temp.dat","wb");
		while(fread(&a1,sizeof(a1),1,fp)==1)
		{
		 if(bookno!=a1.bookno)
		 {
		  fwrite(&a1,sizeof(a1),1,temp);
		 }
		}
		fflush(fp);
		fflush(temp);
		fclose(fp);
		fclose(temp);
		remove("library.dat");
		rename("temp.dat","library.dat");
		gotoxy(2,20);
		cprintf("\n\nBook Record Successfully Removed");
	       }
		else
		{
		gotoxy(2,20);
		cprintf("\n\nBook Number does not exist");
		}
		gotoxy(2,22);
		cprintf("\n\nPress any key to continue.....");
		getch();
	    }
	   void editbook()  /********** Edit Book Record **********/
				  {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  int found;
				  long bookno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("EDIT BOOK RECORD");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Book No:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				 if(strcmp(x,"")==0)
				   goto bnl;
				 if(isnumber(x))
				   bookno=atol(x);
				 else
				   {
					gotoxy(21,7);
					cprintf("    ");
					goto bnl;
				   }
				   found=find(bookno);
				   if(found)
				   {
					fp=fopen("Library.dat","rb");
					temp=fopen("temp.dat","wb");

				   while(fread(&a1,sizeof(a1),1,fp)==1)
					{
					if(bookno!=a1.bookno)
					fwrite(&a1,sizeof(a1),1,temp);
					else
					{
					  gotoxy(10,9);
					   cprintf("Title:");
					   gotoxy(10,11);
					   cprintf("Author:");
					   gotoxy(10,13);
					   cprintf("ISBN No:");
					   gotoxy(10,15);
					   cprintf("price:");
					   buf[0]=20;
					   ttl:
					   gotoxy(21,9);
					   x=cgets(buf);
					   if(strcmp(x,"")==0)
						 goto ttl;
					   strcpy(a1.title,x);
					   buf[0]=20;
					   auth:
					   gotoxy(21,11);
					   x=cgets(buf);
					   if(strcmp(x,"")==0)
						  goto auth;
					   strcpy(a1.author,x);
					   buf[0]=20;
					   isbnl:
					   gotoxy(21,13);
					   x=cgets(buf);
					   if(strcmp(x,"")==0)
						  goto isbnl;
					   strcpy(a1.isbn,x);
					   buf[0]=20;
					   prcl:
					   gotoxy(21,15);
					   x=cgets(buf);
					   if(strcmp(x,"")==0)
						  goto prcl;
					  if(isnumber(x))
						 a1.price=atol(x);
					  else
					   {
						gotoxy(21,15);
						cprintf("      ");
						goto prcl;
					   }
					   a1.issued=0;
					   a1.memno=0;
					   a1.doi.dd=0;
					   a1.doi.mm=0;
					   a1.doi.yy=0;
					  fwrite(&a1,sizeof(a1),1,temp);
					  }
					  }
					   fflush(fp);
					   fflush(temp);
					   fclose(fp);
					   fclose(temp);
					   remove("library.dat");
					   rename("temp.dat","library.dat");
					   gotoxy(2,20);
					   cprintf("\n\nBook Record successfully Changed");
					   }
					   else
					   {
						gotoxy(2,20);
						cprintf("\n\nBook Number does not exist");
						}
						gotoxy(2,22);
						cprintf("\n\nPress any key to continue.....");
						getch();
						}

				int find(int bookno)         /* Find */
				 {
				   FILE *fp;
				   Account a1;
				   int found=0;
				   fp=fopen("library.dat","rb");
				   if(fp==NULL)
				   return(0);

					rewind(fp);

					  while(fread(&a1,sizeof(a1),1,fp)==1)
					  if(bookno==a1.bookno)
					  {
					   found=1; break;
					  }
					 fclose(fp);
					 return(found);
					}
					 int isnumber(char *st)
					  {
						int l,i;
						l=strlen(st);
						for(i=0;i<l;i++)
						 {
						  if(isalpha(st[i])&&st[i]!='.')
						  return(0);
						 }
						  return(1);
					   }


				  void addmember()            /* Add Member */
				  {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp;
				  account a1;
				  int found;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("ADD NEW MEMBER");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Member No:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				 if(strcmp(x,"")==0)
				   goto bnl;
				 if(isnumber(x))
				   a1.memno=atol(x);
				 else
				   {
					gotoxy(21,7);
					cprintf("    ");
					goto bnl;
				   }
				   found=findm(a1.memno);
				   if(!found)
				   {
				   fp=fopen("Member.dat","ab");
				   gotoxy(10,9);
				   cprintf("Name:");
				   gotoxy(10,11);
				   cprintf("Phone:");
				   gotoxy(10,13);
				   cprintf("Address:");

				   buf[0]=20;
				   nml:
				   gotoxy(21,9);
				   x=cgets(buf);
				   if(strcmp(x,"")==0)
					 goto nml;
				   strcpy(a1.mname,x);
				   buf[0]=20;
				   pnl:
				   gotoxy(21,11);
				   x=cgets(buf);
				   if(strcmp(x,"")==0)
						goto pnl;
					strcpy(a1.phone,x);
					buf[0]=20;
					addl:
					gotoxy(21,13);
					x=cgets(buf);
					if(strcmp(x,"")==0)
						goto addl;
					strcpy(a1.address,x);

				  fwrite(&a1,sizeof(a1),1,fp);
				  fflush(fp);
				  fclose(fp);
				  gotoxy(2,20);
				  cprintf("\n\nMember Record successfully added");
				  }
				  else
				  {
					gotoxy(2,20);
					cprintf("\n\nMember Number already exists");
				  }
				  gotoxy(2,22);
				  cprintf("\n\nPress any key to continue....");
				  getch();
				  }

				 void deletemember()             /* Delete Member Record */
				  {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  int found;
				  long memno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("DELETE MEMBER RECORD");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Member No:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				 if(strcmp(x,"")==0)
				   goto bnl;
				 if(isnumber(x))
				   memno=atol(x);
				 else
				   {
					gotoxy(21,7);
					cprintf("    ");
					goto bnl;
				   }
				   found=findm(memno);
				   if(found)
				   {
				   fp=fopen("member.dat","rb");
				   temp=fopen("temp.dat","wb");
				   deleted=0;
				   while(fread(&a1,sizeof(a1),1,fp)==1)
				   {
				   if(memno==a1.memno)
				   {
				   if(a1.issued==1)
				   {
				     deleted=1;
				     continue;
				   }
				   }

				   fwrite(&a1,sizeof(a1),1,temp);
				   }
						fflush(fp);
						fflush(temp);
						fclose(fp);
						fclose(temp);
						remove("member.dat");
						rename("temp.dat","member.dat");
						gotoxy(2,20);
						if(deleted)
						cprintf("\n\nmember record successfully removed");
						else
						cprintf("\n\nCheck Member Account");
						}
						else
						{
						gotoxy(2,20);
						cprintf("\n\member number does not exist");
						}
						gotoxy(2,22);
						cprintf("\n\nPress any key to continue....");
						getch();
					   }
					   int findm(int memno)
						{
						FILE *fp;
						account a1;
						int found=0;
						fp=fopen("member.DAT","rb");
						if(fp==NULL)
						return(0);
						while(fread(&a1,sizeof(a1),1,fp)==1)
						 {
						 if(memno==a1.memno)
						  {
						  found=1;
						  }
						  }
						  fclose(fp);
						  return(found);
						  }

				 void editmember()   /* Edit Member Record */
				 {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  int found;
				  int memno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("EDIT MEMBER RECORD");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Member No:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				 if(strcmp(x,"")==0)
				   goto bnl;
				 if(isnumber(x))
				   memno=atol(x);
				 else
				   {
					gotoxy(21,7);
					cprintf("    ");
					goto bnl;
				   }
				   found=findm(memno);
				   if(found)
				   {
				   fp=fopen("Member.dat","rb");
				   temp=fopen("temp.dat","wb");
				   while(fread(&a1,sizeof(a1),1,fp)==1)
					{
					  if(memno!=a1.memno)
					  fwrite(&a1,sizeof(a1),1,temp);
					  else
					   {
						 gotoxy(10,9);
						 cprintf("Name:");
						 gotoxy(10,11);
						 cprintf("Phone:");
						 gotoxy(10,13);
						 cprintf("Address:");
						 buf[0]=20;
						 nml:
						 gotoxy(21,9);
						 x=cgets(buf);
						 if(strcmp(x,"")==0)
						   goto nml;
						   strcpy(a1.mname,x);
						   buf[0]=20;
						   pnl:
						   gotoxy(21,11);
						   x=cgets(buf);
						 if(strcmp(x,"")==0)
						  goto pnl;
						 strcpy(a1.phone,x);
						 buf[0]=20;
						 addl:
						 gotoxy(21,13);
						 x=cgets(buf);
						if(strcmp(x,"")==0)
						  goto addl;
						  strcpy(a1.address,x);
					   fwrite(&a1,sizeof(a1),1,temp);
						}
						}
						fflush(fp);
						fflush(temp);
						fclose(fp);
						fclose(temp);
						remove("member.dat");
						rename("temp.dat","member.dat");
						gotoxy(2,20);
						cprintf("\n\nmember record successfully Changed");
						}
						else
						{
						gotoxy(2,20);
						cprintf("\n\nmember number does not exist");
						 }
					   gotoxy(2,22);
					   cprintf("\n\nPress any key to continue....");
					   getch();
					   }

				 void findbook()        /* Find Book */
				  {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp;
				  account a1;
				  int found=0;
				  long bookno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("FIND BOOK RECORD");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Title:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				 if(strcmp(x,"")==0)
				   goto bnl;
				 fp=fopen("library.dat","rb");
				   while(fread(&a1,sizeof(a1),1,fp)==1)
					{
					if(strcmp(a1.title,x)==0)
					 {
					   gotoxy(10,9);
					   cprintf("Book no:%ld",a1.bookno);
					   gotoxy(10,11);
					   cprintf("Author:%s",a1.author);
					   gotoxy(10,13);
					   cprintf("ISBN No:%s",a1.isbn);
					   gotoxy(10,15);
					   cprintf("price:%f",a1.price);
					   found=1;
					  }

					   }

					  if(found==0)
						{
						gotoxy(2,20);
						cprintf("\n\nBook Number does not exist");
						}
						fflush(fp);
						fclose(fp);

						gotoxy(2,22);
						cprintf("\n\nPress any key to continue.....");
						getch();
						}

				void findmember()       /* find member */
				 {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  int found=0;
				  int memno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("FIND MEMBER RECORD");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Mem No:");
				 buf[0]=20;
				 bnl:
				 gotoxy(21,7);
				 x=cgets(buf);
						if(strcmp(x,"")==0)
						  goto bnl;
						if(isnumber(x))
						  memno=atol(x);
						else
						 {
						   gotoxy(21,7);
						   cprintf("      ");
						   goto bnl;
						 }
						 fp=fopen("member.dat","rb");
					   while(fread(&a1,sizeof(a1),1,fp)==1)
						{
						  if(memno==a1.memno)
						   {
							gotoxy(10,9);
							cprintf("Name:%s",a1.mname);
							gotoxy(10,11);
							cprintf("Phone:%s",a1.phone);
							gotoxy(10,13);
							cprintf("Address:%s",a1.address);
							found=1;
						   }
						   }
						   if(found==0)
							{
							 gotoxy(2,20);
							 cprintf("\n\nMember Number does not exist");
							}
							 fflush(fp);
							 fclose(fp);
							 gotoxy(2,22);
							 cprintf("\n\nPress any key to continue....");
							 getch();
							}
					 long datediff(int ddi,int mmi,int yyi,int ddr,int mmr,int yyr)
					  {
					   long totdays;
					   if(ddr<ddi)
						{
						 ddr+=30;
						 mmr--;
						}
					   if(mmr<mmi)
						{
						 mmr+=12;
						 yyr--;
						}
						totdays=(yyr-yyi)+(mmr-mmi)+(ddr-ddi);
						return(totdays);
						}
			  void listallbooks()      /* List all books */
				  {
				  char *x;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp;
				  account a1;
				  int found;
				  long bookno;
				  textmode(C80);
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=2000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(32,3);
				 cprintf("SHOW BOOKS RECORD");
				 gotoxy(32,4);
				 cprintf("=================");
				 fp=fopen("Library.dat","rb");
				 gotoxy(2,6);
				 cprintf("\n BOOKNO    TITLE        AUTHOR     ISBN_NO   PRICE   ISSUE   MEMNO   DOI");
				 gotoxy(2,8);
				 cprintf("\n컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");

				 while(fread(&a1,sizeof(a1),1,fp)==1)
				  {
				   cprintf("\n\r %5ld  %-15.15s  %-10.10s  %-6.6s  %6.2f   %4d   %4d   %02d %02d %02d",
				   a1.bookno,a1.title,a1.author,a1.isbn,a1.price,
				   a1.issued,a1.memno,a1.doi.dd,a1.doi.mm,a1.doi.yy);

				   }
				   fflush(fp);
				   fclose(fp);

				   gotoxy(2,22);
				   cprintf("\n\nPress any key to continue....");
				   getch();
				  textmode(C40);
				   }

				 void issuebook()       /* Issue Book */
				 {
				  char *x;
				  struct date dt;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  int found;
				  long bookno;
				  int memno;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("ISSUE BOOK");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Mem No:");
				 buf[0]=20;
				 mnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				if(strcmp(x,"")==0)
					  goto mnl;
				if(isnumber(x))
					  memno=atol(x);
				else
				 {
				   gotoxy(21,7);
				   cprintf("      ");
				   goto bnl;
				 }
			   found=findm(memno);
			   if(!found)
				{
				 gotoxy(2,10);
				 cprintf("\n\nMember Number does not exist");
				}
			   else
				{
				  gotoxy(10,9);
				  cprintf("Book No:");
				  buf[0]=20;
				  bnl:
				  gotoxy(21,9);
				  x=cgets(buf);
				  if(strcmp(x,"")==0)
					 goto bnl;
				  if(isnumber(x))
					 bookno=atol(x);
				  else
				   {
					gotoxy(21,9);
					cprintf("      ");
					goto bnl;
				   }
				  found=find(bookno);
				  if(found)
				  {
				   fp=fopen("Library.dat","rb");
				   temp=fopen("temp.dat","wb");

				   while(fread(&a1,sizeof(a1),1,fp)==1)
				   {
					if(bookno==a1.bookno)
					 {
					  if(a1.issued==1)
					   {
						gotoxy(10,11);
						cprintf("BOOK ALREADY ISSUED");
					   }
					  else
					   {
						a1.issued=1;
						a1.memno=memno;
						getdate(&dt);
						a1.doi.dd=dt.da_day;
						a1.doi.mm=dt.da_mon;
						a1.doi.yy=dt.da_year;

						gotoxy(10,14);
						printf("BOOK ISSUED");
					   }
					 }
				 fwrite(&a1,sizeof(a1),1,temp);

				 }
				fflush(fp);
				fflush(temp);
				fclose(fp);
				fclose(temp);
				remove("Library.dat");
				rename("temp.dat","library.dat");

				 }
				 else
				 {
				 gotoxy(10,11);
				 cprintf("Book no does not exist");
				 }
				}
				gotoxy(2,22);
				cprintf("\n\nPress any key to continue.....");
				getch();
			   }

			 void receivebook()       /* Receive Book */
			  {
				  char *x;
				  struct date dt;
				  long days;
				  int n1,n2,s,i;
				  char buf[1000];
				  FILE *fp,*temp;
				  account a1;
				  //int found;
				  long bookno;
				  int memno=0;
				  clrscr();
				  textcolor(BLUE);
				  textbackground(YELLOW);
				  for(i=1;i<=1000;i++)
				   {
					gotoxy(i,0);
					cprintf(" ");
				   }
				 gotoxy(2,3);
				 cprintf("RECEIVE BOOK");
				 gotoxy(2,4);
				 cprintf("===================================");
				 gotoxy(10,7);
				 cprintf("Book No:");
				 buf[0]=20;
				 mnl:
				 gotoxy(21,7);
				 x=cgets(buf);
				if(strcmp(x,"")==0)
					  goto mnl;
				if(isnumber(x))
					  bookno=atol(x);
				else
				 {
				   gotoxy(21,7);
				   cprintf("      ");
				   goto mnl;
				 }
			      //	found=find(bookno);
				fp=fopen("library.dat","rb");
				temp=fopen("temp.dat","wb");

				 while(fread(&a1,sizeof(a1),1,fp)==1)
				  {
				   if(bookno==a1.bookno)
					{
					 if(a1.issued==0)
					  {

					 gotoxy(10,11);
					   cprintf("BOOK ALREADY AVAILABLE");
					   }
					   else
						{
						 a1.issued=0;
						 a1.memno=memno;
						 getdate(&dt);
				 days=datediff(a1.doi.dd,a1.doi.mm,a1.doi.yy,dt.da_day,dt.da_mon,dt.da_year);
				 gotoxy(10,14);
				 printf("BOOK RECEIVED AFTER %ld DAYS",days);
						   }

						}
				   fwrite(&a1,sizeof(a1),1,temp);
					}
				gotoxy(2,22);
				fflush(fp);
				fflush(temp);
				fclose(fp);
				fclose(temp);
				remove("Library.dat");
				rename("temp.dat","library.dat");
				cprintf("\n\nPress any key to continue.....");
				getch();

				 }















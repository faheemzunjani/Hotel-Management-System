// Hotel Management Software 
// Customized for The Grand Budapest Hotel
// Faheem Hassan Zunjani

#include<iostream.h>							//Header Files
#include<conio.h>
#include<graphics.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct guest								//Guest’s structure
{ char name[30];
  char roomid[5];
  int rest_bill;
  int bill;
};

struct rguest								//Restaurant’s structure
{ char roomid[5];
  int rest_bill;
};

void room_avail()							//To check room availability
{
  cleardevice();
  closegraph();

  char rrooms[][5]={"R101","R102","R103","R104","R105","R106",
		    "R107","R108","R109","R110","R111","R112","R113","R114",
		    "R115"};
  char srooms[][5]={"S201","S202","S203","S204","S205","S206",
		    "S207","S208","S209","S210","S211","S212","S213","S214",
		    "S215"};
  char prooms[][5]={"P301","P302","P303","P304","P305","P306",
		    "P307","P308","P309","P310"};
  char drooms[][5]={"D401","D402","D403","D404","D405"};


  char rtype;
  guest g;
  int i;

  cout<<"\t\t\t The Grand Budapest Hotel"<<endl;
  cout<<"\t\t\t     Room Availability"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"Room types:"<<endl;
  cout<<endl;
  cout<<"R. Ruby Deluxe"<<endl;
  cout<<"S. Sapphire Deluxe"<<endl;
  cout<<"P. Platinum Suite"<<endl;
  cout<<"D. Diamond Mansion"<<endl;
  cout<<endl;
  cout<<"Which type of room do you want? (R/S/P/D): ";
  rtype = getche();

  ifstream ifile ;
  ifile.open("guests.dat",ios::in);				//Guest’s database

  int check[15]={0};
  cout<<endl<<endl;

  cout<<"Available Rooms: ";

  switch(toupper(rtype))
  {
   case 'R':    while (!ifile.eof())
		{
		 ifile.read((char*)&g, sizeof(g));
		 for (i = 0; i<15; i++)
		 {
		  if (strcmpi(g.roomid,rrooms[i])==0)
		  {check[i] = 1;
		  }
		 }
		}

		ifile.close();

		for (i = 0; i<15; i++)
		{if (check[i]==0)
		 {cout<<rrooms[i]<<" ";
		 }
		}
		break;


      case 'S': while (!ifile.eof())
		{
		 ifile.read((char*)&g, sizeof(g));
		 for (i = 0; i<15; i++)
		 {
		  if (strcmpi(g.roomid,srooms[i])==0)
		  {check[i] = 1;
		  }
		 }
		}
		ifile.close();

		for (i = 0; i<15; i++)
		{if (check[i]==0)
		 {cout<<srooms[i]<<" ";
		 }
		}
		break;

       case 'P':while (!ifile.eof())
		{
		 ifile.read((char*)&g, sizeof(g));
		 for (i = 0; i<10; i++)
		 {
		  if (strcmpi(g.roomid,prooms[i])==0)
		  {check[i] = 1;
		  }
		 }
		}
		ifile.close();

		for (i = 0; i<10; i++)
		{if (check[i]==0)
		 {cout<<prooms[i]<<" ";
		 }
		}
		break;

	case 'D':while (!ifile.eof())
		{
		 ifile.read((char*)&g, sizeof(g));
		 for (i = 0; i<5; i++)
		 {
		  if (strcmpi(g.roomid,drooms[i])==0)
		  {check[i] = 1;
		  }
		 }
		}

		ifile.close();

		for (int j = 0; j<5; j++)
		{if (check[j]==0)
		 {cout<<drooms[j]<<" ";
		 }
		}
		break;

  }

cout<<endl<<endl<<endl<<endl<<endl<<endl;

cout<<"Press any key to go back to menu..";
getch();
}



void gen_bill(guest,int);					//Gen_bill function prototype


void disp_tar()							//Display Tariff
{
cleardevice();
setcolor(13);
rectangle(5,5,635,475);
setcolor(13);
settextstyle(3,0,5);
outtextxy(100,70,"Room Tariff(per day)");
setcolor(7);
settextstyle(3,0,3);
outtextxy(190,115,"24hrs checkout");
settextstyle(1,0,3);
outtextxy(30,200,"1. Ruby Deluxe");
outtextxy(30,220,"2. Sapphire Deluxe");
outtextxy(30,240,"3. Platinum Suite");
outtextxy(30,260,"4. Diamond Mansion");
outtextxy(500,200,"Rs 5000");
outtextxy(500,220,"Rs 7500");
outtextxy(500,240,"Rs 10000");
outtextxy(500,260,"Rs 15000");
settextstyle(1,0,2);
outtextxy(30,340,"Press any key to go back to menu..");

getch();
cleardevice();
}

void check_in()								//Check In function
{
cleardevice();
closegraph();

cout<<"\t\t      The Grand Budapest Hotel"<<endl;
cout<<endl;
cout<<"\t\t\t      Check in";
cout<<endl;
cout<<endl;

guest newg;
ofstream fout;
fout.open("guests.dat",ios::app);					//Guest’s datafile

cout<<"Enter Guest's Name: ";
gets(newg.name);
cout<<endl;
cout<<"Room Type:"<<endl;
cout<<"1. Ruby(Rxxx)"<<endl;
cout<<"2. Sapphire(Sxxx)"<<endl;
cout<<"3. Platinum(Pxxx)"<<endl;
cout<<"4. Diamond(Dxxx)"<<endl;
cout<<endl;
cout<<"Enter Room No:";
gets(newg.roomid);

newg.bill=0;
newg.rest_bill=0;

fout.write((char*)&newg,sizeof(newg));

cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Welcome to The Grand Budapest Hotel, "<<newg.name<<" !"<<endl;
cout<<"Have a luxurious stay with us!";
cout<<endl;
cout<<endl;
cout<<"Press any key to go back to menu..";


fout.close();
getch();
}



void search()							    //Guest Search function
{	
cleardevice();
closegraph();

cout<<"\t\t      The Grand Budapest Hotel"<<endl;
cout<<endl;
cout<<"\t\t\t   Guest Search";
cout<<endl;
cout<<endl;

guest sg;

ifstream fin("guests.dat",ios::in);
char sname[30];
cout<<"Enter Guest's Name:";
gets(sname);

int ck=0;

while(!fin.eof())
{
fin.read((char*)&sg,sizeof(sg));
if(!fin.eof())
if(!strcmp(sname,sg.name))
{ cout<<endl;
  cout<<endl;
  cout<<sg.name<<" is staying in room "<<sg.roomid<<" ."<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"To call "<<sg.name<<", dial 5 followed by "<<sg.roomid[1];
  cout<<sg.roomid[2]<<sg.roomid[3]<<" !";
  cout<<endl;
  ck=1;
}

}

fin.close();

if(ck==0)
{ cout<<"Guest Not Found!"<<endl;
  cout<<endl;
  cout<<endl;
}

cout<<endl<<endl<<endl<<endl<<endl;
cout<<"Press any key to go back to menu..";
getch();
}

void rest_bill(guest);						//Restaurant bill prototype

void check_out()							//Check out function
{
cleardevice();
closegraph();

cout<<"\t\t      The Grand Budapest Hotel"<<endl;
cout<<endl;
cout<<"\t\t\t      Check out";
cout<<endl;
cout<<endl;

ifstream fin("guests.dat",ios::in);

guest og;
int nd=0;
char rid[5],op;
cout<<"Enter Guest's RoomId: ";
gets(rid);
cout<<endl;
cout<<endl;

while(!fin.eof())
{ fin.read((char*)&og,sizeof(og));

  if(!strcmp(rid,og.roomid))
  { cout<<"Hello "<<og.name<<"! "<<endl;
    cout<<endl;
    cout<<"Do you want to check out? (Y/N): ";
    op=getche();
    if(op=='y'||op=='Y')
    { cout<<endl;
      cout<<"Enter No. of days stayed: ";
      cin>>nd;
      switch(og.roomid[0])
      { case 'R': og.bill=og.bill+nd*5000;
		  break;
	case 'S': og.bill=og.bill+nd*7500;
		  break;
	case 'P': og.bill=og.bill+nd*10000;
		  break;
	case 'D': og.bill=og.bill+nd*15000;
		  break;
      }

      gen_bill(og,nd);
      fin.close();

     }
   }
   else
   { fin.close();
   }
}
 guest temp;
 ofstream fout;
 ifstream fin2;
 fin2.open("guests.dat",ios::in);			//Deleting guest from datafile
 fout.open("gtemp.dat",ios::out);

 while(!fin2.eof())
 { fin2.read((char*)&temp,sizeof(temp));
   if(strcmp(temp.roomid,rid))
   { fout.write((char*)&temp,sizeof(temp));
   }
 }
 fin2.close();
 fout.close();
 remove("guests.dat");
 rename("gtemp","guests.dat");

}

void gen_bill(guest g,int nd)					//Generates Bill
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,"");

setcolor(11);
rectangle(5,5,635,475);
setcolor(14);
settextstyle(3,0,5);
outtextxy(50,10,"The Grand Budapest Hotel");

setcolor(12);
settextstyle(3,0,4);
outtextxy(250,70,"Receipt");

ifstream bfin("restbill.dat",ios::in);		    		//Restaurant’s database
rguest br;

int rbill;

while(!bfin.eof())
{ bfin.read((char*)&br,sizeof(br));
  if(!strcmp(g.roomid,br.roomid))
  {rbill=br.rest_bill;
  }
}

bfin.close();

char snd[5];
itoa(nd,snd,10);
char srcharg[10];
itoa(g.bill,srcharg,10);
char srestch[10];
itoa(rbill,srestch,10);
char stotal[15];
itoa((g.bill+rbill),stotal,10);
int amount=(g.bill+rbill)+((g.bill+rbill)*0.15);
char samount[15];
itoa(amount,samount,10);
char svat[5];
itoa(((g.bill+rbill)*0.15),svat,10);

setcolor(7);
settextstyle(1,0,2);
outtextxy(120,120,"Name:");
outtextxy(330,120,g.name);
outtextxy(120,140,"RoomId:");
outtextxy(330,140,g.roomid);
outtextxy(120,160,"No of days stayed:");
outtextxy(330,160,snd);
outtextxy(120,180,"Room charges:");
outtextxy(330,180,srcharg);
outtextxy(120,200,"Restaurant charges:");
outtextxy(330,200,srestch);
outtextxy(120,220,"Total:");
outtextxy(330,220,stotal);
outtextxy(120,240,"VAT@15%:");
outtextxy(330,240,svat);
outtextxy(120,260,"Amount:");
outtextxy(330,260,samount);
outtextxy(100,300,"Please pay Rs.");
outtextxy(330,300,samount);
outtextxy(100,350,"Thank You for staying with us!");
outtextxy(120,370,"We hope to serve you again!");
outtextxy(140,390,"Have a nice day!");
outtextxy(10,449,"Manager: FHZ");

getch();
}

void rest_bill()								//Restaurant Bill
{
cleardevice();
closegraph();


fstream file("restbill.dat",ios::in,ios::app);
file.seekg(0,ios::beg);

struct dishes
{ int code;
  char item[30];
  int price;
};

dishes d[20]={{1,"Butter Chicken",390},{2,"Fish Curry",210},
	      {3,"Prawns Curry",375},{4,"Mutton Roganjosh",220},
	      {5,"Paneer Butter Ms.",180},{6,"Paneer Tikka",190},
	      {7,"Prawns Curry",375},{8,"Veg. Kofta",220},
	      {9,"Veg. Jalfrezi",160},{10,"Malai Kofta",250},
	      {11,"Veg. Manchurian",170},{12,"Dal Makhni",180},
	      {13,"Veg. Schezwan",250},{14,"Veg. Fried Rice",200},
	      {15,"Tomato Soup",70},{16,"Hot And Sour Soup",80},
	      {17,"Chicken Biryani",290},{18,"Paneer Chillli",210},
	      {19,"Tandoori Roti",15},{20,"Stuffed Naan",30}};


cout<<"\t\t      The Grand Budapest Hotel"<<endl;
cout<<endl;
cout<<"\t\t\t Fine Dining Menu"<<endl;
cout<<endl;

int r=5,c=5;
for(int i=0;i<20;i+=2)
{
gotoxy(c,r);
cout<<d[i].code<<". "<<d[i].item;
gotoxy(c+40,r);
cout<<d[i+1].code<<". "<<d[i+1].item;
r++;
}
cout<<endl;

char ch=' ',rm[5];
int cd,pos;

rguest g,rg;
g.rest_bill=0;
rg.rest_bill=0;

gotoxy(5,20);
cout<<"Enter Guest's RoomId:";
gets(rm);

while(!file.eof())
{ file.read((char*)&g,sizeof(g));
  if(!strcmp(g.roomid,rm))
  { rg=g;
    pos=file.tellg();
  }
}

do
{
gotoxy(5,21);
cout<<"                                                ";
gotoxy(5,22);
cout<<"                                                ";
gotoxy(5,21);
cout<<"Enter dish's code: ";
cin>>cd;
rg.rest_bill=rg.rest_bill+d[cd].price;
gotoxy(5,22);
cout<<"Do you want to enter more? (Y/N):";
ch=getche();
}while(ch=='y'||ch=='Y');

cout<<endl;
cout<<"\t\t\t\t Amount: "<<rg.rest_bill<<endl;
cout<<"Press any key to go back to menu..";

file.seekg(pos-sizeof(rg),ios::beg);
file.write((char*)&rg,sizeof(rg));

file.close();

getch();
}





void disp_fac()								//Display facilities
{
cleardevice();

setcolor(9);
rectangle(5,5,635,475);
setcolor(14);
settextstyle(3,0,5);
outtextxy(50,10,"The Grand Budapest Hotel");

setcolor(12);
settextstyle(3,0,4);
outtextxy(220,70,"Amenities");

setcolor(7);
settextstyle(1,0,2);
outtextxy(160,120,"1. WiFi Enabled Rooms ");
outtextxy(160,140,"2. Complimentary Breakfast");
outtextxy(160,160,"3. Conference & Banquet Halls");
outtextxy(160,180,"4. Fine Dining Restaurant");
outtextxy(160,200,"5. Mansions With Butlers");
outtextxy(160,220,"6. Thai Spa ");
outtextxy(160,240,"7. Swimming pool");
outtextxy(160,260,"8. Recreational Games");
outtextxy(160,280,"9. Gymnasium");
outtextxy(158,300,"10. Laundry ");

outtextxy(20,420,"Press any key to go back to menu.. ");

getch();
}



void main()									//Main Function
{
int gd,gm;									//Graphics Mode
gd=DETECT;
initgraph(&gd,&gm,"");

char ch=' ';

while(ch!='8')
{
initgraph(&gd,&gm,"");
setcolor(YELLOW);
rectangle(5,5,635,475);
setcolor(LIGHTGREEN);
rectangle(10,10,630,470);

setcolor(14);
settextstyle(3,0,5);
outtextxy(50,10,"The Grand Budapest Hotel");
setcolor(LIGHTCYAN);
settextstyle(1,0,1);
outtextxy(110,58,"Alpine Mountainside, Republic Of Zubrowka");

setcolor(12);
settextstyle(4,0,4);
outtextxy(250,100,"MENU");

settextstyle(1,0,2);							//Displays Menu
setcolor(9);
outtextxy(70,150,"1. Check Room Availability");
outtextxy(70,170,"2. Display Tariff");
outtextxy(70,190,"3. Display Amenities");
outtextxy(70,210,"4. Check In");
outtextxy(70,230,"5. Search Guest");
outtextxy(70,250,"6. Restaurant Billing");
outtextxy(70,270,"7. Check Out");
outtextxy(70,290,"8. Exit");

setcolor(LIGHTMAGENTA);
outtextxy(70,360,"Enter choice:");



setcolor(CYAN);
settextstyle(1,0,1);
outtextxy(170,440,"Designed & Developed by Faheem Hassan Zunjani");

gotoxy(110,360);
ch=getch();


switch(ch)
{ case '1': room_avail();
	    break;
  case '2': disp_tar();
	    break;
  case '3': disp_fac();
	    break;
  case '4': check_in();
	    break;
  case '5': search();
	    break;
  case '6': rest_bill();
	    break;
  case '7': check_out();
	    break;
}


}

closegraph();	
}

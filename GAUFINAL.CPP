#include<fstream.h>
#include<process.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void enter_details();
void check_details();
void add_balance();
void delete_details();
void modify_details();

class METRO
{
    char name[30];
    char pincode[10];
    char address[25];
    int code;
    char date[20];
    char cardtype[10];
    float balance;
public:
    void getdata(void);
    int checkcode();
    void getbal();
    void display();
    void mod();
    void add();
    METRO()
    {
        strcpy(name,"Not Provided");
        strcpy(pincode,"Not Provided");
        strcpy(address,"Not Provided");
        code=0;
        strcpy(date,"Not Provided");
        strcpy(cardtype,"Not Provided");
        balance=0.0;
    }
} m,n;

fstream f,f1;
void METRO::add()
{
    int x;
    gotoxy(15,6);
    cout<<"ENTER the amount :- "<<endl<<endl;
    gotoxy(15,8);
    cout<<"Rs. ";
    cin>>x;
    balance+=x;
}

void METRO::getbal()
{
    if(strcmpi(cardtype,"gold")==0)
    {
        balance=1000.0;
    }
    else if(strcmpi(cardtype,"silver")==0)
    {
        balance=500.0;
    }
    else
    {
        balance=100.0;
    }
}
void METRO::mod()
{
    char name2[20],address2[20],pincode2[20];
    gotoxy(15,6);
    cout<<"ENTER the DETAILS as asked:- "<<endl<<endl;
    gotoxy(15,8);
    cout<<"New NAME (Press & to retain): ";
    gets(name2);
    cout<<endl;
    gotoxy(15,9);
    cout<<"New ADDRESS (Press $ ENTER to retain): ";
    gets(address2);
    gotoxy(15,10);
    cout<<"New PINCODE (Press * to retain): ";
    gets(pincode2);
    cout<<endl;
    gotoxy(15,11);
    if(strcmpi(name2,"&")!=0)
        strcpy(name,name2);
    if(strcmpi(address2,"$")!=0)
        strcpy(address,address2);
    if(strcmpi(pincode2,"*")!=0)
        strcpy(pincode,pincode2);
}
void METRO::getdata()
{
    gotoxy(15,3);
    cout<<"ENTER the Details as follows:";
    gotoxy(15,5);
    cout<<"NAME:";
    gets(name);
    gotoxy(15,6);
    cout<<"ADDRESS:";
    gets(address);
    gotoxy(15,7);
    cout<<"PIN-CODE:";
    gets(pincode);
    gotoxy(15,8);
    cout<<"CARD-TYPE (GOLD/SILVER/BRONZE):";
    gets(cardtype);
    gotoxy(15,9);
    cout<<"CARD-CODE:";
    randomize();
    code=random(1255);
    cout<<code;
    cout<<" (Memorize this)";
    gotoxy(15,10);
    cout<<"DATE of Creation (DD/MM/YYYY): ";
    gets(date);
    gotoxy(15,11);
    cout<<"BALANCE: ";
    getbal();
    cout<<balance;
}
int METRO::checkcode()
{
    return code;
}
void METRO::display()
{
    gotoxy(15,5);
    cout<<"The Details are as follows:";
    cout<<endl;
    gotoxy(15,6);
    cout<<"NAME: ";
    puts(name);
    cout<<endl;
    gotoxy(15,7);
    cout<<"ADDRESS: ";
    puts(address);
    cout<<endl;
    gotoxy(15,8);
    cout<<"PIN-CODE: ";
    puts(pincode);
    cout<<endl;
    gotoxy(15,9);
    cout<<"CARD-TYPE: ";
    puts(cardtype);
    cout<<endl;
    gotoxy(15,10);
    cout<<"CARD-Code: ";
    cout<<code;
    cout<<endl;
    gotoxy(15,11);
    cout<<"DATE of Creation:(DD/MM/YYYY): ";
    puts(date);
    cout<<endl;
    gotoxy(15,12);
    cout<<"BALANCE: ";
    cout<<balance;
    cout<<endl;
}
void border()
{
    clrscr();
    for (int i=2; i<80; i++)
    {
        gotoxy(i,3);
        cout<<">";
        gotoxy(i,23);
        cout<<"<";
    }
    for (i=4; i<23; i++)
    {
        gotoxy(2,i);
        cout<<"A";
        gotoxy(79,i);
        cout<<"V";
    }
}
void welcome()
{
    char m='*';
    do
    {
        cout<<endl<<endl<<endl<<endl ;
        cout<<"       MM     MM    EEEEEE    TTTTTT   RRRRRR       OOO                  ";
        cout<<endl;
        cout<<"       MMM   MMM    E           T      RR    R     OO   O                ";
        cout<<endl;
        cout<<"       MM M M  M    E           T      R     R    OO     O               ";
        cout<<endl;
        cout<<"       MM  M   M    EEEE        T      RRRRR      OO     O               ";
        cout<<endl;
        cout<<"       MM      M    E           T      RR   R     OO     O               ";
        cout<<endl;
        cout<<"       MM      M    E           T      RR    R     OO   O                ";
        cout<<endl;
        cout<<"       MM      M    EEEEEE      T      RR    R       OOO                 ";
        cout<<endl<<endl;

        cout<< "                     D    E    L    H    I                ";
        cout<<endl;
        cout<<"   NOW FROM VAISHALI TO NOIDA SECTOR-9 & SHAHDARA TO TILAK NAGAR   ";
        cout<<endl;
        cout<<endl<<endl;
        cout<<"The following project has been made/developed by Gaurav Dhawan (C)";
        cout<<endl;
        cout<<"under the guidance of Ms.Deepica (C++ Teacher) at , NEPS Computer Labs.";
        cout<<endl;
        cout<<"REFERENCE/HELP :";
        cout<<endl;
        cout<<"www.google.com";
        cout<<endl;
        cout<<"www.slideshare.com";
        cout<<endl;
        cout<<"Press any key to continue :";
        m=getch();
    }
    while(m=='*');
}
void main()
{
    int ch;
    clrscr();
    char ch1='y';
    welcome();
    do
    {
        border();
        gotoxy(30,5);
        cout<<"         MAIN MENU       ";
        for (int z=29; z<=60; z++)
        {
            gotoxy(z,6);
            cout<<"-";
        }
        gotoxy(20,7);
        cout<<"1.  CARD REGISTERATION";
        gotoxy(20,8);
        cout<<"2.  CHECK Details";
        gotoxy(20,9);
        cout<<"3.  DELETE Records";
        gotoxy(20,10);
        cout<<"4.  MODIFY Records";
        gotoxy(20,11);
        cout<<"5.  ADD balance";
        gotoxy(20,12);
        cout<<"6.  EXIT";
        gotoxy(20,19);
        cout<<"ENTER YOUR CHOICE:";
        cout<<endl;
        gotoxy(20,20);
        cin>>ch;
        switch(ch)
        {
        case 1:
            enter_details();
            break;
        case 2:
            check_details();
            break;
        case 3:
            delete_details();
            break;
        case 4:
            modify_details();
            break;
        case 5:
            add_balance();
        case 6:
            exit(0);
            break;
        default:
            cout<<"WRONG CHOICE!"<<endl;
        };
    }
    while(ch1=='y');
    clrscr();
}

void enter_details()
{
    char l='y';
    f.open("Metro.dat",ios::app|ios::binary);
    do
    {
        clrscr();
        border();
        m.getdata();
        f.write((char*)&m,sizeof(m));
        f.close();
        gotoxy(10,14);
        cout<<"Details have been saved. ";
        cout<<endl;
        gotoxy(10,15);
        cout<<"Want to save any other details :";
        cout<<endl;
        l=getch();
    }
    while(l=='y');
    clrscr();
}
void check_details()
{
    char p='y';
    int mcode,t;
    gotoxy(28,2);
    cout<<"DETAILS CHECK";
    do
    {
        clrscr();
        border();
        f.open("Metro.dat",ios::in|ios::binary);
        int r,t=0;
        gotoxy(15,3);
        cout<<"ENTER THE CODE TO SEARCH:"<<endl;
        gotoxy(15,4);
        cin>>mcode;
        while(!f.eof())
        {
            f.read((char*)&m,sizeof(m));
            if(m.checkcode()==mcode)
            {
                t=1;
                gotoxy(20,7);
                m.display();
                break;
            }
        }
        if(t==0)
        {
            gotoxy(15,7);
            cout<<"Sorry , we donot have any such record.";
        }
        f.close();
        gotoxy(20,19);
        cout<<"Do you wish to continue?";
        p=getch();
    }
    while(p=='y');
    clrscr();
}
void delete_details()
{
    int mc,cnfm,mcode;
    char l='y';
    do
    {
        clrscr();
        border();
        gotoxy(28,2);
        cout<<"DELETING RECORDS:";
        gotoxy(15,3);
        cout<<"Enter the CARD CODE to DELETE:"<<endl;
        gotoxy(15,6);
        cin>>mc;
        int s=0;
        f.open("Metro.dat",ios::in|ios::binary);
        while(!f.eof())
        {
            f.read((char*)&m,sizeof(m));
            if(m.checkcode()==mc)
            {
                s=1;
                break;
            }
            else
            {
            }
        } f.close();
        if(s==1)
        {
            f.open("Metro.dat",ios::in|ios::binary);
            f1.open("copy.dat",ios::app|ios::out|ios::binary);
            while(!f.eof())
            {
                f.read((char*)&m,sizeof(m));
                if(m.checkcode()!=mc)
                {
                    f1.write((char*)&m,sizeof(m));
                }
            }
            gotoxy(20,8);
            m.display();
            gotoxy(15,13);
            cout<<"Details have been succesfully DELETED.";

        }
        else
        {

            gotoxy(25,5);
            cout<<"We donot have any such record. ";
        }
        f1.close();
        f.close();
        remove("Metro.dat");
        rename("copy.dat","Metro.dat");
        gotoxy(20,14);
        cout<<"Want to DELETE any other details:"<<endl;
        l=getch();
    }
    while(l=='y');
    clrscr();
}
void modify_details()
{
    char l='y';
    int mcode2;
    int found=0;
    f.open("Metro.dat",ios::in|ios::out|ios::binary);
    do
    {
        clrscr();
        border();
        gotoxy(15,3);
        cout<<" ENTER THE CODE TO MODIFY:";
        cout<<endl;
        gotoxy(24,4);
        cin>>mcode2;
        long pos;
        while(!f.eof())
        {
            pos=f.tellg();
            f.read((char *)&m,sizeof(m));
            if(m.checkcode()==mcode2)
            {
                m.mod();
                f.seekg(pos);
                f.write((char *)&m,sizeof(m));
                found=1;
                break;
            }
        }
        if(found==1)
        {
            cout<<"Details have been modified!";
        }
        else
        {
            gotoxy(15,5);
            cout<<"Details unavailable!";
        }


        f.seekg(0);

        f.close();
        gotoxy(15,14);
        cout<<"Want to MODIFY any other details:"<<endl;
        l=getch();
    }
    while(l=='y');
    clrscr();
}
void add_balance()
{
    char p='y';
    int mcode3;
    int found=0;

    do
    {
        clrscr();
        border();
        gotoxy(15,3);
        f.open("Metro.dat",ios::in|ios::out|ios::binary);
        cout<<" ENTER THE CODE TO ADD Balance:";
        cout<<endl;
        gotoxy(24,4);
        cin>>mcode3;
        long pos;
        while(!f.eof())
        {
            pos=f.tellg();
            f.read((char *)&m,sizeof(m));
            if(m.checkcode()==mcode3)
            {
                m.add();
                f.seekp(pos);
                f.write((char *)&m,sizeof(m));
                found=1;
                break;
            }
        }
        if(found==1)
        {
            gotoxy(15,9);
            cout<<"BALANCE has been modified!";
        }
        else
        {
            gotoxy(15,5);
            cout<<"Details unavailable!";
        }


        f.seekg(0);

        f.close();
        gotoxy(15,14);
        cout<<"Want to ADD more Balance:"<<endl;
        p=getch();
    }
    while(p=='y');
    clrscr();
}


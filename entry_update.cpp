#include<iostream>
#include<windows.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<cstdio>
#include<string>
#include"encrypt.cpp"
COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void cnew();
void ench(char[],int);
void login();
void delay(int);
void dech(char[],int);
//void verify(int);
using namespace std;
void cnew()
{
    string filename,line;
    cout << "Please enter a username(Without Spaces) : ";
    cin>>filename;
    filename += ".cyan_extension";
    ifstream f;
    f.open( filename.c_str() );
    if(f.is_open())
    {
        while(std::getline(f,line))
        {
            f>>line;
        }
    }
    f.close();
    if(line.empty())
    {
    ofstream f;
    f.open( filename.c_str() );
    char pss[20];
    lb:cout<<"Enter the password (Without Spaces): ";
    cin>>pss;
    if(strlen(pss)<8)
    {
        cout<<"Password smaller than 8 chars try again\n";
        goto lb;
    }
    ench(pss,strlen(pss));
    f << pss;
    cout<<"Account Created successfully\n";
    f.close();
    system("pause");
    system("cls");
    return;
    }
    else
    {
            cout<<"Username taken....try again\n";
            system("pause");
            system("cls");
            cnew();
    }
}
void login()
{
    char tmp1[20];
    string uname,pass,line,tnames,line_alias;
    cout<<setw(15)<<"\t\t"<<"Login\n";
    cout<<"1->Enter Username : ";
    cin>>uname;
    cout<<"\n2->Enter Password : ";
    cin>>pass;
    fstream f;
    tnames=uname;
    uname += ".cyan_extension";
    f.open( uname.c_str(),ios::in|ios::out );
    if(f.is_open())
    {
        while(std::getline(f,line))
        {
            f>>line;
        }
    }
   line_alias=line;
   strcpy(tmp1,line.c_str());
   dech(tmp1,strlen(tmp1));
   line = string(tmp1);
   system("cls");
   if(line.empty())
   {
       cout<<"Username does not exist\n";
       system("pause");
       system("cls");
       return;
   }
   else if(pass!=line)
   {
       cout<<"Wrong Password\n";
       system("pause");
       system("cls");
       return;
   }
   else
   {
    f.close();
    int x;
    char vs[15];
    string list_view,lv;
    strcpy(vs,tnames.c_str());
    list_view= strrev(vs);
    list_view+=tnames;
    char ch,cho,a[15],tp1[15],tp2[15],store_down[500],comms[50];
    string nusr,pas1,pas,chpas,nsr,ch2,retrieve_date,new_date,new_date1,store;
    fstream f;
    f.open(uname.c_str());
    bl:do{
    cout<<setw(15)<<"\t\t\t"<<"WELCOME "<<tnames<<"\n";
    cout<<"1->Update Username\n";
    cout<<"2->Update Password\n";
    cout<<"3->Manage Entries\n";
    cout<<"4->Logout\n";
    cout<<"5->Delete Account\n";
    cout<<"6->Print Source Code\n";
    cin>>x;
    system("cls");
    if(x==1)
    {
        cout<<"Enter new username(Without Spaces)\n";
        cin>>nusr;
        nsr=nusr;
        cout<<"\nDo u really want to change your username from "<<tnames<<" to "<<nusr<<"\n";
        nusr += ".cyan_extension";
        cout<<"\nEnter yes or no\n";
        cin>>ch;
        if(ch=='Y'||'y')
        {
            f.close();

            std::remove(uname.c_str());
            ofstream f;
            f.open(nusr.c_str());
            f<<line_alias;
            tnames = nsr;
            uname=nusr;
            cout<<"Username successfully changed\n";
            system("pause");
            system("cls");
        }
        else goto bl;
    }
    if(x==2)
    {
        cout<<"Enter current password : ";
        cin>>chpas;
        strcpy(tp2,chpas.c_str());
        ench(tp2,strlen(tp2));
        chpas = string(tp2);
        if(chpas==line_alias)
        {
        cout<<"Enter new password (Without Spaces) : ";
        cin>>pas;
        strcpy(tp1,pas.c_str());
        ench(tp1,strlen(tp1));
        pas = string(tp1);
        f.clear();
        ofstream f;
        f.open( uname.c_str() );
        f<<pas;
        cout<<"Password updated successfully\n";
        line_alias = string(pas);
        system("pause");
        system("cls");
        }
        else
        {
            cout<<"Wrong Password\n";
            f.close();
            system("pause");
            system("cls");
            return;
        }
    }
    if(x==3)
    {
        int en_ch;
        char str[500];
        cout<<"\t\t\tWELCOME TO YOUR PERSONAL DIARY\n\n";
        cout<<"1-> View a previous entry\n";
        cout<<"2-> Add a new entry\n";
        cout<<"3-> List all entries\n";
        cin>>en_ch;
        system("cls");
        if(en_ch==1)
        {
            cout<<"\nEnter the date you want view (FORMAT:dd-mm-yyyy): ";
            cin>>retrieve_date;
            retrieve_date+=tnames;
            ifstream f;
            f.open(retrieve_date.c_str());
            if(f.is_open())
            {
                while(std::getline(f,store))
                {
                    f>>store;
                }
            system("cls");
            strcpy(str,store.c_str());
            dech(str,strlen(str));
            cout<<"\n"<<str<<"\n\n\n\n\n\n\n";
            }
            else cout<<"\nSorry :( Specified file does not exist\n";
            system("pause");
            system("cls");
            f.close();
        }
        if(en_ch==2)
        {

            cout<<"Enter the date for the entry (FORMAT:dd-mm-yyyy): ";
            cin>>new_date;
            system("cls");
            new_date1=new_date+tnames;
            //list_view+=tnames;
            cout<<"\t\t\t\tEnter the record\n\n";
            fflush(stdin);
            gets(store_down);
            //verify(strlen(store_down));
            ench(store_down,strlen(store_down));
            ofstream f;
            f.open(new_date1.c_str());
            f<<store_down;
            f.close();
            cout<<"\n\nEnter any special comments(if any) for this record\n";
            fflush(stdin);
            gets(comms);
            ofstream f1;
            f1.open(list_view.c_str(),ios::app);
            f1<<new_date;
            f1<<"\t\t";
            f1<<comms;
            f1<<"\n";
            f1.close();
            cout<<"\n\nYour record for the date "<<new_date<<" is being encrypted via 64-bit XOR wait a moment..\n";
            int n1=0;
            while(n1<12)
            {
                delay(9000);
                cout<<"*";
                delay(9000);
                cout<<"$";
                n1++;
            }
            system("cls");
        }
        if(en_ch==3)
        {
            ifstream f2;
            f2.open(list_view.c_str(),ios::out);
            if(f2.is_open())
            {
                while(std::getline(f2,lv))
                {
                    f2>>lv;
                }
                cout<<"Date of Entry\t\t"<<"Comments\n\n";
                cout<<lv<<"\n\n";
                f2.close();
            }
            else{
                cout<<"You don't have any entries right now\n";
                f2.close(); }
                system("pause");
                system("cls");


        }

    }
    if(x==4)
    {
        cout<<"You have logged out successfully\n";
        system("pause");
        system("cls");
        f.close();
        fflush(stdin);
        return;
    }
    if(x == 5)
    {
        cout<<"Do you really want to delete your account\n";
        cout<<"\nEnter Y or N\n";
        cin>>ch2;
        if(ch2 == "y")
        {
            cout<<"\nEnter current password\n";
            cin>>pas1;
            strcpy(tp2,pas1.c_str());
            ench(tp2,strlen(tp2));
            pas1 = string(tp2);
            if(pas1==line_alias)
            {
                f.close();
                std::remove(uname.c_str());
                cout<<"\nAccount Deleted Successfully\n";
                system("pause");
                system("cls");
                return;
            }
            else
            {
                cout<<"\nWrong password.....don't fuck with others account.....kicking u out\n";
                system("pause");
                system("cls");
                return;
            }

        }
        else
        {
            cout<<"Please select a valid option!!\n";
            system("pause");
            system("cls");

            goto bl;
        }
    }
    if(x==6)
    {
        int cntr=5;
        cout<<"Generating source code in\n";
        while(cntr>0)
        {
            gotoxy(0,2);
            cout<<cntr;
            cntr--;
            delay(10000);
        }
        system("cls");
        cout<<"\n\n";
        FILE *fp;
        char c;
        fp = fopen("entry_update.cpp","r");
        do
        {
            c = getc(fp);
            putchar(c);
        }
        while(c!=EOF);
        fclose(fp);
        system("pause");
        system("cls");
    }
    }while(1);
   }

}
void delay(int x)
{
    for(int i=x;i>0;i--)
        for(int j=x;j>0;j--)
    {

    }
}
int main()
{
    cout<<"This is a small console project developed by the\n\n";
    delay(20000);
    system("cls");
    int a=0;
    while(a<11)
    {
        delay(2500);
        cout<<"M\n";
        delay(2500);
        a++;
    }
    a=0;
    gotoxy(1,0);
    while(a<5)
    {
        delay(2500);
        cout<<"M";
        delay(2500);
        a++;
    }
    gotoxy(5,1);
    a=1;
    int b=0;
    while(b<5)
    {
        delay(2500);
        cout<<"M";
        gotoxy(5,++a);
        delay(2500);
        b++;
    }
    a=0;
    gotoxy(6,0);
    while(a<5)
    {
        delay(2500);
        cout<<"M";
        delay(2500);
        a++;
    }
    a=0,b=1;
    gotoxy(10,1);
    while(a<10)
    {
        delay(2500);
        cout<<"M";
        gotoxy(10,++b);
        delay(2500);
        a++;
    }
    b=22,a=0;
    gotoxy(22,0);
    while(a<8)
    {
        delay(2500);
        cout<<"S";
        gotoxy(--b,0);
        delay(2500);
        a++;
    }
    a=0,b=0;
    gotoxy(14,0);
    while(a<5)
    {
        delay(2500);
        cout<<"S";
        gotoxy(14,++b);
        delay(2500);
        a++;
    }
    a=0,b=14;
    gotoxy(14,5);
    while(a<8)
    {
        delay(2500);
        cout<<"S";
        gotoxy(++b,5);
        delay(2500);
        a++;
    }
    a=0,b=5;
    gotoxy(22,5);
    while(a<5)
    {
        delay(2500);
        cout<<"S";
        gotoxy(22,++b);
        delay(2500);
        a++;
    }
    b=22,a=0;
    gotoxy(22,10);
    while(a<9)
    {
        delay(2500);
        cout<<"S";
        gotoxy(--b,10);
        delay(2500);
        a++;
    }
    gotoxy(0,20);
    cout<<"Be patient...Initializing the data into program buffer";
    gotoxy(0,25);
    a=0;
    string q="v";
    while(a<3)
    {
        for(int i=0;i<15;i++)
        {
            delay(6000);
            cout<<q;
        }
        gotoxy(0,25);
        ++a;
        if(a==1)
        q="^";
        else q="-";
    }
    system("cls");
    int x;
    lpb:do{
    cout<<setw(20)<<"\t\t\t"<<"WELCOME\n";
    cout<<endl;
    cout<<"1->Login\n";
    cout<<endl;
    cout<<"2->Create new Account\n";
    cout<<endl;
    cout<<"3->Exit\n";
    cout<<endl;
    cin>>x;
    system("cls");
    if(x==1)
    {
        login();
    }
    if(x==2)
    {
        cnew();
    }
    if(x==3)
    {
        exit(0);
    }
    if(x!=1||2||3)
    {
	cout<<"Wrong Option\n";
	system("cls");
    goto lpb;
    }

    }while(x>0&&x<4);
    return 0;
}

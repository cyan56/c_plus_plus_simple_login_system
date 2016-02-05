#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<cstdio>
#include<string>
#include"encrypt.cpp"
void cnew();
void ench(char[],int);
void login();
void dech(char[],int);
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
    char ch,cho,a[15],tp1[15],tp2[15];
    string nusr,pas1,pas,chpas,nsr,ch2;
    fstream f;
    f.open(uname.c_str());
    bl:do{
    cout<<setw(15)<<"\t\t\t"<<"WELCOME "<<tnames<<"\n";
    cout<<"1->Update Username\n";
    cout<<"2->Update Password\n";
    cout<<"3->Logout\n";
    cout<<"4->Delete Account\n";
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
        cout<<"You have logged out successfully\n";
        system("pause");
        system("cls");
        f.close();
        return;
    }
    if(x == 4)
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
                cout<<"\nWrong password......kicking u out\n";
                system("pause");
                system("cls");
                return;
            }

        }
        else
        {
            system("cls");
            goto bl;
        }
    }
    }while(x>0&&x<5);
   }

}
int main()
{
    int x;
    do{
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
    }while(x>0&&x<4);
    return 0;
}

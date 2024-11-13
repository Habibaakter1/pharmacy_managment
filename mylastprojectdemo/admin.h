#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include<conio.h>
#include"user.h"
#include"product.h"

class ADMIN : public USER
{
private:
    string password;
    string user_id;
    PRODUCT p;
public:
    ADMIN();
    void getdata();
    void display_menu();
    void user_func();
    int login();
};

#endif // ADMIN_H_INCLUDED
ADMIN :: ADMIN() {}
void ADMIN :: getdata()
{
    system("cls");
    cout<<"\n\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\tADMIN LOGIN"<<endl;
    cout<<"\t\t\t----------------------------------"<<endl;
    cout<<"\n\t\t\tUser ID : ";
    cin>>user_id;
    cout<<"\n\t\t\tPassword : ";
    cin>>password;
}
int ADMIN :: login()
{
    if(user_id=="Sumaia" && password=="529133")
    {
        return 0;
    }
    else
    {
        cout<<"\n\tInvalid user ID and password, try again!"<<endl;
        sleep(1);
        return 1;
    }
}
void ADMIN :: display_menu()
{
    system("cls");
    cout<<"\n\t\t\t==========================================="<<endl;
    cout<<  "\t\t\t|              ADMIN MENU                 |"<<endl;
    cout<<  "\t\t\t==========================================="<<endl;
    cout<<"\n\t\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\t\t  1. Show Medicine list "<<endl;
    cout<<"\t\t\t  2. Add Medicine to Stock "<<endl;
    cout<<"\t\t\t  3. Delete Medicine from Stock  "<<endl;
    cout<<"\t\t\t  4. Update Medicine Information   "<<endl;
    cout<<"\t\t\t  5. Search Medicine in Stock"<<endl;
    cout<<"\t\t\t  6. Exit"<<endl;
    cout<<"\n\t\t-----------------------------------------------------------------"<<endl;
    cout<<"\n\n\nEnter your choice : ";
}
void ADMIN :: user_func()
{
    getdata();
    while(login())
    {
        getdata();
    }
    cout<<"\n\t\tSuccessfully logged in!......Press any key to continue.......";
    getch();
st:
    display_menu();
    int c;
    c=getche();
    {
        if(c=='1')
        {
            system("cls");
            p.show_list();
        }
        else if(c=='2')
        {
            system("cls");
            p.add_product();
        }
        else if(c=='3')
            p.delete_product();
        else if(c=='4')
            p.update_product();
        else if(c=='5')
            p.search_product();
        else if(c=='6')
            return;
        cout<<"\n\nPress any key to continue..........."<<endl;
        getch();
            goto st;
    }
}

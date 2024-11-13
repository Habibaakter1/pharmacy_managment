#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "user.h"
#include "order.h"
class CUSTOMER : public USER
{
protected:
    string cname;
    string address;
public:
    CUSTOMER();
    void getdata();
    void display_menu();
    void user_func();
};
class ORDER
{
protected:
    int id;
    int amount;
    string order_date;
public:
    ORDER();
    void getdata();
    void order_item(vector<pair<PRODUCT*,int>>&);
    void display_bill(vector<pair<PRODUCT*,int>>&order_list,string,string);
};

CUSTOMER::CUSTOMER()
{
}
void CUSTOMER :: getdata()
{
    system("cls");
    cout<<"\n\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\tCUSTOMER LOGIN"<<endl;
    cout<<"\t\t\t----------------------------------\n"<<endl;
    cout<<"\t\tEnter your name : ";
    getchar();
    getline(cin,cname);
    cout<<"\t\tEnter your address : ";
    getline(cin,address);
}
void CUSTOMER :: display_menu()
{
    system("cls");
    cout<<"\n\t\t\t==========================================="<<endl;
    cout<<  "\t\t\t|            CUSTOMER MENU                |"<<endl;
    cout<<  "\t\t\t==========================================="<<endl;
    cout<<"\n\t\t-----------------------------------------------------------------\n"<<endl;
    cout<<"\t\t\t  1. Show Medicine list "<<endl;
    cout<<"\t\t\t  2. Order medicines "<<endl;
    cout<<"\t\t\t  3. Search medicines  "<<endl;
    cout<<"\t\t\t  4. Exit"<<endl;
    cout<<"\n\t\t-----------------------------------------------------------------"<<endl;
    cout<<"\n\n\nEnter your choice : ";
}
void CUSTOMER :: user_func()
{
    PRODUCT p;
    getdata();
    cout<<"\nThanks for the details!"<<endl;cout<<"Press any key to continue.........."<<endl;
    getch();
st:
    system("cls");
    display_menu();
    int c;
    c=getche();
    if(c=='1')
    {
        system("cls");
        p.show_list();
    }
    else if(c=='2')
    {
        ORDER o;
        vector<pair<PRODUCT*,int>>order_list;
        system("cls");
        p.show_list();
        o.order_item(order_list);
        o.display_bill(order_list,cname,address);
    }
    else if(c=='3')
    {
        p.search_product();
    }
    else if(c=='4')
    {
        return;
    }
    cout<<"Press any key to continue..........."<<endl;
    getch();
    goto st;
}
ORDER::ORDER()
{
    //ctor
}
void ORDER :: getdata()
{
    cout<<"\nEnter the items' information you want to purchase : "<<endl;
    cout<<"Product ID : ";
    cin>>id;
    cout<<"Product amount : ";
    cin>>amount;
}
void ORDER :: order_item(vector<pair<PRODUCT*,int>>&order_list)
{
    cout<<"Enter the date : ";
    cin>>order_date;
    while(1)
    {
        st:
        getdata();
            if(alldata[id]==0)
            {
                alldata.erase(id);
                cout<<"Not available in stock!"<<endl;
                goto st;
            }
            if(alldata[id]->getamount()<amount)
            {
                cout<<"Not enough product in stock! please try another!"<<endl;
                goto st;
            }
            order_list.push_back(make_pair(alldata[id],amount));
        cout<<"Want to order more? (y/n) "<<endl;
        char c;
        cin>>c;
        if(c=='n')
            break;
    }
}

void ORDER :: display_bill(vector<pair<PRODUCT*,int>>&order_list,string name,string address)
{
    int total_bill=0;
    PRODUCT p;
    system("cls");
    cout<<"\t\t\t\t\tRECEIPT OF PURCHASE"<<endl;
    cout<<"\t\t\t==============================================="<<endl;
    cout<<"Customer's name      : "<<name<<endl;
    cout<<"Customer's address   : "<<address<<endl;
    cout<<"Order date           : "<<order_date<<endl;
     cout<<"\n _______________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"\n | MEDICINE ID |"<<setw(20)<<std:: right<<"MEDICINE NAME |"<<setw(20)<<std:: right<<"MEDICINE TYPE |"
    <<setw(20)<<std:: right<<"COMPANY NAME |"<<setw(25)<<std:: right<<"PER-UNIT COST(TK) |"<<setw(20)<<std:: right<<"STOCK AMOUNT |"<<setw(20)<<std:: right<<"PURCHASE AMOUNT"<<endl;
    cout<<" __________________________________________________________________________________________________________________________________________________\n"<<endl;

    for(int i=0; i<order_list.size(); i++)
    {
        PRODUCT*p=order_list[i].first;
        p->putdata();
        p->changeamount(order_list[i].second);
        if(p->getamount()==0)
        {
            alldata.erase(p->getID());
        }
        cout<<setw(20)<<std:: right<<order_list[i].second<<endl;
        total_bill+=(order_list[i].first->getcost()*order_list[i].second);
    }
    cout<<" __________________________________________________________________________________________________________________________________________________\n"<<endl;
    cout<<"total bill : "<<total_bill<<" tk only!\n"<<endl;

}

#endif // CUSTOMER_H_INCLUDED

#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
void load_data();
void getdataToFlie();
class PRODUCT
{
protected:
    char pname[25];
    int pID;
    char ptype[20];
    char company[25];
    int cost;
    int number_of_item;
public:
    PRODUCT();
    int getID();
    int getcost();
    int getamount();
    int checkname(char*);
    void changeamount(int x);
    void getdata();
    void putdata();
    void add_product();
    void show_list();
    void delete_product();
    void update_product();
    void search_product();
};
map<int,PRODUCT*>alldata;
void load_data()
{
    ifstream f;
    f.open("productDetails.dat", ios::in | ios::binary);  ///use of files
    f.seekg(0);
    if(f)
    {
        while(!f.eof())
        {
            PRODUCT* p=new PRODUCT;
            f.read(reinterpret_cast<char*>(p),sizeof(*p));
            alldata[p->getID()]=p;
        }
        alldata.erase(0);
    }
    f.close();
}
void getdataToFlie()
{
    ofstream f;
    f.open("productDetails.dat", ios::out | ios::binary);
    for(auto i=alldata.begin(); i!=alldata.end(); i++)
    {
        PRODUCT p = *(i->second);
        //p.putdata();
        f.write(reinterpret_cast<char*>(&p),sizeof(p));

    }
}
void first_screen()
{
    cout<<"\n\n\t\t\t\tWELCOME TO MEDICINE SHOP "<<endl;
    cout<<"\t\t======================================================\n"<<endl;
    cout<<"\t\t\t------------------------------------"<<endl;
    cout<<"\t\t\t|     1.ADMIN LOGIN\t   \t   |"<<endl;
    cout<<"\t\t\t|                   \t\t   |"<<endl;
    cout<<"\t\t\t|     2.CUSTOMER LOGIN\t\t   |"<<endl;
    cout<<"\t\t\t|                   \t\t   |"<<endl;
    cout<<"\t\t\t------------------------------------"<<endl;
    cout<<"\nEnter your choice : ";
}
PRODUCT :: PRODUCT() {}
int PRODUCT :: checkname(char* c)
{
    if(strcmp(c,pname)==0)
        return 0;
    return 1;
}
int PRODUCT :: getcost()
{
    return cost;
}
void PRODUCT :: getdata()
{
    cout<<"Product name : ";
    cin>>pname;
    cout<<"Product ID   : ";
    cin>>pID;
    cout<<"Product type : ";
    cin>>ptype;
    cout<<"Company name : ";
    cin>>company;
    cout<<"Per unit cost: ";
    cin>>cost;
    cout<<"number of item : ";
    cin>>number_of_item;
}
int PRODUCT :: getID()
{
    return pID;
}
void PRODUCT :: changeamount(int x)
{
    number_of_item-=x;
}
int PRODUCT :: getamount()
{
    return number_of_item;
}
void PRODUCT :: putdata()
{
    //cout<<setw(3)<<pID<<setw(15)<<pname<<setw(15)<<ptype<<setw(20)<<company<<setw(10)<<cost<<setw(20)<<number_of_item;
    cout<<setw(13)<<std:: right<<pID<<setw(20)<<std:: right<<pname<<setw(20)<<std:: right<<ptype<<setw(20)<<std:: right<<company
    <<setw(25)<<std:: right<<cost<<setw(20)<<std:: right<<number_of_item;
}
void PRODUCT :: show_list()
{
    cout<<"\n\t\t\t\t\t\t MEDICINE LIST"<<endl;
    cout<<"\t\t\t\t\t============================"<<endl;
    cout<<"\n _______________________________________________________________________________________________________________________"<<endl;
    cout<<"\n | MEDICINE ID |"<<setw(20)<<std:: right<<"MEDICINE NAME |"<<setw(20)<<std:: right<<"MEDICINE TYPE |"
    <<setw(20)<<std:: right<<"COMPANY NAME |"<<setw(25)<<std:: right<<"PER-UNIT COST(TK) |"<<setw(20)<<std:: right<<"STOCK AMOUNT |"<<endl;
    cout<<" _______________________________________________________________________________________________________________________\n"<<endl;
    if(!alldata.empty())
    {
        for(auto i=alldata.begin(); i!=alldata.end(); i++)
        {
            i->second->putdata();
            cout<<endl;
        }
    }
    cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

}
void PRODUCT :: add_product()
{
    cout<<"\t\t------------------------------------------"<<endl;
    cout<<"\t\t\tNEW MEDICINES INFORMATION"<<endl;
    cout<<"\t\t------------------------------------------\n"<<endl;
    while(1)
    {
        PRODUCT *p= new PRODUCT;
        p->getdata();
        alldata[p->getID()]=p;
        cout<<"\n\tWant to add more? (y/n) : ";
        if(getche()=='n')
            break;
        cout<<endl;
    }
    system("cls");
    cout<<"--------------------------------------------"<<endl;
    cout<<"\nItems successfully added in the stock!"<<endl;
}
void PRODUCT :: delete_product()
{
    int dID;
    system("cls");
    cout<<"\t\t------------------------------------------"<<endl;
    cout<<"\t\t\tDELETING ITEMS FROM STOCK"<<endl;
    cout<<"\t\t------------------------------------------\n"<<endl;
    cout<<"Enter the ID of element you want to delete : ";
    cin>>dID;
    if(alldata[dID]==0)
       {
           cout<<"Not in stock!"<<endl;
           alldata.erase(dID);
            return;
       }
    cout<<"\n _______________________________________________________________________________________________________________________"<<endl;
    cout<<"\n | MEDICINE ID |"<<setw(20)<<std:: right<<"MEDICINE NAME |"<<setw(20)<<std:: right<<"MEDICINE TYPE |"
    <<setw(20)<<std:: right<<"COMPANY NAME |"<<setw(25)<<std:: right<<"PER-UNIT COST(TK) |"<<setw(20)<<std:: right<<"STOCK AMOUNT |"<<endl;
    cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

   alldata[dID]->putdata();cout<<endl;
   cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

   cout<<"Are you sure you want to delete? Press 1 for confirmation........."<<endl;
   if(getche()=='1')
   {
        delete(alldata[dID]);
        alldata.erase(dID);
        system("cls");
        cout<<"--------------------------------------------"<<endl;
        cout<<"\nItem deleted successfully!"<<endl;
   }
}
void PRODUCT :: update_product()
{
    system("cls");
    cout<<"\t\t------------------------------------------"<<endl;
    cout<<"\t\t\tMEDICINES INFORMATION UPDATE"<<endl;
    cout<<"\t\t------------------------------------------\n"<<endl;
    cout<<"\nEnter the product ID : ";
    int dID;
    cin>>dID;
    if(alldata[dID]==0)
       {
           cout<<"Not in stock!"<<endl;
           alldata.erase(dID);
            return;
       }
    cout<<"\n _______________________________________________________________________________________________________________________"<<endl;
cout<<"\n | MEDICINE ID |"<<setw(20)<<std:: right<<"MEDICINE NAME |"<<setw(20)<<std:: right<<"MEDICINE TYPE |"
    <<setw(20)<<std:: right<<"COMPANY NAME |"<<setw(25)<<std:: right<<"PER-UNIT COST(TK) |"<<setw(20)<<std:: right<<"STOCK AMOUNT |"<<endl;
    cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

   alldata[dID]->putdata();cout<<endl;
   cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

    cout<<"Enter the updated info : "<<endl;
    PRODUCT *p=new PRODUCT();
    p->getdata();
    delete(alldata[dID]);
    alldata.erase(dID);
    alldata[p->getID()]=p;
    cout<<"\nItem successfully updated in stock!"<<endl;

}
void PRODUCT :: search_product()
{
    system("cls");
    cout<<"\t\t------------------------------------------"<<endl;
    cout<<"\t\t\tSEARCHING MEDICINE BY NAME"<<endl;
    cout<<"\t\t------------------------------------------\n"<<endl;
    cout<<"Enter the product name : ";
    char name[20];cin>>name;
    for(auto i=alldata.begin();i!=alldata.end();i++)
    {
        if(i->second->checkname(name)==0)
            {
                cout<<"\n _______________________________________________________________________________________________________________________"<<endl;
cout<<"\n | MEDICINE ID |"<<setw(20)<<std:: right<<"MEDICINE NAME |"<<setw(20)<<std:: right<<"MEDICINE TYPE |"
    <<setw(20)<<std:: right<<"COMPANY NAME |"<<setw(25)<<std:: right<<"PER-UNIT COST(TK) |"<<setw(20)<<std:: right<<"STOCK AMOUNT |"<<endl;
    cout<<" _______________________________________________________________________________________________________________________\n"<<endl;

                i->second->putdata();cout<<endl;return;
            }
    }
    cout<<"Not found"<<endl;
}
#endif // PRODUCT_H_INCLUDED

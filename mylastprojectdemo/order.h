#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include"product.h"

#endif // ORDER_H_INCLUDED
//ORDER::ORDER()
//{
//    //ctor
//}
//void ORDER :: getdata()
//{
//    cout<<"Product ID : ";
//    cin>>id;
//    cout<<"Product amount : ";
//    cin>>amount;
//}
//void ORDER :: order_item(vector<pair<PRODUCT*,int>>&order_list)
//{
//    while(1)
//    {
//        st:
//        getdata();int fnd=-1;
//        for(int i=0; i<alldata.size(); i++)
//        {
//            if(alldata[i]->getID()==id)
//            {
//                fnd=i;
//                break;
//            }
//        }
//        if(fnd!=-1)
//        {
//            if(alldata[fnd]->getamount()<amount)
//            {
//                cout<<"Not enough product in stock! please try another!"<<endl;
//                goto st;
//            }
//            order_list.push_back(make_pair(alldata[fnd],amount));
//        }
//        cout<<"Want to continue? (y/n) "<<endl;
//        char c;
//        cin>>c;
//        if(c=='n')
//            break;
//    }
//}
//
//void ORDER :: display_bill(vector<pair<PRODUCT*,int>>&order_list)
//{
//    int total_bill=0;
//    PRODUCT p;
//    system("cls");
//    cout<<setw(3)<<"ID"<<setw(15)<<"name"<<setw(15)<<"type"<<setw(20)<<"company"<<setw(10)<<"cost"<<setw(20)<<"available"<<setw(20)<<"ordered amount"<<endl;
//    for(int i=0; i<order_list.size(); i++)
//    {
//        PRODUCT*p=order_list[i].first;
//        p->putdata();
//        p->changeamount(order_list[i].second);
//        cout<<setw(10)<<order_list[i].second<<endl;
//        total_bill+=(order_list[i].first->getcost()*order_list[i].second);
//    }
//    cout<<endl<<"total bill : "<<total_bill<<" tk only!"<<endl;
//}


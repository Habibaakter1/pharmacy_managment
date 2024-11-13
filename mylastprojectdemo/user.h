#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class USER
{
public:
    virtual void display_menu()=0;
    virtual void user_func()=0;
    virtual void getdata() {};
    virtual int login() {return 0;};
};
#endif // USER_H_INCLUDED

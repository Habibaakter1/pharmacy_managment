#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED
#include "admin.h"
#include "customer.h"
#endif

int main()
{
    USER *u;

    load_data();
    first_screen();
    char c=getche();
    if(c=='1')
    {
        u=new ADMIN();

    }
    else
    {
        u=new CUSTOMER();
    }
    u->user_func();
    getdataToFlie();
    return 0;
}

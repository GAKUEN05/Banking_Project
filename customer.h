#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include "account.h"

using namespace std;

class customer{
    public:
        int customer_id;
        string first_name;
        string last_name;
        vector<account> client_account;

        customer(int ID,string given_name,string surname);

        void print_account_info();
        void print_transaction_info();
        void add_account(account *compte);
        void transfer_money(account* compte1,account* compte2,double *mymoney);
};
#endif
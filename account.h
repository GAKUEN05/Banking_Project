#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <ctime>
#include <time.h>
// #include <vector>
#include "transaction.h"
#include <vector>

using namespace std;

class account{
    public:
        int account_id;
        double balance;
        double interest_rate;
        vector<transaction*> client_transaction;
        account(int ID,double income,double rate);
        void add_transaction(transaction *deal,int x);
        void withdrawal_transaction(double *amount);
        void deposit_transaction(double* amount);
        bool withdrawal_transaction2(double *amount);
        bool deposit_transaction2(double* amount);
        void setBalance(double income);
        void setInterest_rate(double rate);
        double getBalance();
        double getInterest_rate();
        int getaccountId();
};
#endif
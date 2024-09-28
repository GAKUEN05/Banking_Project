#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
// #include "account.h"

using namespace std;

enum type{
    withdrawals,
    deposits,
    transfers
};

class transaction{
    public:
        int transaction_id;
        string date;
        int owner_id;
        double amount;
        enum type transaction_type;

        transaction(int ID,string date_of_transaction,type which_type,int owner_id);
        ~transaction();
        
        
        // void transfer_transaction(account *account1,account *account2,double *amount);

        void setDateOfTransaction(string date_of_transaction);
        void setTransactionType(type your_transaction);
        void setAmount(double mymoney);

        string getDateOfTransaction();
        string getTransactionType();
        int getTransactionId();
        int getOwnerId();
        double getAmount();
};
#endif
#include "transaction.h"

using namespace std;

transaction :: transaction(int ID,string date_of_transaction,type which_type,int owner)
    {
        this->transaction_id=ID;
        this->date=date_of_transaction;
        this->owner_id=owner;
        this->transaction_type=which_type;
    }

void transaction :: setDateOfTransaction(string date_of_transaction)
            {
                this->date=date_of_transaction;
            }
void  transaction :: setTransactionType(type your_transaction)
            {
                this->transaction_type=your_transaction;
            }
void transaction :: setAmount(double mymoney)
    {
        this->amount=mymoney;
    }
string transaction :: getDateOfTransaction()
            {
                return this->date;
            }
string transaction :: getTransactionType()
            {
                return (this->transaction_type ==deposits ? "deposit" : "withdrawal");
            }
int transaction :: getTransactionId()
            {
                return this->transaction_id;
            }
int transaction :: getOwnerId()
    {
        return this->owner_id;
    }
double transaction :: getAmount()
    {
        return this->amount;
    }
transaction::~transaction(){
    
}
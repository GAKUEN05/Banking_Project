#include "account.h"

account :: account(int ID,double income,double rate)
    {
        this->account_id=ID;
        this->balance=income;
        this->interest_rate=rate;
    }
void account :: add_transaction(transaction *deal,int x)
    {
        this->client_transaction.push_back(deal);
        deal->owner_id=x;
    }
void account :: withdrawal_transaction(double* amount)
        {
            if(this->balance>=*amount)
                {
                    double sum=this->balance-*amount;
                    this->setBalance(sum);
                    // Get a different random number each time the program runs
                    srand(time(0));
                    time_t ct=time(0);
                    // Generate a random number between 0 and 100
                    int randomNum = rand() % 100001;
                    // Get the current time and format it
                    time_t now = time(0);
                    tm* ltm = localtime(&now);
                    char current_time[20];
                    strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", ltm);
                    transaction* deal = new transaction(randomNum, string(current_time), withdrawals, this->account_id);
                    deal->amount=*amount;
                    this->add_transaction(deal, this->account_id);
                }
            else
                {
                    cout << "Impossible to do the withdrawal, you haven't enough money in your account, currently your balance is of : "<<this->balance << " €"<<endl;
                }
        }
void account :: deposit_transaction(double* amount)
        {
            if(this->balance+*amount<=25000000) //the limit has been choosen arbitrarily
                {
                    double sum=this->balance+*amount;
                    this->setBalance(sum);
                    // Get a different random number each time the program runs
                    srand(time(0));
                    time_t ct=time(0);
                    // Generate a random number between 0 and 100
                    int randomNum = rand() % 100001;
                    // Get the current time and format it
                    time_t now = time(0);
                    tm* ltm = localtime(&now);
                    char current_time[20];
                    strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", ltm);
                    transaction* deal = new transaction(randomNum, string(current_time), deposits, this->account_id);
                    deal->amount=*amount;
                    this->add_transaction(deal, this->account_id);
                }
            else
                {
                    cout << "Impossible to do the deposit, you've exceeded the limit (25000000 €) in your account "<<endl;
                }
        }

bool account :: withdrawal_transaction2(double* amount)
        {
            if(this->balance>=*amount)
                {
                    double sum=this->balance-*amount;
                    this->setBalance(sum);
                    // Get a different random number each time the program runs
                    srand(time(0));
                    time_t ct=time(0);
                    // Generate a random number between 0 and 100
                    int randomNum = rand() % 100001;
                    // Get the current time and format it
                    time_t now = time(0);
                    tm* ltm = localtime(&now);
                    char current_time[20];
                    strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", ltm);
                    transaction* deal = new transaction(randomNum, string(current_time), withdrawals, this->account_id);
                    deal->amount=*amount;
                    this->add_transaction(deal, this->account_id);
                    return true;
                }
                    cout << "Impossible to do the withdrawal,"<< this->getaccountId() << "has not enough money in your account, currently the balance is of : "<<this->balance << " €"<<endl;
                    return false;
        }

bool account :: deposit_transaction2(double* amount)
        {
            if(this->balance+*amount<=25000000) //the limit has been choosen arbitrarily
                {
                    double sum=this->balance+*amount;
                    this->setBalance(sum);
                    // Get a different random number each time the program runs
                    srand(time(0));
                    time_t ct=time(0);
                    // Generate a random number between 0 and 100
                    int randomNum = rand() % 100001;
                    // Get the current time and format it
                    time_t now = time(0);
                    tm* ltm = localtime(&now);
                    char current_time[20];
                    strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", ltm);
                    transaction* deal = new transaction(randomNum, string(current_time), deposits, this->account_id);
                    deal->amount=*amount;
                    this->add_transaction(deal, this->account_id);
                    return true;
                }
            
                    cout << "Impossible to do the deposit, "<< this->getaccountId() << "exceeded the limit (25000000 €) in your account "<<endl;
                    return false;
        }

void account :: setBalance(double income)
            {
                this->balance=income;
            }
void account :: setInterest_rate(double rate)
        {
            this->interest_rate=rate;
        }
double account :: getBalance()
        {
            return this->balance;
        }
double account :: getInterest_rate()
    {
        return this->interest_rate;
    }
int account :: getaccountId()
    {
        return this->account_id;
    }
// int main(){
//     return 0;
// }
#include "customer.h"

customer :: customer(int ID,string given_name,string surname)
    {
        this->customer_id=ID;
        this->first_name=given_name;
        this->last_name=surname;
    }
void customer :: print_account_info()
    {
        cout << "--------------------------" << endl;
        cout << "HERE ARE THE INFORMATION ABOUT THE ACCOUNT OF " <<this->first_name<<" " << this->last_name<< endl;
        cout <<"CUSTOMER ID : "<<this->customer_id << endl;
        for (const auto& acc : client_account){
            cout <<"ACCOUNT ID : "<< acc.account_id << endl;
            cout <<"BALANCE ID : "<< acc.balance << endl;
            cout <<"INTEREST RATE : "<< acc.interest_rate << endl;
            cout << "--------------------------" << endl;
        }
    }
void customer :: print_transaction_info()
    {
         cout << "--------------------------" << endl;
         cout << "HERE ARE THE TRANSACTIONS INFORMATION ABOUT THE ACCOUNT OF " <<this->first_name<<" " << this->last_name<< endl;
         cout <<"CUSTOMER ID : "<<this->customer_id << endl;
         for (const auto& acc : client_account){
             cout <<"ACCOUNT ID : "<< acc.account_id << endl;
             for(const auto& trans : acc.client_transaction)
             {
                cout <<"TRANSACTION ID : "<< trans->transaction_id << endl;
                cout <<"DATE : "<< trans->date << endl;
                cout <<"AMOUNT : "<< trans->amount<<endl;
                cout <<"TYPE OF TRANSACTION : "<< (trans->transaction_type ? "deposit" : "withdrawal") << endl;
             }
            cout << "--------------------------" << endl;
         }
    }
void customer :: add_account(account *compte)
    {
        this->client_account.push_back(*compte);
    }
void customer :: transfer_money(account* compte1,account* compte2,double *mymoney)
    {
        //STEP 1:which one send , which one receive
        int choice;
        cout << "Which account is the expeditor : " << compte1->account_id << " (if so enter 1) " << compte2->account_id << " (if so enter 2) "<< endl;
        cin >> choice;
        //STEP 2:Do the transfer
        if(compte1->withdrawal_transaction2(mymoney))
            {
                cout <<"Alright, the money has been sent correctly : )"<<endl;
                if(compte2->deposit_transaction2(mymoney))
                    {
                        cout <<"Alright, the money has been received correctly : )"<<endl;
                    }
            }
    }
// int main()
//     {
//         return 0;
//     }
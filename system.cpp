#include "transaction.h"
#include "customer.h"
#include "account.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cmath>
vector<customer> client;
void write_into_file()
    {
        string file_name;
        cout << "Please could you enter the name of the file in which you want to write : ";
        cin >> file_name;
        ofstream outFile(file_name);
        int choice1;
        int choice2=1;
        cout << "||FILLING OF THE CLIENTS INFORMATION|| " << endl;
        cout << "Do you want to add a client ? "<<" Yes (then press 1), No (then press 2) " << endl;
        cin >> choice1;
        switch(choice1)
            {
                case 1:
                    if (outFile.is_open())
                        {
                            do{
                                string first_name;
                                string last_name;
                                srand(time(0));
                                int id=rand() % 100001;
                                cout <<"Enter the first_name : ";
                                cin >> first_name;
                                cout <<"Enter the last_name : ";
                                cin >> last_name;
                                customer* dear_client=new customer(id,first_name,last_name);
                                int client_number=rand() % 100001;
                                double montant_client;
                                double rate_of_client=double(rand()) / RAND_MAX * 0.9;
                                rate_of_client=round(rate_of_client*1000)/1000;
                                cout <<"How much do you want to put in this account ? ";
                                cin >> montant_client;
                                account* dear_account= new account(client_number,montant_client,rate_of_client);
                                dear_client->add_account(dear_account);
                                client.push_back(*dear_client);
                                outFile <<"Client ID : "<<id << ", " <<"Name : " <<first_name<< " " << last_name <<", account_id : "<<client_number<<", balance : "<< montant_client <<" €"<<", interest rate: "<< rate_of_client<<"\n";
                                cout << "Do you want to add another client ? "<<" Yes (then press 1), No (then press 2) " << endl;
                                cin >> choice2;
                            }while(choice2==1);
                            cout << "Ok, Have a nice day :)" << endl;
                            outFile.close();
                            break;
                        }
                    else
                        {
                            cerr << "Unable to open file for writing\n";
                            break;
                        }
                case 2:
                cout << "Ok, Have a nice day :)" << endl;
                break;
                default:
                    throw :: invalid_argument("You haven't follow the instruction  !!!");
                    }
        
    };
void read_into_file()
    {
        string file_name;
        cout << "Please could you enter the name of the file you're looking for :";
        cin >> file_name;
        ifstream inFile(file_name);
        string line;
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                cout << line << endl;
            }
        inFile.close();
    } else {
            cerr << "Unable to open file for reading\n";
    }
    }
int main(){
    write_into_file();
    read_into_file();
    // //** Print information about account **//
    // customer yami(458875,"Yugi","Muto");
    // // client.push_back(yami);
    // customer joey(878975,"Joey","Wheeler");
    // // client.push_back(joey);
    // customer kaiba(782577,"Seto","Kaiba");
    // // client.push_back(kaiba);
    // account compte1(458978,10.00,0.2);
    // account* compte2=new account(457178,500.00,0.2);
    // account* compte3=new account(457898,600.00,0.2);
    // yami.add_account(&compte1);
    // joey.add_account(compte2);
    // kaiba.add_account(compte3);
    // double money3=250.00;
    // cout << "Joey Balance before transaction : " <<joey.client_account[0].getBalance() <<endl;
    // kaiba.transfer_money(&kaiba.client_account[0],&joey.client_account[0],&money3);
    // kaiba.print_transaction_info();
    // joey.print_transaction_info();
    // cout << "Joey Balance after transaction : " <<joey.client_account[0].getBalance() <<endl;
    // yami.client_account[0].setBalance(12000.00);
    // yami.print_account_info();
    // cout << "Balance : " << yami.client_account[0].getBalance()<<endl;

    //** Testing information about transaction **/
    // transaction paiement(258,"03-25-2024",withdrawals,1258);
    // yami.client_account[0].add_transaction(&paiement,yami.client_account[0].getaccountId());
    // yami.print_transaction_info(); //Print all transaction (I mean all information related to transactions) in an account 
    // cout << "Transaction ID : "<< yami.client_account[0].client_transaction[0]->getTransactionId() <<endl;
    // cout << "Date of the transaction : "<< yami.client_account[0].client_transaction[0]->getDateOfTransaction() <<endl;
    // cout << "Type of transaction : "  << yami.client_account[0].client_transaction[0]->getTransactionType() <<endl;
    // cout << "Account ID : " << paiement.Account->account_id<<endl;

    //** Testing if the transaction the operations *//
    // double money1=200.03;
    // double money2=30000000000;
    // cout << "Balance before withdrawal : " <<yami.client_account[0].getBalance()<< endl;
    // yami.client_account[0].withdrawal_transaction(&money1);
    // cout << "Balance after withdrawal : " <<yami.client_account[0].getBalance()<< endl;
    // cout << "Balance before deposit : " <<yami.client_account[0].getBalance()<< endl;
    // yami.client_account[0].deposit_transaction(&money2);
    // cout << "Balance after deposit : " <<yami.client_account[0].getBalance()<< endl;
    return 0;
}
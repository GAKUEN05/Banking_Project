# Banking System project
# Overview
This project is a C++ implementation of a banking system designed with an object-oriented approach. It includes classes for customers, accounts, transactions, and banking services. The system allows for creating and managing customers, accounts, and transactions, as well as performing banking services such as withdrawals, deposits, and transfers. Customers can also view their account information, including account balances, recent transactions, and other details.

# Features
* **Customer Management**: Create and manage customer information.<br>

* **Account Management:** Create and manage accounts, including viewing account balances and interest rates.<br>

* **Transaction Management**: Record and manage transactions, including deposits and withdrawals.<br>

* **Banking Services**: Perform banking operations such as withdrawals, deposits, and transfers between accounts.<br>

# Technologies Used
* **C++ Programming Language**<br>

* **MySQL (for database management)**<br>
# Classes and Methods

**Customer Class**<br>

* **Constructor**: Initializes a customer with an ID, first name, and last name.
* **print_account_info**: Prints account information for the customer.
* **print_transaction_info**: Prints transaction information for the customer’s accounts.
* **add_account**: Adds an account to the customer’s list of accounts.
* **transfer_money**: Transfers money between two accounts.

**Account Class**<br>

* **Constructor**: Initializes an account with an ID, balance, and interest rate.
* **add_transaction**: Adds a transaction to the account.
* **withdrawal_transaction**: Performs a withdrawal transaction.
* **deposit_transaction**: Performs a deposit transaction.
* **withdrawal_transaction2**: Performs a withdrawal transaction and returns a boolean status
* **deposit_transaction2**: Performs a deposit transaction and returns a boolean status.
* **setBalance**: Sets the account balance.
* **setInterest_rate**: Sets the interest rate for the account.
* **getBalance**: Returns the account balance.
* **getInterest_rate**: Returns the interest rate for the account.
* **getaccountId**: Returns the account ID.

**Transaction Class**<br>

* **Constructor**: Initializes a transaction with an ID, date, type, and owner ID.
* **setDateOfTransaction**: Sets the date of the transaction.
* **setTransactionType**: Sets the type of the transaction.
* **setAmount**: Sets the amount for the transaction.
* **getDateOfTransaction**: Returns the date of the transaction.
* **getTransactionType**: Returns the type of the transaction.
* **getTransactionId**: Returns the transaction ID.
* **getOwnerId**: Returns the owner ID of the transaction.
* **getAmount**: Returns the amount of the transaction.
* **Destructor**: Cleans up the transaction object.

# How to Run

1.**Clone the repository**:
`git clone https://github.com/GAKUEN05/Banking_Project.git`<br>

2.**Compile the project**:
`g++ -o system *.cpp`<br>

3.**Run the executable**:
`./system`

-- Connect to localhost
-- psql -U postgres -h localhost -p 5433

-- Drop tables if they exist
DROP TABLE IF EXISTS transactions;
DROP TABLE IF EXISTS accounts;
DROP TABLE IF EXISTS customers;
DROP TYPE IF EXISTS transaction_type;


SELECT* FROM accounts_account_id_seq;
ALTER SEQUENCE accounts_account_id_seq RESTART WITH 1;
-- Create the customers table
CREATE TABLE customers (
    customer_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL
);


SELECT* FROM customers_customer_id_seq;
ALTER SEQUENCE customers_customer_id_seq RESTART WITH 1;
-- Create the accounts table
CREATE TABLE accounts (
    account_id SERIAL PRIMARY KEY,
    customer_id INT,
    balance DOUBLE PRECISION NOT NULL DEFAULT 0.0,
    interest_rate DOUBLE PRECISION NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);


-- Create the transaction type enum
CREATE TYPE transaction_type AS ENUM ('withdrawals', 'deposits', 'transfers');

SELECT* FROM transactions_transaction_id_seq;
ALTER SEQUENCE transactions_transaction_id_seq RESTART WITH 1;

-- Create the transactions table
CREATE TABLE transactions (
    transaction_id SERIAL PRIMARY KEY,
    account_id INT,
    transaction_type transaction_type NOT NULL,
    amount DOUBLE PRECISION NOT NULL,
    transaction_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    owner_id INT,
    FOREIGN KEY (account_id) REFERENCES accounts(account_id),
    FOREIGN KEY (owner_id) REFERENCES customers(customer_id)
);

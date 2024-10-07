#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to load .env file manually
void load_env(const string &filename);

int main()
{
    // Load the .env file
    load_env(".env");

    // Retrieve the password from the environment variable
    const char *password = getenv("pswd");

    if (password == nullptr)
    {
        cerr << "Environment variable 'pswd' is not set!" << endl;
        return 1;
    }

    try
    {
        // Use the environment variable for the password in the connection string
        pqxx::connection C("dbname = bank_user user = postgres password = " + string(password) +
                           " hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open())
        {
            cout << "Opened database successfully: " << C.dbname() << endl;
        }
        else
        {
            cout << "Can't open database" << endl;
            return 1;
        }
        C.disconnect();
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

// Function to load .env file manually
void load_env(const string &filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        size_t delimiter_pos = line.find('=');
        string name = line.substr(0, delimiter_pos);
        string value = line.substr(delimiter_pos + 1);
        setenv(name.c_str(), value.c_str(), 1); // Set the environment variable
    }
}

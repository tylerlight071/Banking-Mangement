#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <limits>  // For numeric limits

using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();     // function to get data from user
    void show_account() const; // function to show data on screen
    void modify();             // function to add new data
    void dep(int);             // function to accept amount and add to balance amount
    void draw(int);            // function to accept amount and subtract from balance amount
    void report() const;       // function to show data in tabular format
    int retacno() const;       // function to return account number
    int retdeposit() const;    // function to return balance amount
    char rettype() const;      // function to return type of account
};

void account::create_account()
{
    cout << "\nEnter The account No. :";
    while (!(cin >> acno) || acno < 0) {
        cout << "Invalid input. Please enter a positive integer for the account number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    cout << "\n\nEnter The Name of The account Holder : ";
    cin.getline(name, 50);
    cout << "\nEnter Type of The account (C/S) : ";
    cin >> type;
    type = toupper(type);
    while (type != 'C' && type != 'S') {
        cout << "Invalid input. Please enter 'C' for Current or 'S' for Saving: ";
        cin >> type;
        type = toupper(type);
    }
    cout << "\nEnter The Initial amount (>=500 for Saving and >=1000 for Current) : ";
    while (!(cin >> deposit) || ((type == 'S' && deposit < 500) || (type == 'C' && deposit < 1000))) {
        cout << "Invalid input. Please enter a valid initial amount (>=500 for Saving and >=1000 for Current): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\n\n\nAccount Created..";
}

void account::show_account() const
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}

void account::modify()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account (C/S) : ";
    cin >> type;
    type = toupper(type);
    while (type != 'C' && type != 'S') {
        cout << "Invalid input. Please enter 'C' for Current or 'S' for Saving: ";
        cin >> type;
        type = toupper(type);
    }
    cout << "\nModify Balance amount : ";
    while (!(cin >> deposit) || deposit < 0) {
        cout << "Invalid input. Please enter a positive amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void account::dep(int x)
{
    if (x < 0) {
        cout << "Invalid deposit amount. Cannot be negative." << endl;
        return;
    }
    deposit += x;
}

void account::draw(int x)
{
    if (x < 0) {
        cout << "Invalid withdraw amount. Cannot be negative." << endl;
        return;
    }
    if (deposit - x < 0) {
        cout << "Insufficient balance." << endl;
        return;
    }
    deposit -= x;
}

void account::report() const
{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}

void write_account();            // function to write record in binary file
void display_sp(int);            // function to display account details given by user
void modify_account(int);        // function to modify record of file
void delete_account(int);        // function to delete record of file
void display_all();              // function to display all account details
void deposit_withdraw(int, int); // function to deposit/withdraw amount for given account
void intro();                    // introductory screen function

// Main function

int main()
{
    char ch;
    int num;
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. NEW ACCOUNT";
        cout << "\n\n\t02. DEPOSIT AMOUNT";
        cout << "\n\n\t03. WITHDRAW AMOUNT";
        cout << "\n\n\t04. BALANCE ENQUIRY";
        cout << "\n\n\t05. ALL ACCOUNT HOLDER LIST";
        cout << "\n\n\t06. CLOSE AN ACCOUNT";
        cout << "\n\n\t07. MODIFY AN ACCOUNT";
        cout << "\n\n\t08. EXIT";
        cout << "\n\n\tSelect Your Option (1-8) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            cout << "\n\nAccount created successfully!";
            break;
        case '2':
            cout << "\n\n\tEnter The account No. : ";
            while (!(cin >> num) || num < 0) {
                cout << "Invalid input. Please enter a positive integer for the account number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            deposit_withdraw(num, 1);
            cout << "\n\nAmount deposited successfully! ";
            break;
        case '3':
            cout << "\n\n\tEnter The account No. : ";
            while (!(cin >> num) || num < 0) {
                cout << "Invalid input. Please enter a positive integer for the account number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            deposit_withdraw(num, 2);
            cout << "\n\nAmount withdrawn successfully!";
            break;
        case '4':
            cout << "\n\n\tEnter The account No. : ";
            while (!(cin >> num) || num < 0) {
                cout << "Invalid input. Please enter a positive integer for the account number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n\n\tEnter The account No. : ";
            while (!(cin >> num) || num < 0) {
                cout << "Invalid input. Please enter a positive integer for the account number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            delete_account(num);
            cout << "\n\nAccount closed successfully!";
            break;
        case '7':
            cout << "\n\n\tEnter The account No. : ";
            while (!(cin >> num) || num < 0) {
                cout << "Invalid input. Please enter a positive integer for the account number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            modify_account(num);
            cout << "\n\nAccount modified successfully!";
            break;
        case '8':
            cout << "\n\n\tThanks for using bank management system";
            break;
        default:
            cout << "\n\n\tInvalid option. Please select a number between 1 and 8.";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}

// Function to write in file
void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    if (!outFile) {
        cout << "Error: File could not be opened for writing." << endl;
        return;
    }
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    if (!outFile) {
        cout << "Error: Failed to write account to file." << endl;
    }
    outFile.close();
}

// Function to read specific record from file
void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    cout << "\nBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (!flag)
        cout << "\n\nAccount number does not exist";
}

// Function to modify record of file
void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    while (!File.eof() && !found)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (File.eof()) break; // Break if end of file is reached
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = static_cast<int>(File.tellg()) - sizeof(account);
            File.seekp(pos, ios::beg);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (!found)
        cout << "\n\nRecord Not Found ";
}

// Function to delete record of file
void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    if (!outFile) {
        cout << "Error: Temporary file could not be opened for writing." << endl;
        return;
    }
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
        else {
            found = true;
        }
    }
    inFile.close();
    outFile.close();
    if (found) {
        remove("account.dat");
        rename("Temp.dat", "account.dat");
        cout << "\n\n\tRecord Deleted ..";
    } else {
        cout << "\n\n\tAccount number does not exist.";
        remove("Temp.dat");
    }
}

// Function to display all accounts deposit list
void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.    NAME            Type   Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

// Function to deposit and withdraw amounts
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    while (!File.eof() && !found)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (File.eof()) break; // Break if end of file is reached
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSIT AMOUNT ";
                cout << "\n\nEnter The amount to be deposited: ";
                while (!(cin >> amt) || amt < 0) {
                    cout << "Invalid input. Please enter a positive amount: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdrawn: ";
                while (!(cin >> amt) || amt < 0) {
                    cout << "Invalid input. Please enter a positive amount: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                int bal = ac.retdeposit() - amt;
                if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
                    cout << "Insufficient balance";
                else
                    ac.draw(amt);
            }
            int pos = static_cast<int>(File.tellg()) - sizeof(account);
            File.seekp(pos, ios::beg);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            cout << "\n\n\tRecord Updated";
            found = true;
        }
    }
    File.close();
    if (!found)
        cout << "\n\nRecord Not Found ";
}

// Introductory function
void intro()
{
    system("cls");
    cout << "\t\t\t\t Welcome To Lightwood Bank\n";
    cout << "\t\t\t\t\n\n Press Enter to continue\n";
    cin.get();
}

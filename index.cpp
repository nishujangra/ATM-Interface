#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#define endl "\n"

using namespace std;

class Transaction{
public:
    string type;
    double amount;

    Transaction(const string& type, double amount){
        this->type = type;
        this->amount = amount;
    }
};

class Account{
private:
    string username;
    string pin;
    double balance;
    vector<Transaction> history;

public:
    Account(const string& username, const string& pin){
        this->username = username;
        this->pin = pin;
        this->balance = 0.0;
    }

    bool authentication(const string& pin){
        return this->pin == pin;
    }

    void viewBalance(){
        cout << "Current Balance: $ " << balance << endl;
    }

    void depositMoney(double amount){
        if(amount > 0){
            balance += amount;
            history.push_back(Transaction("Deposit", amount));
            cout << "$" << amount << "has successfully deposited." << endl;
        }
        else{
            cout << "Invalid amount. Please enter a valid amount." << endl;
        }
    }

    void withdrawMoney(double amount){
        if(balance >= amount && amount > 0){
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "$" << amount << "has successfully withdrawn." << endl;
        }
        else if(amount > balance){
            cout << "Insufficient Balance. Please enter a lower amount" << endl;
        }
        else{
            cout << "Invalid amount. Please enter a valid amount." << endl;
        }
    }

    void viewTransactionHistory(){
        cout << "\n\nTransaction History: " << endl;
        for(const auto& transaction : history){
            cout << transaction.type << " : $" << transaction.amount << endl;
        }
    }
};

class ATM{
private:
    unordered_map<string, Account> accounts;
    Account* currentAccount;

public:
    ATM(){
        currentAccount = NULL;
    }

    void displayMenu(){
        cout << "\nATM Main Menu:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Create new account" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
    }

    void displayAccountMenu(){
        cout << "\nAccount Menu:" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Transaction Histroy" << endl;
        cout << "5. Logout" << endl;
        cout << "Choose an option: ";
    }

    void createAccount(){
        string username;
        string pin;
        cout << "Enter Username: ";
        cin >> username;

        if(accounts.find(username) == accounts.end()){
            cout << "Enter Pin: ";
            cin >> pin;

            accounts.emplace(username, Account(username, pin));
            cout << "Account Created Successfully." << endl;
        }
        else{
            cout << "Username already existed. Please use a different username." << endl;
        }
    }

    void login(){
        string username;
        string pin;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Pin: ";
        cin >> pin;

        auto it = accounts.find(username);
        if(it != accounts.end() && it->second.authentication(pin)){
            currentAccount = &it->second;
            cout << "Logged In Successfully" << endl;
            accountMenu();
        }
        else{
            cout << "Invalid username or password." << endl;
        }
    }

    void accountMenu(){
        int choice;
        while(true){
            displayAccountMenu();
            cin >> choice;

            switch(choice){
                case 1:
                    currentAccount->viewBalance();
                    break;

                case 2:
                    {
                        double amount;
                        cout << "Enter the amount to deposit: $ ";
                        cin >> amount;
                        currentAccount->depositMoney(amount);
                        break;
                    }

                case 3:
                    {
                        double amount;
                        cout << "Enter the amount to withdraw: $ ";
                        cin >> amount;
                        currentAccount->withdrawMoney(amount);
                        break;
                    }

                case 4:
                    currentAccount->viewTransactionHistory();
                    break;

                case 5:
                    cout << "Logged Out Successfully" << endl;
                    currentAccount = NULL;
                    return ;

                default:
                    cout << "Invalid option. Please choose a valid menu option" << endl;
            }
        }
    }
};

int main(){
    ATM atm;
    int choice;

    while(true){
        atm.displayMenu();
        cin >> choice;

        switch (choice){
            case 1:
                atm.login();
                break;

            case 2:
                atm.createAccount();
                break;

            case 3:
                cout << "Thanks for using the ATM. Have a nice day" << endl;
                return 0;

            default:
                cout << "Invalid Option. Please choose a valid menu option: " << endl;
                break;
        }
    }

    return 0;
}
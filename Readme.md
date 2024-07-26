# ATM Interface

This project is a simulation of an ATM interface implemented in C++. It provides functionalities for user authentication, managing multiple accounts, viewing balance, depositing money, withdrawing money, and viewing transaction history.

## Features

- **User Authentication:** Secure login using username and pin.
- **Multiple Accounts:** Supports creating and managing multiple user accounts.
- **Balance Inquiry:** View current account balance.
- **Deposit Money:** Deposit money into the account.
- **Withdraw Money:** Withdraw money from the account with balance checks.
- **Transaction History:** View a history of deposits and withdrawals.
- **Error Handling:** Includes checks for invalid inputs and actions.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., g++)
- C++ Standard Library

### Running the Program

1. **Clone the Repository:**

    ```sh
    git clone https://github.com/yourusername/atm-interface.git
    cd atm-interface
    ```

2. **Compile the Program:**

    ```sh
    g++ -o atm atm.cpp
    ```

3. **Run the Program:**

    ```sh
    ./atm
    ```

## Usage

When you run the program, you will be presented with the ATM Main Menu:

1. **Login:**
    - Enter your username and pin to log into your account.

2. **Create Account:**
    - Create a new account by providing a unique username and pin.

3. **Exit:**
    - Exit the ATM interface.

### Account Menu

After logging in, you will have the following options:

1. **View Balance:**
    - Displays the current balance of your account.

2. **Deposit Money:**
    - Allows you to deposit a specified amount into your account.

3. **Withdraw Money:**
    - Allows you to withdraw a specified amount from your account, ensuring you have sufficient balance.

4. **View Transaction History:**
    - Displays a list of all transactions (deposits and withdrawals) made on your account.

5. **Logout:**
    - Logs you out and returns to the main menu.

## Example

```
ATM Main Menu:
1. Login
2. Create Account
3. Exit
Choose an option: 2
Enter username: user1
Enter pin: pass1
Account created successfully.

ATM Main Menu:
1. Login
2. Create Account
3. Exit
Choose an option: 1
Enter username: user1
Enter pin: pass1
LLogged In Successfully

Account Menu:
1. View Balance
2. Deposit Money
3. Withdraw Money
4. View Transaction History
5. Logout
Choose an option: 2
Enter amount to deposit: $100
$100 has successfully deposited.

Account Menu:
1. View Balance
2. Deposit Money
3. Withdraw Money
4. View Transaction History
5. Logout
Choose an option: 1
Current Balance: $100
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.

## Acknowledgments

- Inspired by basic banking operations and ATM functionalities.
- Built with C++ to demonstrate object-oriented programming and simple user authentication.
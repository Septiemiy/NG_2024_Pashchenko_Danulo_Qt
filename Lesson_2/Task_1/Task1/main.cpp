#include <iostream>

using namespace std;

const int BANK_ACCOUNT_SIZE = 10;

void menu()
{
    cout << endl << "'+' --- put money in a bank account." << endl
         << "'-' --- take money from a bank account." << endl
         << "'s' --- output all money from all bank accounts." << endl
         << "'a' --- bank account with max money." << endl
         << "'i' --- bank account with min money." << endl
         << "'q' --- quit." << endl << endl;
}

void putMoney(int* bank_accounts)
{
    int bank_account_number = 0;
    int money = 0;
    cout << endl << "Input bank account number on which you want to put money: ";
    cin >> bank_account_number;
    cout << endl << "Input the amount of money: ";
    cin >> money;

    bank_accounts[bank_account_number - 1] += money;
}

void takeMoney(int* bank_accounts)
{
    int bank_account_number = 0;
    int money = 0;
    cout << endl << "Input bank account number from which you want to take money: ";
    cin >> bank_account_number;
    cout << endl << "Input the amount of money: ";
    cin >> money;

    if(bank_accounts[bank_account_number - 1] < money)
    {
        cout << endl << "   Error: There is not enough money in the bank account." << endl;
        takeMoney(bank_accounts);
    }
    else
    {
        bank_accounts[bank_account_number - 1] -= money;
    }
}

void allMoney(int* bank_accounts)
{
    int allMoney = 0;
    for(int index = 0; index < BANK_ACCOUNT_SIZE; index++)
    {
        allMoney += bank_accounts[index];
    }
    cout << endl << "   Result: " << allMoney << endl;
}

void maxMoney(int* bank_accounts)
{
    int maxMoney = 0;
    int bankAccountNumber = 0;
    for(int index = 0; index < BANK_ACCOUNT_SIZE; index++)
    {
        if(maxMoney < bank_accounts[index])
        {
            maxMoney = bank_accounts[index];
            bankAccountNumber = index + 1;
        }
    }
    cout << endl << "   Result: " << bankAccountNumber << " --- " << maxMoney << endl;
}

int maxMoneyNotVoid(int* bank_accounts)
{
    int maxMoney = 0;
    for(int index = 0; index < BANK_ACCOUNT_SIZE; index++)
    {
        if(maxMoney < bank_accounts[index])
        {
            maxMoney = bank_accounts[index];
        }
    }
    return maxMoney;
}

void minMoney(int* bank_accounts)
{
    int minMoney = maxMoneyNotVoid(bank_accounts);
    int bankAccountNumber = 0;
    for(int index = 0; index < BANK_ACCOUNT_SIZE; index++)
    {
        if(minMoney > bank_accounts[index])
        {
            minMoney = bank_accounts[index];
            bankAccountNumber = index + 1;
        }
    }
    cout << endl << "   Result: " << bankAccountNumber << " --- " << minMoney << endl;
}

int main()
{
    int bank_accounts[BANK_ACCOUNT_SIZE] = {};

    while(1)
    {
        cout << endl << "Bank accounts:" << endl;
        for(int index = 0; index < BANK_ACCOUNT_SIZE; index++)
        {
            cout << index + 1 << " --- " << bank_accounts[index] << endl;
        }

        menu();

        char action = '+';
        cout << "Select the needed action: ";
        cin >> action;

        switch(action)
        {
            case '+':
                putMoney(bank_accounts);
                break;
            case '-':
                takeMoney(bank_accounts);
                break;
            case 's':
                allMoney(bank_accounts);
                break;
            case 'a':
                maxMoney(bank_accounts);
                break;
            case 'i':
                minMoney(bank_accounts);
                break;
            case 'q':
                exit(0);
                break;
            default:
                cout << endl << "   Error: Invalid action." << endl;
                break;
        }
    }
    return 0;
}

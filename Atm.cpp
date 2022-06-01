#include <iostream>
using namespace std;
class Atm
{
private:
    int account_no;
    int mobile_no;
    int pin;
    double balance;
    string name;

public:
    void setdata(string name, double balance, int pin, int mobile_no, int account_no)
    {
        this->account_no = account_no;
        this->balance = balance;
        this->mobile_no = mobile_no;
        this->name = name;
        this->pin = pin;
    }
    int get_accno()
    {
        return account_no;
    }
    int get_mobile_no()
    {
        return mobile_no;
    }
    int get_pin()
    {
        return pin;
    }
    string get_name()
    {
        return name;
    }
    int get_balance()
    {
        return balance;
    }

    void withdrawl()
    {
        if (balance <= 0)
        {
            cout << "Your Balance is 0" << endl;
        }
        int amt;
        cout << "Enter amount to Withdrawl" << endl;
        cin >> amt;
        if (balance >= amt)
        {
            balance -= amt;
            cout << "Collect your Cash!" << endl;
            cout << "Available Balance : " << balance << endl;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }
    void user_details()
    {
        int pswd;
        cout << "Please re-enter your pin" << endl;
        cin >> pswd;
        if (pswd == pin)
        {
            cout << "Name : " << name << endl;
            cout << "Account Number : " << account_no << endl;
            cout << "Mobile Number : " << mobile_no << endl;
            cout << "Balance : " << balance << endl;
        }
        else
        {
            cout << "wrong Pin" << endl;
        }
    }
    // Updating mobile number
    void change_mobile(int old_mobile, int new_mobile)
    {
        if (old_mobile == mobile_no)
        {
            mobile_no = new_mobile;
        }
        else
        {
            cout << "Incorrect Old Mobile Number" << endl;
        }
    }
    // Change pswd
    void change_pin(int old_pin, int new_pin)
    {
        if (old_pin == pin)
        {
            pin = new_pin;
        }
        else
        {
            cout << "Incorrect Pin" << endl;
        }
    }
};
int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;

    Atm user1;
    user1.setdata("Saksham", 3500, 1234, 930568, 1234567);
    do
    {
        cout << "==================== WELCOME TO ATM ====================" << endl;
        cout << "Enter your Account Number" << endl;
        cin >> enterAccountNo;
        cout << "Enter your PIN" << endl;
        cin >> enterPIN;
        if ((enterPIN == user1.get_pin()) && (enterAccountNo == user1.get_accno()))
        {
            do
            {
                int choice;
                int old_mobile, new_mobile;
                int old_pin, new_pin;
                cout << "===========Welcome to ATM =============" << endl;
                cout << "1.Check Balance" << endl;
                cout << "2.Cash Widthdrawl" << endl;
                cout << "3.Show User Details" << endl;
                cout << "4.Update Mobile No." << endl;
                cout << "5.Change PIN" << endl;
                cout << "6.EXIT" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout << "Your balance is :" << user1.get_balance() << endl;
                    break;
                case 2:
                    user1.withdrawl();
                    break;
                case 3:
                    user1.user_details();
                    break;
                case 4:
                    cout << "Enter your old Mobile Number" << endl;
                    cin >> old_mobile;
                    cout << "Enter your new Mobile Number" << endl;
                    cin >> new_mobile;
                    user1.change_mobile(old_mobile, new_mobile);
                    break;
                case 5:
                    cout << "Enter your old PIN" << endl;
                    cin >> old_pin;
                    cout << "Enter your new PIN" << endl;
                    cin >> new_pin;
                    user1.change_pin(old_pin, new_pin);
                    break;
                case 6:
                    exit(0);
                    break;
                default:
                    cout << "INVALID OPERATIONS" << endl;
                    break;
                }
            } while (1);
        }
        else
        {
            cout << "INVALID CREDENTIALS" << endl;
        }

    } while (1);

    return 0;
}
#include<iostream>
#include<climits>

using namespace std;

class BankAccount{
    int accNum , accBalance;
public:
    BankAccount(int accNum){
        this->accNum = accNum;
        this->accBalance = 0;
    }
    void deposit(int n){
        // int n;
        // cout << "Please enter the amount you wish to deposit : ";
        // cin >> n;
        accBalance += n;
        cout << "Your transaction has been completed successfully. Your updated balance is : " << accBalance << endl;
    }
    void withDraw(int n){
        // int n;
        // cout << "Please enter the amount you wish to withdraw : ";
        // cin >> n;
        if(n > accBalance){
            cout << "Transaction failed: Withdrawal amount exceeds available balance." << endl;
        }else{
            accBalance -= n;
            cout << "Your transaction has been completed successfully. Your updated balance is : " << accBalance << endl; 
        }
    }
    void getBalance(){
        cout << "Your current account balance is = " << accBalance << endl;
    }
};

int main(){
    BankAccount b1(123);
    b1.getBalance();
    b1.deposit(10000);
    b1.withDraw(2000);
    b1.getBalance();
    return 0;
}
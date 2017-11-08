/// Returning and passing object in a function

#include <iostream>
class Account{
    public: int balance;
    public: Account(){
        balance = 0;
    }
    public: static Account getAcc(Account a, Account b){
        Account ac;
        ac.balance = a.balance+b.balance;
        return ac;
  }
};

int main(){
    using namespace std;
    Account a1;
    a1.balance = 50;
    Account a2;
    a2.balance = 60;
    Account b = Account::getAcc(a1,a2);
    cout << b.balance << endl;
}

#include <iostream>
class BankAccount{
    private :
        std::string accountNumber;
        double balance;
        std::string ownerName;
    
    public :
        BankAccount(std::string accountNumber, std::string ownerName) : accountNumber{accountNumber}, balance{0}, ownerName{ownerName}  {};
        void Deposit(double amount);
        void Withdraw(double amount);
        void GetBalance() const;
        void DisplayInfo() const;
};

void BankAccount::Deposit(double amount){
    balance += amount;
    std::cout<<amount<<"원을 입금하였습니다.\n";
    return;
}

void BankAccount::Withdraw(double amount){
    if(balance<amount){
        std::cout<<"잔액이 부족합니다.\n";
        return;
    }
    balance -= amount;
    std::cout<<amount<<"원을 출금하였습니다.\n";
}

void BankAccount::GetBalance(){
    std::cout<<"현재 통장 잔고는 "<<balance<<"원 입니다.\n";
    return;
}
    
void BankAccount::DisplayInfo(){
    std::cout<<"계좌 번호 : "<<accountNumber<<"\n";
    std::cout<<"소유자 이름 : "<<ownerName<<"\n";
}

int main(){
    BankAccount account1("123-456-789","장재웅");
    BankAccount account2("987-654-321","홍길동");
    account1.Deposit(3000);
    account1.Withdraw(1200);
    account1.GetBalance();
    account1.DisplayInfo();
    account2.Withdraw(500);
    account2.DisplayInfo();
}  
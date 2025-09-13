#include <iostream>

void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main(){

    int choice=0;
    double balance=0;



    do{
        std::cout << "\n\n===== MENU =====\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch(choice){
            case 1: showbalance(balance);
            break;

            case 2:balance += deposit();
            break;

            case 3:balance -=withdraw(balance);
            break;

            case 4: std::cout<<"Thanks for visiting!!";
            break;

            default:
            std::cout<<"Invalid option.";

        }

    }while(choice !=4);

    return 0;
}

void showbalance(double balance){
    std::cout<<"Your Balance is: "<<balance;

}

double deposit(){
    double amount;
    std::cout<<"Enter amount: ";
    std::cin>>amount;
    return amount;

}

double withdraw(double balance){
    double amount;
    std::cout<<"Enter amount: ";
    std::cin>>amount;
    if(amount>balance){
        std::cout<<"Insufficient Balance";
        return 0;
    }
    return amount;
}




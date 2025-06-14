#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
//sets precision for floating numbers
#include <iomanip>

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){


    double balance = 0;
    int choice;

    do{
        std::cout << "*******************\n";
        std::cout << "Enter Your Choice: \n";
        std::cout << "*******************\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        //clears the input buffer and preventing a break in the program
        //reset any error flags when std::cin fails to interpret input
        std::cin.clear();
        //this will clear the input buffer
        fflush(stdin);

        switch(choice){
            case 1: showBalance(balance);
                break;
            case 2: balance = balance + deposit();
                    showBalance(balance);
                break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                break;
            case 4: std::cout << "Thanks for Visiting!!!\n";
                break;
            default: std::cout << "Invalid Choice\n";
        }
    }while(choice != 4);

    system("pause");
    
    return 0;
}
void showBalance(double balance){

    //std::precision() << std::fixed will set the amount of decimals
    std::cout << "Your balance is : $" << std::setprecision(2) << std::fixed << balance << '\n';
}
double deposit(){

    double amount;

    std::cout << "Enter Amount to Deposit: \n";
    std::cin >> amount;

    if(amount > 0){

    return amount;}
    else{
        std::cout << "That is Not a Valid Amount\n";
        return 0;
    }
}
double withdraw(double balance){

    double amount;

    std::cout << "Enter Amount to Wishdraw: \n";
    std::cin >> amount;

    if(amount > balance){
        std::cout << "Insufficient Funds \n";
        return 0;}
    else if (amount < 0){
        std::cout << "That is Not a Valid Amount\n";
        return 0;
    }
    else{
    return amount;
    }
}
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
//sets precision for floating numbers
#include <iomanip>

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){


    double balance = 0;
    int choice;

    do{
        cout << "*******************\n";
        cout << "Enter Your Choice: \n";
        cout << "*******************\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cin >> choice;

        //clears the input buffer and preventing a break in the program
        //reset any error flags when std::cin fails to interpret input
        cin.clear();
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
            case 4: cout << "Thanks for Visiting!!!\n";
                break;
            default: cout << "Invalid Choice\n";
        }
    }while(choice != 4);

    system("pause");
    
    return 0;
}
void showBalance(double balance){

    //std::precision() << std::fixed will set the amount of decimals
    cout << "Your balance is : $" << setprecision(2) << fixed << balance << '\n';
}
double deposit(){

    double amount;

    cout << "Enter Amount to Deposit: \n";
    cin >> amount;

    if(amount > 0){

    return amount;}
    else{
        std::cout << "That is Not a Valid Amount\n";
        return 0;
    }
}
double withdraw(double balance){

    double amount;

    cout << "Enter Amount to Wishdraw: \n";
    cin >> amount;

    if(amount > balance){
        cout << "Insufficient Funds \n";
        return 0;}
    else if (amount < 0){
        cout << "That is Not a Valid Amount\n";
        return 0;
    }
    else{
    return amount;
    }
}
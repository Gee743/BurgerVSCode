//Geethika Rathnajith
//G21235963



#include <iostream>
using namespace std;

//Prototypes of functions
void addCredits(double &credit);
void orderBurger(double &credit, double &total);
void chooseToppings(double &credit, double &total);

int main() {
    double credit = 100; //current credit balance
    double total = 0; //Total credits of the burger purchased

    cout << "----------------------------" << endl;
    cout << "UClan Burger" << endl;
    cout << "----------------------------" << endl;

    while (true) { //loop of the main menu
        int menu;
        cout << "MAIN MENU" << endl;
        cout << "   1. Add credits" << endl;
        cout << "   2. Order Burger" << " (Current credits: " << credit << ")" << endl;
        cout << "   0. Exit" << endl;
        cout << "Please enter a number: ";
        cin >> menu;
        cout << endl;
        cout << "----------------------------" << endl;

        if (menu == 1) {
            addCredits(credit); //call the function used to add more credits
        } else if (menu == 2) {
            orderBurger(credit, total); //call the function to start ordering the burger
        } else if (menu == 0) {
            cout << "Exiting the program. Thank you!" << endl;
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}

//function used to add more credits to the exsisting amount
void addCredits(double &credit) {
    double creditadd;
    cout << "Your current balance is: " << credit << endl;
    cout << "Enter the amount you want to add: ";
    cin >> creditadd;
    cout << endl;

    credit += creditadd;

    cout << "Your new credit amount is: " << credit << endl;
}

//function used to order the burger
void orderBurger(double &credit, double &total) {
    int size;

    cout << "ORDER BURGER - Select size   " << "[Current Balance = " << credit << " credits]" << endl;
    cout << endl;
    cout << "Please choose from the following options" << endl;
    cout << endl;
    cout << "   1. Small  [3.0 credits]" << endl;
    cout << "   2. Medium [5.50 credits]" << endl;
    cout << "   3. Large  [7.25 credits]" << endl;
    cout << "   0. Return to main menu" << endl;
    cout << "-------------------------" << endl;
    cout << "Please enter a number: ";
    cin >> size;
    cout << endl;

    if (size == 1) {
        cout << "You have selected a small burger" << endl;
        credit -= 3.0;
        cout << "Current credits: " << credit << endl;
        total += 3.0;
    } else if (size == 2) {
        cout << "You have selected a medium burger" << endl;
        credit -= 5.50;
        cout << "Current credits: " << credit << endl;
        total += 5.50;
    } else if (size == 3) {
        cout << "You have selected a large burger" << endl;
        credit -= 7.25;
        cout << "Current credits: " << credit << endl;
        total += 7.25;
    } else if (size == 0) {
        cout << "Returning to main menu" << endl;
        return; //returning to the main menu
    } else {
        cout << "Invalid input. Returning to main menu." << endl;
        return; //returning to the main menu due to invalid input
    }

    chooseToppings(credit, total);

    if (total <= credit) {
        cout << "Your order is complete. Your total is " << total << " credits" << endl;
        cout << "You have " << credit << " credits remaining" << endl;
    } else {
        cout << "Insufficient credits available. Your order has been canceled." << endl;
        //reset credits to its initial value
        credit = 5;
    }
}

//function used to choose toppings
void chooseToppings(double &credit, double &total) {
    double cheese = 0.80;
    double salad = 0.50;
    double bacon = 1.00;
    double ketchup = 0.30;
    double mayo = 0.30;
    double extraburger = 1.50;

    cout << endl;
    cout << "Please choose from the following toppings: " << endl;
    cout << endl;
    cout << "   1. Cheese       [0.80 credits]" << endl;
    cout << "   2. Salad        [0.50 credits]" << endl;
    cout << "   3. Bacon        [1.00 credits]" << endl;
    cout << "   4. Ketchup      [0.30 credits]" << endl;
    cout << "   5. Mayo         [0.30 credits]" << endl;
    cout << "   6. Extra Burger [1.50 credits]" << endl;
    cout << "   0. Return to main menu" << endl;
    cout << "---------------------------------" << endl;

    while (true) {
        int topping;
        cout << "Please enter a number: ";
        cin >> topping;
        cout << endl;

        if (topping == 0) {
            break;
        } else if (topping >= 1 && topping <= 6) {
            switch (topping) {
                case 1:
                    credit -= cheese;
                    total += cheese;
                    cout << "You have added cheese to your burger" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    cout << "Credits remaining : " << credit << endl;
                    break;
                case 2:
                    credit -= salad;
                    total += salad;
                    cout << "You have added salad to your burger" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    break;
                case 3:
                    credit -= bacon;
                    total += bacon;
                    cout << "You have added bacon to your burger" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    break;
                case 4:
                    credit -= ketchup;
                    total += ketchup;
                    cout << "You have added ketchup to your burger" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    break;
                case 5:
                    credit -= mayo;
                    total += mayo;
                    cout << "You have added mayo to your burger" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    break;
                case 6:
                    credit -= extraburger;
                    total += extraburger;
                    cout << "You have added an extra burger to your order" << endl;
                    cout << "Your current price is : " << total << " credits" << endl;
                    cout << endl;
                    break;
            }

            char addtopping;
            cout << "Press y to add another topping or press n to confirm order: ";
            cin >> addtopping;

            if (addtopping == 'n' || addtopping == 'N') {
                break;
            }
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
}




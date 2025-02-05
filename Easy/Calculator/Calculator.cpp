// This is a simple calculator program that takes two numbers and an operator and performs the operation on the two numbers.
// The program uses a switch statement to determine which operation to perform.
// The program also includes error handling for invalid input.

//steps for development
// 1. set up basic input and output

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    // 2. implement the airthmetic operations
    double num1, num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    // 3. add input validation
    if (cin.fail()) {
        cout << "Invalid input. Please enter a number." << endl;
        return 1;
    }
    // 4. implement a loop to keep the calculator running until the user chooses to exit
    while (true) {
        // 5. implement the switch statement to perform the operation based on the operator
        switch (op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero." << endl;
                }
                break;
            case '%':
                if (num2 != 0) {
                    cout << num1 << " % " << num2 << " = " << (int)num1 % (int)num2 << endl;
                } else {
                    cout << "Error: Division by zero." << endl;
                }
                break;
            case '^':
                cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << endl;
                break;
            default:
                cout << "Invalid operator. Please enter a valid operator." << endl;
        }
        // 6. add option to exit the program
        char choice;
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        if (choice == 'n') {
            break;
        } else if (choice == 'y') {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter operator (+, -, *, /): ";
            cin >> op;
            cout << "Enter second number: ";
            cin >> num2;
        } else {
            cout << "Invalid choice. Exiting program." << endl;
            break;
        }
    }
    return 0;
}

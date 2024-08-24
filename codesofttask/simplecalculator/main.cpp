#include <iostream>
#include <limits>

// Function to display the menu
void displayMenu() {
    std::cout << "\n===== Calculator Menu =====\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "===========================\n";
}

// Function to get a valid number from the user
double getNumber() {
    double num;
    while (true) {
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a valid number: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard extra input
            return num;
        }
    }
}

// Function to get a valid operation from the user
char getOperation() {
    char op;
    while (true) {
        std::cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '5') {
            return op;
        } else {
            std::cout << "Invalid operation. Please enter a valid operation (+, -, *, /, 5 to exit): ";
        }
    }
}

// Function to perform the chosen operation
double performOperation(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
                return std::numeric_limits<double>::quiet_NaN();
            }
        default:
            std::cout << "Error: Invalid operation.\n";
            return std::numeric_limits<double>::quiet_NaN();
    }
}

// Main function
int main() {
    double num1, num2, result;
    char operation;
    bool running = true;

    while (running) {
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        operation = getOperation();

        if (operation == '5') {
            running = false;
            std::cout << "Exiting the calculator. Goodbye!\n";
            continue;
        }

        std::cout << "Enter the first number: ";
        num1 = getNumber();
        std::cout << "Enter the second number: ";
        num2 = getNumber();

        result = performOperation(num1, num2, operation);

        if (!std::isnan(result)) {
            std::cout << "The result is: " << result << "\n";
        }
    }

    return 0;
}


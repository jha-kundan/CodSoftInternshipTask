#include<iostream>
using namespace std;

int calcy(char choice, int num1, int num2){
    int total;
    switch (choice)
    {
    case '+':
        total = num1 + num2;
        return total; 
        break;
    case '-':
        total = num1 - num2;
        return total; 
        break;
    case '*':
        total = num1 * num2;
        return total; 
        break;
    case '/':
        total = num1 / num2;
        return total; 
        break;
    case '%':
        total = num1 % num2;
        return total; 
        break;
    
    default:
        cout<<"Enter Valid choice: "<<endl;
        break;
    };

    return 0;
}
int main(){
    char choice;
    int n1, n2;
    while(1){

        cout << "\n===== Calculator Menu =====\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. x\n";
        cout << "===========================\n";
        
        cout << "Enter your choice : ";
        cin>>choice;



        if(choice == 'x'){
            break;
        }
        cout << "Enter the first number: ";
        cin>>n1;
        cout << "Enter the second number: ";
        cin>>n2;
        int total = calcy(choice, n1, n2);

        cout<<"total : "<<total<<endl;

    }


    
    return 0;
}
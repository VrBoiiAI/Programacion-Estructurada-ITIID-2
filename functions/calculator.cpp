#include <stdio.h>
using namespace std;

int sum(int a, int b) {return a + b;}
int substract(int a, int b) {return a - b;}
int multiply(int a, int b) {return a * b;}
int divide(int a, int b) {return static_cast<float>(a)/b;}
int percentage(int a, int b) {return (static_cast<float>(a)/100)*b;}

int main(){
    // Variable initialization
    int num1,num2,operation;

    // Get data
    printf("Enter the first value: ");
    scanf("%d", &num1);

    printf("Enter the second value: ");
    scanf("%d", &num2);
    
    printf("\n[1] Addition\n[2] Substraction\n[3] Multiplication\n[4] Division\n[5] Percentage\n\nWhich operation do you want to do?: ");
    scanf("%d", &operation);

    // Enter the correct operation using switch
    switch (operation){
    case 1:
        printf("%d + %d = %d", num1, num2, sum(num1, num2));
        break;

    case 2:
        printf("%d - %d = %d", num1, num2, substract(num1, num2));
        break;

    case 3:
        printf("%d x %d = %d", num1, num2, multiply(num1, num2));
        break;

    case 4:
        // We first verify that the denominator is not zero
        if (num2 != 0){
            printf("%d / %d = %.2f", num1, num2, divide(num1,num2));
            break;
        } else{
            printf("Cannot divide by 0."); 
            break;
        }

    case 5:
        printf("%d%% of %d = %.2f", num1, num2, percentage(num1, num2));
        break;
    
    default:
        printf("Enter a valid option.");
    }

    return 0;
}
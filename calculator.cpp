#include <stdio.h>
using namespace std;

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
        printf("%d + %d = %d", num1, num2, num1+num2);
        break;

    case 2:
        printf("%d - %d = %d", num1, num2, num1-num2);
        break;

    case 3:
        printf("%d x %d = %d", num1, num2, num1*num2);
        break;

    case 4:
        // We first verify that the denominator is not zero
        if (num2 != 0){
            float division = static_cast<float>(num1)/num2; // We convert one value of the division to float to return num1 float value
            printf("%d / %d = %.2f", num1, num2, division);
            break;
        } else{
            printf("Cannot divide by 0."); 
            break;
        }

    case 5:
        printf("%d%% of %d = %.2f", num1, num2, (static_cast<float>(num1)/100)*num2);
        break;
    
    default:
        printf("Enter num1 valid option.");
    }
    return 0;
}
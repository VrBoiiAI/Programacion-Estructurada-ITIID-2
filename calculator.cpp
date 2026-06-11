#include <stdio.h>
using namespace std;

int main(){
    // Variable initialization
    int a,b,op;

    // Get data
    printf("Enter the first value: ");
    scanf("%d", &a);

    printf("Enter the second value: ");
    scanf("%d", &b);
    
    printf("\n[1] Addition\n[2] Substraction\n[3] Multiplication\n[4] Division\n[5] Percentage\n\nWhich operation do you want to do?: ");
    scanf("%d", &op);

    // Enter the correct operation using switch
    switch (op){
    case 1:
        printf("%d + %d = %d", a, b, a+b);
        break;

    case 2:
        printf("%d - %d = %d", a, b, a-b);
        break;

    case 3:
        printf("%d x %d = %d", a, b, a*b);
        break;

    case 4:
        // We first verify that the denominator is not zero
        if (b != 0){
            float division = static_cast<float>(a)/b; // We convert one value of the division to float to return a float value
            printf("%d / %d = %.2f", a, b, division);
            break;
        } else{
            printf("Cannot divide by 0."); 
            break;
        }

    case 5:
        printf("%d%% of %d = %.2f", a, b, (static_cast<float>(a)/100)*b);
        break;
    
    default:
        printf("Enter a valid option.");
    }
    return 0;
}
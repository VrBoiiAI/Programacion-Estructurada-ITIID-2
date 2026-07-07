#include <stdio.h>

int factorial(int n){
    if (n==0 || n==1){  
        return 1;
    } else{
        return factorial(n-1) * n;
    }
}

int main(){
    // Variable initialization
    int n;

    // Get data
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    // If n is positive we calculate its factorial
    if (n >= 0){
        printf("%d! = %d", n, factorial(n));

    } else{
        printf("Factorial operation does not work with negative numbers.");
    }

    return 0;
}
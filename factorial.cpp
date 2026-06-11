#include <stdio.h>

int main(){
    // Variable initialization
    int n;

    // Get data
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);


    if (n >= 0){
        int factorial = 1;

        // Calculate factorial with for
        for (int i=1; i<=n; i++){
            factorial = factorial * i;
        }
        printf("%d! = %d (for)\n", n, factorial);

        // Calculate factorial with while
        int i = 1;
        factorial = 1;
        while (i <= n){
            factorial = factorial * i;
            i++;
        }
        printf("%d! = %d (while)", n, factorial);
    } else printf("Factorial operation does not work with negative numbers.");
    return 0;
}
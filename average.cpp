#include <stdio.h>

using namespace std;

int main(){
    // Variable initialization
    int a,b;
    float avg = 0;

    // Get values
    printf("Enter the start of the interval: ");
    scanf("%d", &a);

    printf("Enter the end of the interval: ");
    scanf("%d", &b);

    if (b-a > 0){ // When the start is smaller than the end the program runs normally
        for (int i=a; i<=b; i++){avg += i;}
        avg = (avg/(b-a+1));
    }
    else if (b-a < 0){ // When the end is smaller than the start we swap the values
        for (int i=b; i<=a; i++){avg += i;}
        avg = (avg/(a-b+1));
    } else{ // If start and end are the same we just print the value
        avg = a;
    }

    printf("The average of the numbers in [%d-%d] is: %.2f", a, b, avg);
    return 0;
}
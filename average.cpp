#include <stdio.h>

using namespace std;

int main(){
    // Variable initialization
    int interval_start,interval_end;
    float average = 0;

    // Get values
    printf("Enter the start of the interval: ");
    scanf("%d", &interval_start);

    printf("Enter the end of the interval: ");
    scanf("%d", &interval_end);
    if (interval_end-interval_start > 0){ // When the start is smaller than the end the program runs normally
        for (int i=interval_start; i<=interval_end; i++){average += i;}
        average = (average/(interval_end-interval_start+1)); // We add one in the divisor because the substraction 'removes' one of the limits
    }
    else if (interval_end-interval_start < 0){ // When the end is smaller than the start we swap the values
        for (int i=interval_end; i<=interval_start; i++){average += i;}
        average = (average/(interval_start-interval_end+1)); // We add one in the divisor because the substraction 'removes' one of the limits
    } else{ // If start and end are the same we just print the value
        average = interval_start;
    }

    printf("The average of the numbers in [%d-%d] is: %.2f", interval_start, interval_end, average);
    return 0;
}
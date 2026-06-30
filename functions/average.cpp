#include <stdio.h>

using namespace std;

float interval_average(int interval_start, int interval_end, float avg){

    if (interval_end==interval_start){  
        return avg;
    } else{
        avg -= 0.5;
        return interval_average(interval_start, interval_end-1, avg);
    }
}

int main(){
    // Variable initialization
    int interval_start,interval_end;
    float average = 0;

    // Get values
    printf("Enter the start of the interval: ");
    scanf("%d", &interval_start);

    printf("Enter the end of the interval: ");
    scanf("%d", &interval_end);
    
    average = interval_average(interval_start, interval_end, interval_end); 

    printf("The average of the numbers in [%d-%d] is: %.2f", interval_start, interval_end, average);

    return 0;
}
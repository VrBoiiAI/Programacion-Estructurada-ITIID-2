#include <stdio.h>
#include <math.h>
using namespace std;

float x;

float triangular(int upward_start, int peak, int downward_end){
    // We verify that the function has coherent values
    if (upward_start < peak && peak < downward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it is
            if (x <= upward_start) return 0;
            else if (x <= peak) return ((static_cast<float>(x)-upward_start)/(downward_end-peak));
            else if (x <= downward_end) return ((static_cast<float>(downward_end)-x)/(downward_end-peak));
            else return 0;

        } else return -1;
}

float gamma(int upward_start, int upward_end){

        // We verify that the function has coherent values
        if (upward_start < upward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it is
            if (x <= upward_start) return 0;
            else if (x < upward_end) return ((static_cast<float>(x)-upward_start)/(upward_end-upward_start));
            else return 1;

        } else return -1;

}

float trapezoidal(int upward_start, int upward_end, int downward_start, int downward_end){

    // We verify that the function has coherent values
    if (upward_start < upward_end && upward_end < downward_start && downward_start < downward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it is
            if (x <= upward_start) return 0;
            else if (x <= upward_end) return ((static_cast<float>(x)-upward_start)/(upward_end-upward_start));
            else if (x <= downward_start) return 1;
            else if (x <= downward_end) return ((static_cast<float>(downward_end)-x)/(downward_end-downward_start));
            else return 0;

        } else return -1;
}

float s(int upward_start=0, int upward_end=0){
        // We verify that the function has coherent values
        if (upward_start < upward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it is
            if (x < upward_start) return 0;
            else if (x <= ((static_cast<float>(upward_start)+upward_end)/(2))) return (2*pow((((static_cast<float>(x)-upward_start))/(upward_end-upward_start)),2));
            else if (x <= upward_end) return (1-(2*pow((static_cast<float>(upward_end)-x)/(upward_end-upward_start),2)));
            else return 1;

        } else return -1;    
}

int main(){
    // Variable initialization
    int operation, upward_start, upward_end, peak, downward_start, downward_end;
    float y;
    // We get the function to calculate
    printf("\n[1] Triangular Function\n[2] Gamma Function\n[3] Trapezoidal Function\n[4] S Function\n\nWhich function do you want to represent?: ");
    scanf("%d", &operation);

    switch (operation){
    case 1:
        // Get data
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of m (peak of the triangle): ");
        scanf("%d", &peak);
        printf("Enter the value of b (end of the downward slope): ");
        scanf("%d", &downward_end);

        y = triangular(upward_start, peak, downward_end);

        // We verify that the function has coherent values
        if (x >= 0){
            printf("The value of x in %.2f is: %.2f", x, y);
        } else printf("The values of the limits dont match (should be a<m<b)");
        break;

    case 2:
        // Get data 
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of m (end of the upward slope): ");
        scanf("%d", &upward_end);

        y = gamma(upward_start,upward_end);

        // We verify that the function has coherent values
        if (x >= 0){
            printf("The value of x in %.2f is: %.2f", x, y);
        } else printf("The values of the limits dont match (should be a < m)");
        break;

    case 3:
        // Get data
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of b (end of the upward slope): ");
        scanf("%d", &upward_end);
        printf("Enter the value of c (start of the downward slope): ");
        scanf("%d", &downward_start);
        printf("Enter the value of d (end of the downward slope): ");
        scanf("%d", &downward_end);

        y = trapezoidal(upward_start, upward_end, downward_start, downward_end);
        
        // We verify that the function has coherent values
        if (x >= 0){
            printf("The value of x in %.2f is: %.2f", x, y);
        } else printf("The values of the limits dont match (should be a<b<c<d)");
        break;

    case 4:
        // Get data
        printf("Enter the value of a (start of the slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of c (end of the slope): ");
        scanf("%d", &upward_end);

        y = s(upward_start, upward_end);

        // We verify that the function has coherent values
        if (x >= 0){
            printf("The value of x in %.2f is: %.2f", x, y);
        } else printf("The values of the limits dont match (should be a<c)");
        break;
    
    default:
        printf("Enter a valid option.");
    }
    return 0;
}
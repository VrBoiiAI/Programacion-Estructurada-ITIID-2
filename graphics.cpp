#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    // Variable initialization
    int operation, upward_start, upward_end, peak, downward_start, downward_end ;
    float x;

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

        // We verify that the function has coherent values
        if (upward_start < peak && peak < downward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= upward_start) printf("The value of x in %.2f is: 0", x);
            else if (x <= peak) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-upward_start)/(downward_end-peak)));
            else if (x <= downward_end) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(downward_end)-x)/(downward_end-peak)));
            else printf("The value of x in %.2f is: 0", x);

        } else printf("The values of the limits dont match (should be a<m<b)");
        break;

    case 2:

        // Get data 
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of m (end of the upward slope): ");
        scanf("%d", &upward_end);

        // We verify that the function has coherent values
        if (upward_start < upward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= upward_start) printf("The value of x in %.2f is: 0", x);
            else if (x < upward_end) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-upward_start)/(upward_end-upward_start)));
            else printf("The value of x in %.2f is: 1", x);

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

        // We verify that the function has coherent values
        if (upward_start < upward_end && upward_end < downward_start && downward_start < downward_end){ // We verify that the function has coherent values
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= upward_start) printf("The value of x in %.2f is: 0", x);
            else if (x <= upward_end) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-upward_start)/(upward_end-upward_start)));
            else if (x <= downward_start) printf("The value of x in %.2f is: 1", x);
            else if (x <= downward_end) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(downward_end)-x)/(downward_end-downward_start)));
            else printf("The value of x in %.2f is: 0", x);

        } else printf("The values of the limits dont match (should be a<b<c<d)");
        break;

    case 4:

        // Get data
        printf("Enter the value of a (start of the slope): ");
        scanf("%d", &upward_start);
        printf("Enter the value of c (end of the slope): ");
        scanf("%d", &upward_end);

        // We verify that the function has coherent values
        if (upward_start < upward_end){
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);

            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x < upward_start) printf("The value of x in %.2f is: 0", x);
            else if (x <= ((static_cast<float>(upward_start)+upward_end)/(2))) printf("The value of x in %.2f is: %.2f", x, (2*pow((((static_cast<float>(x)-upward_start))/(upward_end-upward_start)),2)));
            else if (x <= upward_end) printf("The value of x in %.2f is: %.2f", x, (1-(2*pow((static_cast<float>(upward_end)-x)/(upward_end-upward_start),2))));
            else printf("The value of x in %.2f is: 1", x);

        } else printf("The values of the limits dont match (should be a<c)");
        break;
    
    default:
        printf("Enter a valid option.");
    }
    return 0;
}
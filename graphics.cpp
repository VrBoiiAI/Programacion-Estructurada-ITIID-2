#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    // Variable initialization
    int a,b,c,d,m,op;
    float x;

    // We get the function to calculate
    printf("\n[1] Triangular Function\n[2] Gamma Function\n[3] Trapezoidal Function\n[4] S Function\n\nWhich function do you want to represent?: ");
    scanf("%d", &op);

    switch (op){
    case 1:
        // Get data
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &a);
        printf("Enter the value of m (peak of the triangle): ");
        scanf("%d", &m);
        printf("Enter the value of b (end of the downward slope): ");
        scanf("%d", &b);
        if (a < m && m < b){ // We verify that the function has coherent values
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);
            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= a) printf("The value of x in %.2f is: 0", x);
            else if (x <= m) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-a)/(b-m)));
            else if (x <= b) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(b)-x)/(b-m)));
            else printf("The value of x in %.2f is: 0", x);
        } else printf("The values of the limits dont match (should be a<m<b)");
        break;

    case 2:
        // Get data 
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &a);
        printf("Enter the value of m (end of the upward slope): ");
        scanf("%d", &m);
        if (a < m){ // We verify that the function has coherent values
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);
            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= a) printf("The value of x in %.2f is: 0", x);
            else if (x < m) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-a)/(m-a)));
            else printf("The value of x in %.2f is: 1", x);
        } else printf("The values of the limits dont match (should be a < m)");
        break;

    case 3:
        // Get data
        printf("Enter the value of a (start of the upward slope): ");
        scanf("%d", &a);
        printf("Enter the value of b (end of the upward slope): ");
        scanf("%d", &b);
        printf("Enter the value of c (start of the downward slope): ");
        scanf("%d", &c);
        printf("Enter the value of d (end of the downward slope): ");
        scanf("%d", &d);
        if (a < b && b < c && c < d){ // We verify that the function has coherent values
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);
            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x <= a) printf("The value of x in %.2f is: 0", x);
            else if (x <= b) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(x)-a)/(b-a)));
            else if (x <= c) printf("The value of x in %.2f is: 1", x);
            else if (x <= d) printf("The value of x in %.2f is: %.2f", x, ((static_cast<float>(d)-x)/(d-c)));
            else printf("The value of x in %.2f is: 0", x);
        } else printf("The values of the limits dont match (should be a<b<c<d)");
        break;

    case 4:
        // Get data
        printf("Enter the value of a (start of the slope): ");
        scanf("%d", &a);
        printf("Enter the value of c (end of the slope): ");
        scanf("%d", &c);
        if (a < c){ // We verify that the function has coherent values
            printf("Enter the value of x to calculate: ");
            scanf("%f", &x);
            // We get the value of x and evaluate its corresponding y value based on where on the graphic it its
            if (x < a) printf("The value of x in %.2f is: 0", x);
            else if (x <= ((static_cast<float>(a)+c)/(2))) printf("The value of x in %.2f is: %.2f", x, (2*pow((((static_cast<float>(x)-a))/(c-a)),2)));
            else if (x <= c) printf("The value of x in %.2f is: %.2f", x, (1-(2*pow((static_cast<float>(c)-x)/(c-a),2))));
            else printf("The value of x in %.2f is: 1", x);
        } else printf("The values of the limits dont match (should be a<c)");
        break;
    
    default:
        printf("Enter a valid option.");
    }
    return 0;
}
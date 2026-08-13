#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){                                                                                                             
    string Products[15]; // Array containing the names of each product
    float Prices[15]; // Array containing the price of each product

    for (int i = 0; i < 5; i++) { // For loop to get each product's name and price (Just 5 items for faster testing)
        cout << "Enter Product " << (i + 1) << "'s name: ";
        getline(cin >> ws, Products[i]); // We use getline and cin >> ws to remove leading blank characters
                                         //(spaces, newlines, tabs, etc.) and wipe input buffer in each iteration

        cout << "Enter '" << Products[i] << "' price: ";
        cin >> Prices[i];
    }
    
    printf("\n\n");
    for (int i = 0; i < 5; i++) { // For loop to print product name and price (Just 5 items for faster testing)
        printf("%s: $%.2f\n", Products[i].c_str(), Prices[i]); // printf has problems printing the string so we use the .c_str() method to instead pass its pointer
    }
    return 0;
}

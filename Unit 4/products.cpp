#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){                                                                                                             
    string Products[15];
    float Prices[15];

    for (int i = 0; i < 5; i++) {
        cout << "Enter Product " << (i + 1) << "'s name: ";
        getline(cin >> ws, Products[i]); 

        cout << "Enter '" << Products[i] << "' price: ";
        cin >> Prices[i];
    }
    
    printf("\n\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f\n", Products[i].c_str(), Prices[i]);
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void arrayUpdate(int P, int& n, string Arr[], string newElement){
    int i = n;
    while (i >= P-1){
        Arr[i+1] = Arr[i];
        i--;
    }

    Arr[P-1] = newElement;
    n++;
}

int main(){
    int n = 3, pos = 3;
    string Cars[10] = {"Ford", "Chevrolet", "Hyundai"};

    printf("Number of initialized elements in array: %d\nArray elements:\n", n);
    for (int i=0; i<n; i++) printf("%s\n", Cars[i].c_str());

    arrayUpdate(pos, n, Cars, "Lamborghini");

    printf("\n******* After Update *******\n\n");
    printf("Number of initialized elements in array: %d\nArray elements:\n", n);
    for (int i=0; i<n; i++) printf("%s\n", Cars[i].c_str());

    return 0;
}

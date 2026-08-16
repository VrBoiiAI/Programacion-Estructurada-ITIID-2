#include <stdio.h>
#include <iostream>
#include <iterator>

using namespace std;

void printVector(int Arr[], int len){ // Function to print arrays in the form [0, 1, 2, 3, 4]
    cout << "[";
    for (int i=0; i<len-1; i++){
        cout << Arr[i] << ", ";
    }
    cout << Arr[len-1] << "]";
    cout<<endl;
}

void sumVectors(int A[], int B[], int len){ // Prints the algebraic sum of two vectors with the same length 
    int Sum[len]; // We initialize an array to save the resulting vector
    for (int i=0; i<len; i++){ // For loop to iterate the elements of the arrays 
        Sum[i] = A[i] + B[i]; // We sum the elements of the 2 arrays and save it to the same index of the resulting array
    }
    printVector(Sum, len); // We print the result array once the operation is done
}

int dotProduct(int A[], int B[], int len){ // Returns the vector dot product of two vectors with the same length
    int sum = 0;
    for (int i=0; i<len; i++){
        sum += A[i] * B[i]; // Sums the product of the elements in both vectors with the same index
    }
    return sum;
}

int main(){
    int n = 5;
    int A[n] = {1, 2, 3, 4, 5};
    int B[n] = {6, 7, 8, 9, 10};

    cout << "A vector: ";
    printVector(A, n);

    cout << "B vector: ";
    printVector(B, n);

    cout << endl << "Sum:" << endl;
    sumVectors(A, B, n);

    cout << endl << "Dot Product:" << endl;
    cout << dotProduct(A, B, n);

    return 0;
}
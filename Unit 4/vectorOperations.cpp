#include <stdio.h>
#include <iostream>
#include <iterator>

using namespace std;

void printVector(int Arr[], int len){
    cout << "[";
    for (int i=0; i<len-1; i++){
        cout << Arr[i] << ", ";
    }
    cout << Arr[len-1] << "]";
    cout<<endl;
}

void sumVectors(int A[], int B[], int len){
    int Sum[len];
    for (int i=0; i<len; i++){
        Sum[i] = A[i] + B[i];
    }
    printVector(Sum, len);
}

int multiplyVectors(int A[], int B[], int len){
    int sum = 0;
    for (int i=0; i<len; i++){
        sum += A[i] * B[i];
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

    cout << endl << "Multiplication:" << endl;
    cout << multiplyVectors(A, B, n);

    return 0;
}
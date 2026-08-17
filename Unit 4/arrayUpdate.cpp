#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void clearScreen() {
    // \033[2J clears the screen, \033[H moves the cursor to the top-left
    cout << "\033[2J\033[H"; 
}

int getDeclaredElements(string Arr[], int size){ // Returns the number of elements in an array that are not empty strings
    int declaredCount = size;
    for (int i=0; i<size; i++){
        if (Arr[i] == "")
            declaredCount--;
    }
    return declaredCount;
}


// Function to print arrays in the form [0, 1, 2, 3, 4], prints "NULL" if the element is an empty string
// If list=true instead prints elements like:
// [1] A
// [2] B
// [3] etc. does not print empty strings

void printVector(string Arr[], int len, bool list=false){
    if (!(list)){ // Check for list flag
        cout << "[";
        for (int i=0; i<len-1; i++){ // Prints all values except last one
            if (Arr[i] == ""){ // Print NULL if Arr[i] is an empty string, print the value otherwise
                cout << "NULL, ";
            } else{
                cout << Arr[i] << ", ";
            }
        }
        if (Arr[len-1] == ""){ // prints specially the last element to close the bracket, NULL if last element is an empty string
            cout << "NULL]";
            cout<<endl;
        } else{
            cout << Arr[len-1] << "]";
            cout<<endl;
        }
    } else{
        for (int i=0; i<len; i++){ // Prints elements as a list if list=true
            if (!(Arr[i] == "")){
                printf("[%d] %s\n", i+1, Arr[i].c_str());
            }
        }
    }
}

bool isArrayFull(string Arr[], int size){ // Checks and returns true if there are 0 empty strings in the array, otherwise returns false
    int emptyCount = 0;
    for (int i=0; i<size; i++){ // Adds one to the count if the element is an empty string
        if (Arr[i] == "")
            emptyCount++;
    }
    if (emptyCount == 0){ // If emptyCount == 0, there are no empty strings and the array is full
        return true;
    } else{
        return false;
    }
}

// Inserts {newElement} in index {P-1} of {Arr[]}, pushes elements to the back if the position is taken,
// puts {newElement} in the first available blank space if P > number of declared elements of {Arr[]} as to not have empty spaces between elements
// Doesn't do anything if the array is already full
void addEntry(int P, string Arr[], string newElement, int size){ 
    int i = getDeclaredElements(Arr, size);
    if (!(isArrayFull(Arr, size))){ // Add the new element only if the array is not full
        if (P-1>i){ // Check if user is trying to use a blank position which is not the first one
            printf("Cannot skip positions, saving in first blank space...\n");
            Arr[i] = newElement;
        }
        else{
            while (i >= P-1){ // If the new element goes between elements, push elements to the back (We already checked that array is not full)
                Arr[i] = Arr[i-1];
                i--;
            }
            Arr[P-1] = newElement; // After pushing elements after target index, we insert the new element
        }
    } else printf("Array is full. Please instead edit or delete an entry...\n"); // Terminate early if array is full
}

void deleteEntry(int P, string Arr[], int size){ // Deletes element in index {P-1} and moves later elements one position to the left
    for (int i = P-1; i<size-1; i++){
        Arr[i] = Arr[i+1]; // We first move every element after the one we are deleting one position to the left (Except the last one)
    }
    Arr[size-1] = ""; // The last element turns into an empty string
}

void editEntry(int P, string Arr[], string newElement){ // Updates the value of {Arr[P-1]} with {newElement}
    Arr[P-1] = newElement;
}

int main(){
    string Cars[5]; // Main working array
    int operation; // Variable to get the operation to do
    int arraySize = size(Cars);
    
    while(1){ // We loop the options until user exits
        printVector(Cars, arraySize);

        // Get operation
        printf("\n[1] Add entry\n[2] Delete entry\n[3] Edit entry\n[4] Exit\n\nWhich operation do you want to do? ");
        scanf("%d", &operation);

        switch (operation){ // Send user to selected operation. Clears screen and repeats if no valid option is selected. Terminates main function if user exits
            case 1:{ // [1] Add entry
                string newElement; // Element to be inserted in ...
                int position;      // index {position-1}

                printf("Enter a car brand: "); // Get newElement
                getline(cin >> ws, newElement);

                printf("Enter the position to place '%s': ", newElement.c_str()); // Get position
                scanf("%d", &position);
                clearScreen();
                addEntry(position, Cars, newElement, arraySize); // Add {newElement} in index {position-1} of array {Cars}
                break;
            }

            case 2:{ // [2] Delete entry
                int position; // Element in index {position-1} to be deleted

                printVector(Cars, arraySize, true); // Show array {Cars} in list form for the user to choose which element to delete
                printf("Enter the position to delete: "); // Get position
                scanf("%d", &position);

                deleteEntry(position, Cars, arraySize); // Remove element in index {position-1} of array {Cars}
                clearScreen();
                break;
            }
                
            case 3:{ // [3] Edit entry
                string newElement; // Element to be updated to in ...
                int position;      // index {position-1}

                printVector(Cars, arraySize, true); // Show array {Cars} in list form for the user to choose which element to edit
                printf("Enter the position to edit: "); // Get position
                scanf("%d", &position);

                printf("Enter the new element: "); // Get new value
                getline(cin >> ws, newElement);

                editEntry(position, Cars, newElement); // Update element in index {position-1} of array {Cars} to {newElement}
                clearScreen();
                break;
            }
            case 4: // [4] Exit
                return 0; // Terminate program early

            default: // Invalid option
                clearScreen(); // Clear screen, show error message and show menu again
                printf("Enter a valid option.\n");
                break;
            }
    }
}

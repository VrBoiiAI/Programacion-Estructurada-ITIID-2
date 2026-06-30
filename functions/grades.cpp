#include <stdio.h>
#include <iostream>
using namespace std;

float final_grade(float class_work, float portfolio, float exam, int assistance){
    if (class_work >= 50 && portfolio >= 50 && exam >= 50 && assistance >= 80){
        return (class_work*0.3 + portfolio*0.3 + exam*0.4);
    } else if (assistance < 80){
        return -1; // Control value if assistance percentage was not reached
    } else return -2; // Control value if any grading parameter minumum was not reached
}

int main(){
    // Variable initialization
    float class_work, portfolio, exam;
    int assistance;

    // Get data
    printf("Enter your Class Work grade (%%): ");
    scanf("%f", &class_work);

    printf("Enter your Portfolio grade (%%): ");
    scanf("%f", &portfolio);

    printf("Enter your Exam grade (%%): ");
    scanf("%f", &exam);

    printf("Enter your Assistance (%%): ");
    scanf("%d", &assistance);

    // Final grade calculated with given parameters
    float grade = final_grade(class_work, portfolio, exam, assistance); 

    // Check if final_grade returns a control value (not a valid grade) and display the problem
    if (grade == -1){ 
        printf("You did not get the minimum assistance required to get a grade (You have %d%%, 80% required)");
    } else if (grade == -2){
        printf("You did not get the minimum grade (50%) in every grading parameter:\n"); // If both conditions were not met the student does not get a grade.
        if (class_work < 50) printf("Class Work: %.2f%%\n", class_work);
        if (portfolio < 50) printf("Portfolio: %.2f%%\n", portfolio);
        if (exam < 50) printf("Exam: %.2f%%\n", exam);
    } 
    
    // If final_grade returns a valid grade, displays it
    else {
        printf("Final grade: %.2f", grade);
    }

    return 0;
}
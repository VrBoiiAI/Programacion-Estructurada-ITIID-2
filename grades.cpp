#include <stdio.h>
#include <iostream>
using namespace std;

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

    if (class_work >= 50 && portfolio >= 50 && exam >= 50 && assistance >= 80){ // Check for a minimum of 50% in every grading parameter and 80% assistance. 
        float final_grade = class_work*0.3 + portfolio*0.3 + exam*0.4; // Final grade calculated with given parameters
        printf("Final grade: %.2f", final_grade);
    } else{
        printf("You did not meet the minimum requirements to get a grade."); // If both conditions were not met the student does not get a grade.
    }
    return 0;
}
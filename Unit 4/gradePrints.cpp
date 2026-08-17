#include <stdio.h>
#include <string>
using namespace std;

int main(){

    string Last_Names[] = {
        "Alvarez","Arias","Bermudez","Castaneda","Cruz","De La Cruz","Esparza","Lopez Montano",
        "Lopez Rodriguez","Nolasco","Orozco","Pinto","Rodriguez","Rojas","Roja","Villanueva"
    };
    int Class[] = {10, 10, 8, 10, 10, 7, 10, 10, 10, 8, 10, 10, 10, 10, 10, 10}; // Classwork grade of each student in order
    int Document[] = {7, 10, 7, 7, 5, 9, 7, 7, 10, 7, 7, 5, 10, 5, 10, 5, 0, 10}; // Deliverable document grade of each student in order
    float Exam[] = {7.5, 0, 2.5, 4, 0.5, 1.5, 2, 2, 3, 1, 1, 4, 1, 8, 9, 3.5}; // Exam grade of each student in order
    float Ordinary[] = {8.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7.7, 0, 0}; // Grade of each student IF they passed in ordinary period
    float Remedial[] = {0.0, 7.5, 8.5, 8.5, 7.5, 9, 7.5, 5, 7.5, 6, 5, 7.5, 7.5, 0.0, 9, 9}; // Grade of each student IF they passed in remedial period
    float Final[] = {8.1, 7.5, 8.5, 8.5, 7.5, 9, 7.5, 0.0, 7.5, 0.0, 0.0, 7.5, 7.5, 7.7, 9, 9}; // Final grade of each student

    printf("\t\tClass\tDoc\tExam\tOrd\tRem\tFinal\n"); // Print headers
    for (int i = 0; i < 16; i++) { // For loop to iterate all students

        if(Last_Names[i].length() < 8) // We check if the last name is too long, if so, we only print one tab to have all rows flush

            // We print each student's name and grade in each grading parameter, along with their final grade and if they passed in ordinary of remedial period
            printf("%s\t\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", Last_Names[i].c_str(), Class[i], Document[i], Exam[i], Ordinary[i], Remedial[i], Final[i]);

        else 
            printf("%s\t%d\t%d\t%.1f\t%.1f\t%.1f\t%.1f\n", Last_Names[i].c_str(), Class[i], Document[i], Exam[i], Ordinary[i], Remedial[i], Final[i]);
    }
    
    return 0;
}

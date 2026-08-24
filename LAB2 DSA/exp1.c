// student name sap id marks make code uisng diffrent arrays for each field
/*Write a C program that uses arrays to store and display student information.
The program should:
1.	Ask the user to enter the number of students.
2.	Store each student’s name, ID, and marks using arrays.
3.	Display the entered details.*/
#include <stdio.h>
#include <string.h>
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    char names[n][50];
    int marks[n];
    int sap_id[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("SAP ID: ");
        scanf("%d", &sap_id[i]);

        printf("Name: ");
        scanf(" %[^\n]", names[i]);

        printf("Marks: ");
        scanf("%d", &marks[i]);
    }
    printf("\nStudent Record\n");
    for (i = 0; i < n; i++) {
        printf("\nSAP ID  : %d", sap_id[i]);
        printf("\nName  : %s", names[i]);
        printf("\nMarks: %d\n", marks[i]);
    }
    return 0;
}   
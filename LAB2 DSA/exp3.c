//student name sap id marks make code uisng dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    char name[50];
    int marks;
    int roll;
};
int main() {
    int n,i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student *s = (struct student*)malloc(n * sizeof(struct student));
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }
    printf("\nStudent Records\n");
    for (i = 0; i < n; i++) {
        printf("\nRoll  : %d", s[i].roll);
        printf("\nName  : %s", s[i].name);
        printf("\nMarks: %d\n", s[i].marks);
    }
    free(s);
}
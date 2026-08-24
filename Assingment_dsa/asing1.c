//Suppose there are 20 students in a class.  Enter marks of the students (max marks:100) in 2 subjects using 2 different arrays. Print the total marks obtained by each student//

/*#include <stdio.h>

int main() {
    int marks_t[20];
    int marks_l[20];
    int total[20];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < 20; i++) {
        printf("Enter theory marks for student %d: ", i + 1);
        scanf("%d", &marks_t[i]);

        printf("Enter lab marks for student %d: ", i + 1);
        scanf("%d", &marks_l[i]);

        total[i] = marks_t[i] + marks_l[i];
    }

    printf("\nTotal marks of students:\n");
    for(i = 0; i < 20; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }

    return 0;
}*/

#include <stdio.h>
int main() {
    
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int marks[n][2]; 
    int total[n];
    int i;

    for(i = 0; i < n; i++) {
        printf("Enter theory marks for student %d: ", i + 1);
        scanf("%d", &marks[i][0]);

        printf("Enter lab marks for student %d: ", i + 1);
        scanf("%d", &marks[i][1]);

        total[i] = marks[i][0] + marks[i][1];
    }

    printf("\nTotal marks of students:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }

    return 0;
}

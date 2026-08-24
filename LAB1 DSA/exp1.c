/*#include <stdio.h>
int main() {
    int marks_t[20];
    int marks_l[20];
    int total[20];
}
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter theory marks for student %d: ", i + 1);
        scanf("%d", &marks_t[i]);
        printf("Enter lab marks for student %d: ", i + 1);
        scanf("%d", &marks_l[i]);
        total[i] = marks_t[i] + marks_l[i];
    }
    
    printf("\nTotal marks of students:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
        
    }
    
    return 0;
}*/

#include <stdio.h>

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
}

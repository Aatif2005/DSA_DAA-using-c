#include <stdio.h>
struct student {
    char name[50];
    int marks;
    int sap_id;
};
int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("SAP ID: ");
        scanf("%d", &s[i].sap_id);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Marks: ");
        scanf("%d", &s[i].marks);
    }
    printf("\nStudent Record\n");
    for (i = 0; i < n; i++) {
        printf("\nSAP ID  : %d", s[i].sap_id);
        printf("\nName  : %s", s[i].name);
        printf("\nMarks: %d\n", s[i].marks);
    }
    return 0;
}
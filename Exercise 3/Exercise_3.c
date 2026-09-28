#include <stdbool.h>
#include <stdio.h>

int getStudentAmount(void) {
    bool valid;
    int studentAmount;
    do {
        printf("Enter amount of students (>0): ");
        valid = scanf("%d", &studentAmount) && studentAmount > 0;
        while (getchar() != '\n');
    } while (!valid);
    return studentAmount;
}

int handleStudentSelection(int studentAmount) {
    int selection;
    printf("Enter student id (1 - %d) or enter 0 to finish: ", studentAmount);
    const bool valid = scanf("%d", &selection) && selection >= 0 && selection <= studentAmount;
    while (getchar() != '\n');

    if (!valid) {
        printf("Invalid student id.\n");
        return -1;
    }

    return selection;
}

int handleGradeSelection(int studentId) {
    int selection;
    printf("Select grade for student %d (0 - 5), or enter -1 to cancel: ", studentId);
    const bool valid = scanf("%d", &selection) && selection >= -1 && selection <= 5;
    while (getchar() != '\n');

    if (!valid) {
        printf("Invalid grade.\n");
        return -2;
    }

    return selection;
}

int main(void) {
    const int studentAmount = getStudentAmount();
    int students[studentAmount];
    for (int i = 0; i < studentAmount; i++) students[i] = -1;
    int studentId = -1;
    while (studentId != 0) {
        studentId = handleStudentSelection(studentAmount); // Invalid selections return -1
        if (studentId > 0) {
            const int grade = handleGradeSelection(studentId); // Invalid selection & cancel return -1
            if (grade != -1) students[studentId - 1] = grade;
        }
    }

    printf("Student\tGrade\n");
    for (int i = 0; i < studentAmount; ++i) {
        if (students[i] != -1) printf("%d\t\t%d\n", i+1, students[i]);
        else printf("%d\t\t%s\n", i+1, "N/A");
    }
}

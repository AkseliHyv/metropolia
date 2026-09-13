#include <stdbool.h>
#include <stdio.h>

int getStudentAmount(void) {
    bool passed;
    int studentAmount;
    do {
        printf("Enter amount of students (>0): ");
        passed = scanf("%d", &studentAmount) == 1 && studentAmount > 0;
        while (getchar() != '\n');
    } while (!passed);
    return studentAmount;
}

int handleStudentSelection(int studentAmount) {
    int selection = -1; // Not unsigned as there can be any positive amount of students.
                        // 0 is reserved for quitting, so a negative must be used for invalid choice.
    printf("Enter student id (1 - %d) or enter 0 to finish: ", studentAmount);
    scanf("%d", &selection);
    while (getchar() != '\n');

    if (selection < 0 || selection > studentAmount) {
        printf("Invalid student id.\n");
        return -1;
    }

    return selection;
}

int handleGradeSelection(int studentId) {
    int selection = -2; // Could be >5 as well
    printf("Select grade for student %d (0 - 5), or enter -1 to cancel: ", studentId);
    scanf("%d", &selection);
    while (getchar() != '\n');

    if (selection == -1) return -1;
    if (selection < 0 || selection > 5) {
        printf("Invalid grade.\n");
        return -1;
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
        if (studentId > 0) { // studentId can only be valid or -1
            int grade = handleGradeSelection(studentId); // Invalid selection & cancel return -1
            if (grade != -1) students[studentId - 1] = grade; // grade can only be 0-5 or -1
        }
    }

    printf("Student\tGrade\n");
    for (int i = 0; i < studentAmount; ++i) {
        if (students[i] != -1) printf("%d\t\t%d\n", i+1, students[i]);
        else printf("%d\t\t%s\n", i+1, "N/A");
    }
}

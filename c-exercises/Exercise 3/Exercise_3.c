#include <stdbool.h>
#include <stdio.h>

int get_student_amount(void) {
    bool valid;
    int student_amount;
    do {
        printf("Enter amount of students (>0): ");
        valid = scanf("%d", &student_amount) && student_amount > 0;
        while (getchar() != '\n');
    } while (!valid);
    return student_amount;
}

int handle_student_selection(int student_amount) {
    int selection;
    printf("Enter student id (1 - %d) or enter 0 to finish: ", student_amount);
    const bool valid = scanf("%d", &selection) && selection >= 0 && selection <= student_amount;
    while (getchar() != '\n');

    if (!valid) {
        printf("Invalid student id.\n");
        return -1;
    }

    return selection;
}

int handle_grade_selection(int student_id) {
    int selection;
    printf("Select grade for student %d (0 - 5), or enter -1 to cancel: ", student_id);
    const bool valid = scanf("%d", &selection) && selection >= -1 && selection <= 5;
    while (getchar() != '\n');

    if (!valid) {
        printf("Invalid grade.\n");
        return -2;
    }

    return selection;
}

int main(void) {
    const int student_amount = get_student_amount();
    int students[student_amount];
    for (int i = 0; i < student_amount; i++) students[i] = -1;
    int student_id = -1;
    while (student_id != 0) {
        student_id = handle_student_selection(student_amount); // Invalid selections return -1
        if (student_id > 0) {
            const int grade = handle_grade_selection(student_id); // Invalid selection & cancel return -1
            if (grade != -1) students[student_id - 1] = grade;
        }
    }

    printf("Student\tGrade\n");
    for (int i = 0; i < student_amount; ++i) {
        if (students[i] != -1) printf("%d\t\t%d\n", i+1, students[i]);
        else printf("%d\t\t%s\n", i+1, "N/A");
    }
}

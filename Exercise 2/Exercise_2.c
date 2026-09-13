#include <stdbool.h>
#include <stdio.h>
#define MONTHS 12

float monthlySalaries[MONTHS], monthlyTaxes[MONTHS], taxRate, incomeLimit, taxOverLimit;

void init(void) {
    bool passed;
    do {
        printf("Enter tax rate: ");
        passed = scanf("%f", &taxRate) == 1 && taxRate >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter income limit: ");
        passed = scanf("%f", &incomeLimit) == 1 && incomeLimit >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter tax rate for income over the limit: ");
        passed = scanf("%f", &taxOverLimit) == 1 && taxOverLimit >= 0;
        while (getchar() != '\n');
    } while (!passed);
}

void collectSalaries(void) {
    for (int i = 0; i < MONTHS; ++i) {
        bool passed;
        float incomeForMonth;
        do {
            printf("Enter income for month %d: ", i + 1);
            passed = scanf("%f", &incomeForMonth) == 1 && incomeForMonth >= 0;
            while (getchar() != '\n');
        } while (!passed);
        monthlySalaries[i] = incomeForMonth;
    }
}

void calculateTaxes(void) {
    float totalIncome = 0;
    bool goneOverLimit = false;
    for (int i = 0; i < MONTHS; ++i) {
        const float salaryForMonth = monthlySalaries[i];
        totalIncome += salaryForMonth;
        const float salaryOverLimit = totalIncome - incomeLimit;    // Deduce income limit from all income so far.
                                                                    // Causes any income over limit to start from 0.
        if (salaryOverLimit > 0 && !goneOverLimit) {
            // We just went over limit
            const float salaryUnderLimit = salaryForMonth - salaryOverLimit; // Get the amount to calculate normally
            monthlyTaxes[i] = salaryUnderLimit * (taxRate / 100) + salaryOverLimit * (taxOverLimit / 100);
            goneOverLimit = true;
        }
        else {
            if (goneOverLimit) monthlyTaxes[i] = salaryForMonth * (taxOverLimit / 100);
            else monthlyTaxes[i] = salaryForMonth * (taxRate / 100);
        }
    }
}

void presentTable(void) {
    printf("%6s%12s%12s\n", "month", "income", "tax");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%6d%12.2f%12.2f\n", i + 1, monthlySalaries[i], monthlyTaxes[i]);
    }
}

int main(void) {
    init();
    collectSalaries();
    calculateTaxes();
    presentTable();
}
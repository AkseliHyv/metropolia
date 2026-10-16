#include <stdbool.h>
#include <stdio.h>
#define MONTHS 12

float monthly_salaries[MONTHS], monthly_taxes[MONTHS], tax_rate, income_limit, tax_over_limit;

void init(void) {
    bool passed;
    do {
        printf("Enter tax rate: ");
        passed = scanf("%f", &tax_rate) == 1 && tax_rate >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter income limit: ");
        passed = scanf("%f", &income_limit) == 1 && income_limit >= 0;
        while (getchar() != '\n');
    } while (!passed);
    do {
        printf("Enter tax rate for income over the limit: ");
        passed = scanf("%f", &tax_over_limit) == 1 && tax_over_limit >= 0;
        while (getchar() != '\n');
    } while (!passed);
}

void collect_salaries(void) {
    for (int i = 0; i < MONTHS; ++i) {
        bool passed;
        float income_for_month;
        do {
            printf("Enter income for month %d: ", i + 1);
            passed = scanf("%f", &income_for_month) == 1 && income_for_month >= 0;
            while (getchar() != '\n');
        } while (!passed);
        monthly_salaries[i] = income_for_month;
    }
}

void calculate_taxes(void) {
    float total_income = 0;
    bool gone_over_limit = false;
    for (int i = 0; i < MONTHS; ++i) {
        const float salary_for_month = monthly_salaries[i];
        total_income += salary_for_month;
        const float salary_over_limit = total_income - income_limit;    // Deduce income limit from all income so far.
                                                                    // Causes any income over limit to start from 0.
        if (salary_over_limit > 0 && !gone_over_limit) {
            // We just went over limit
            const float salary_under_limit = salary_for_month - salary_over_limit; // Get the amount to calculate normally
            monthly_taxes[i] = salary_under_limit * (tax_rate / 100) + salary_over_limit * (tax_over_limit / 100);
            gone_over_limit = true;
        }
        else {
            if (gone_over_limit) monthly_taxes[i] = salary_for_month * (tax_over_limit / 100);
            else monthly_taxes[i] = salary_for_month * (tax_rate / 100);
        }
    }
}

void present_table(void) {
    printf("%6s%12s%12s\n", "month", "income", "tax");
    for (int i = 0; i < MONTHS; ++i) {
        printf("%6d%12.2f%12.2f\n", i + 1, monthly_salaries[i], monthly_taxes[i]);
    }
}

int main(void) {
    init();
    collect_salaries();
    calculate_taxes();
    present_table();
}
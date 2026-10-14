#include <stdio.h>

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
void displayMenu();

int main() {
    int choice;
    float amount, basic, housing, transport, revenue, expenses, result;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 2:
                printf("Basic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;

            case 3:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                result = calculateBudget(revenue, expenses);
                if (result > 0) printf("SURPLUS: %.2f\n", result);
                else if (result < 0) printf("DEFICIT: %.2f\n", -result);
                else printf("BALANCED\n");
                break;

            case 4:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

void displayMenu() {
    printf("\n================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}
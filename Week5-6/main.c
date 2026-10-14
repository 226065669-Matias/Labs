#include <stdio.h>

#define SIZE 50

int main() {

    float salaries[SIZE];
    float total = 0;
    float highest, lowest;
    float average;
    float searchValue;
    int found = 0;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        total += salaries[i];

        if (i == 0) {
            highest = salaries[i];
            lowest = salaries[i];
        }
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest = salaries[i];
    }

    average = total / SIZE;

    printf("\n--- Salary Report ---\n");
    printf("Total: %.2f\n", total);
    printf("Average: %.2f\n", average);
    printf("Highest: %.2f\n", highest);
    printf("Lowest: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchValue);

    for (int i = 0; i < SIZE; i++) {
        if (salaries[i] == searchValue) {
            found = 1;
            printf("Found at position %d\n", i);
            break;
        }
    }
    if (!found) printf("Salary not found.\n");

    // Bubble sort ascending
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\nSorted salaries:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}
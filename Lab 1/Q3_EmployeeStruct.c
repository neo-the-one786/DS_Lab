// 1.3 Write a program to create a structure to store the information of n number of Employees. Employee’s
// information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the
// information of employees with gross salary. Use array of structure.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
typedef struct {
    int empID;
    char name[MAX_SIZE], desig[MAX_SIZE];
    float basic_salary, hra, da;
} Employee;

int main() {
    int n;
    printf("\nEnter number of employees: ");
    scanf("%d", &n);
    Employee *arr = (Employee *) malloc(n * sizeof(Employee));
    for (int i = 0; i < n; i++) {
        printf("\n\nEnter Employee %d Information: ", i + 1);
        printf("\nID: ");
        scanf("%d", &arr[i].empID);
        printf("\nName: ");
        scanf("%s", arr[i].name);
        printf("\nDesignation: ");
        scanf("%s", arr[i].desig);
        printf("\nBasic Salary: ");
        scanf("%f", &arr[i].basic_salary);
        printf("\nHRA: ");
        scanf("%f", &arr[i].hra);
        printf("\nDA: ");
        scanf("%f", &arr[i].da);
    }
    for (int i = 0; i < n; i++) {
        printf("\n\nEmployee %d: ", i + 1);
        printf("\nID: %d", arr[i].empID);
        printf("\nName: %s", arr[i].name);
        printf("\nDesignation: %s", arr[i].desig);
        printf("\nBasic Salary: %.2f", arr[i].basic_salary);
        printf("\nHRA: %.2f", arr[i].hra);
        printf("\nDA: %.2f", arr[i].da);
        printf("\nGross Salary: %.2f", arr[i].basic_salary + arr[i].hra + arr[i].da);
    }
    free(arr);
}
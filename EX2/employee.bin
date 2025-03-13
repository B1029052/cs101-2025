#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} employee_t;

void emp_readfile() {
    FILE* fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        perror("檔案開啟失敗");
        return;
    }

    employee_t emp;
    while (fread(&emp, sizeof(employee_t), 1, fp)) {
        printf("ID: %d, Name: %s, Age: %d, Salary: %.2f\n", emp.id, emp.name, emp.age, emp.salary);
    }

    fclose(fp);
}

int main() {
    emp_readfile();
    return 0;
}

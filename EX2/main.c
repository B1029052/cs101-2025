#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    double salary;
} employee_t;

// 員工資訊輸出函式
void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %.6lf\n\n", emp.salary);
}

// 將員工資訊寫入二進位檔案
void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    if (fp == NULL) {
        perror("檔案開啟失敗");
        return;
    }
    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
}

// 讀取員工資訊的二進位檔案
void emp_readfile(employee_t emp[]) {
    FILE* fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        perror("檔案開啟失敗");
        return;
    }
    int i = 0;
    employee_t tmp;
    while (fread(&tmp, sizeof(employee_t), 1, fp)) {
        emp[i] = tmp; // 將讀取的數據存入陣列
        i++;
    }
    fclose(fp);
}

int main() {
    employee_t emp[3];

    // 初始化員工數據
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");

    // 寫入檔案
    emp_writefile(emp, 3);

    // 讀取檔案
    employee_t read_emp[10];
    emp_readfile(read_emp);

    // 輸出讀取結果
    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}

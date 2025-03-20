#include <stdio.h>

int main() {
    char v = 'A';
    int* p = NULL;
    p = &v;  // 錯誤：將 char* 指派給 int*，導致錯誤讀取

    printf("Address of v: %x\n", v);
    printf("Address stored in p: %x\n", p);
    printf("Address of p: %x\n", &p);
    printf("Value of *p: %d\n", *p);  // 錯誤的數值
    return 0;
}

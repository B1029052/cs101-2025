#include <stdio.h>

int main() {
    int* ip;
    ip = 2;  // 錯誤：試圖將整數賦值給指標
    printf("%x\n", ip);
    printf("%x\n", *ip);  // Segmentation Fault
    return 0;
}

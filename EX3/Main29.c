#include <stdio.h>

int main() {
    int* ip;
    *ip = 2;  // 錯誤：未初始化指標，導致 Segmentation Fault
    printf("%x\n", *ip);
    return 0;
}

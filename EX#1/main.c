#include <stdio.h>

int main() {
    // 宣告三個陣列
    int a[] = {0, 1, 2};
    char b[] = "ABC";  // 字串實際上會存成 {'A', 'B', 'C', '\0'}
    float c[] = {1.1, 1.2, 1.3};

    // 開啟檔案 (二進位寫入)
    FILE *fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入。\n");
        return 1;
    }

    // 寫入陣列到 a.bin
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);  // 只寫入 'A', 'B', 'C'，不包含 '\0'
    fwrite(c, sizeof(float), 3, fp);

    fclose(fp);  // 關閉檔案

    // 重新開啟檔案 (二進位讀取)
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取。\n");
        return 1;
    }

    // 宣告讀取用變數
    int ra[3];
    char rb[3];
    float rc[3];

    // 讀取檔案內容到變數
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 3, fp);
    fread(rc, sizeof(float), 3, fp);

    fclose(fp);  // 關閉檔案

    // 輸出讀取結果
    printf("%d %d %d\n", ra[0], ra[1], ra[2]);
    printf("%c %c %c\n", rb[0], rb[1], rb[2]);
    printf("%.6f %.6f %.6f\n", rc[0], rc[1], rc[2]);

    return 0;
}

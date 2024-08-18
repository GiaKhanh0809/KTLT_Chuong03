﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Hàm chèn từ vào vị trí bất kỳ trong chuỗi
void chenTu(char* str, const char* tu, int viTri) {
    int len = strlen(str);
    int tuLen = strlen(tu);
    if (viTri > len) viTri = len;
    memmove(str + viTri + tuLen, str + viTri, len - viTri + 1);
    memcpy(str + viTri, tu, tuLen);
}

// Hàm xóa từ trong chuỗi
void xoaTu(char* str, const char* tu) {
    char* pos = strstr(str, tu);
    if (pos) {
        int len = strlen(tu);
        memmove(pos, pos + len, strlen(pos + len) + 1);
    }
}

// Hàm đếm tần suất xuất hiện của mỗi ký tự trong chuỗi
void demTanSuat(const char* str) {
    int freq[256] = { 0 };
    while (*str) {
        freq[(unsigned char)*str]++;
        str++;
    }
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("Ky tu %c xuat hien %d lan.\n", i, freq[i]);
        }
    }
}

// Hàm tìm ký tự xuất hiện nhiều nhất trong chuỗi
char timKyTuXuatHienNhieuNhat(const char* str) {
    int freq[256] = { 0 };
    while (*str) {
        freq[(unsigned char)*str]++;
        str++;
    }
    int maxFreq = 0;
    char maxChar = '\0';
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = i;
        }
    }
    return maxChar;
}

int main() {
    char str[100], ten[30], hoLot[100], tenTimKiem[30];

    printf("Nhap chuoi: ");
    scanf("%s", &str);

    // 6. Chèn từ vào vị trí bất kỳ
    char tuChen[30];
    int viTriChen;
    printf("Nhap tu can chen: ");
    scanf("%s", tuChen);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &viTriChen);
    getchar(); // Đọc ký tự xuống dòng
    chenTu(str, tuChen, viTriChen);
    printf("Chuoi sau khi chen tu: %s\n", str);

    // 7. Xóa từ trong chuỗi
    char tuXoa[30];
    printf("Nhap tu can xoa: ");
    scanf("%s", tuXoa);
    xoaTu(str, tuXoa);
    printf("Chuoi sau khi xoa tu: %s\n", str);

    // 8. Đếm tần suất xuất hiện của mỗi ký tự
    printf("Tan suat xuat hien cua moi ky tu:\n");
    demTanSuat(str);

    // 9. Tìm ký tự xuất hiện nhiều nhất
    char kyTuNhieuNhat = timKyTuXuatHienNhieuNhat(str);
    printf("Ky tu xuat hien nhieu nhat: %c\n", kyTuNhieuNhat);

    return 0;
}
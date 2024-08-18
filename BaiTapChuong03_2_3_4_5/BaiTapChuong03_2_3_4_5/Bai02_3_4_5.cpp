#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Bài 2: Đếm số lượng khoảng trắng trong chuỗi
int demKhoangTrang(const char* str) {
    int count = 0;
    while (*str) {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count;
}

// Bài 3: Xóa những khoảng trắng thừa trong chuỗi
void xoaKhoangTrangThua(char* str) {
    int len = strlen(str);
    int j = 0;
    int i = 0;

    while (str[i]) {
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1]))) {
            str[j++] = str[i];
        }
        i++;
    }

    // Loại bỏ khoảng trắng ở cuối chuỗi
    if (j > 0 && isspace(str[j - 1])) {
        j--;
    }

    str[j] = '\0';
}

// Bài 4: Đổi kí tự đầu tiên của mỗi từ thành chữ in hoa và các từ khác thành chữ thường
void chuanHoaChuoi(char* str) {
    int capitalize = 1; // Biến đánh dấu để chuyển kí tự đầu tiên thành chữ in hoa

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            capitalize = 1;
        }
        else if (capitalize && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize = 0;
        }
        else {
            str[i] = tolower(str[i]);
        }
    }
}

// Bài 5: Tìm kiếm tên trong chuỗi họ tên
void timKiemTen(const char* hoTen, const char* ten) {
    // Tách tên từ chuỗi họ tên
    const char* p = strrchr(hoTen, ' ');
    if (p != NULL) {
        p++; // Tên nằm sau khoảng trắng cuối cùng
    }
    else {
        p = hoTen; // Nếu không có khoảng trắng, toàn bộ chuỗi là tên
    }

    // So sánh tên với chuỗi nhập vào
    if (strcmp(p, ten) == 0) {
        printf("Ten '%s' da nhap dung.\n", ten);
    }
    else {
        printf("Ten '%s' da nhap sai.\n", ten);
    }
}

int main() {
    char str[100];
    char hoTen[100], ten[50];

    // Nhập chuỗi và thực hiện các bài tập
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký tự newline

    // Bài 2: Đếm số lượng khoảng trắng trong chuỗi
    int soKhoangTrang = demKhoangTrang(str);
    printf("So luong khoang trang trong chuoi la: %d\n", soKhoangTrang);

    // Bài 3: Xóa những khoảng trắng thừa trong chuỗi
    xoaKhoangTrangThua(str);
    printf("Chuoi sau khi xoa khoang trang thua: '%s'\n", str);

    // Bài 4: Đổi kí tự đầu tiên của mỗi từ thành chữ in hoa và các từ khác thành chữ thường
    chuanHoaChuoi(str);
    printf("Chuoi sau khi chuan hoa: '%s'\n", str);

    // Bài 5: Tìm kiếm tên trong chuỗi họ tên
    printf("\nNhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự newline

    printf("Nhap ten can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0'; // Xóa ký tự newline

    timKiemTen(hoTen, ten);

    return 0;
}

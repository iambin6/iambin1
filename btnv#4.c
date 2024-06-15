#include <stdio.h>
#include <string.h>

int validate_isbn(char isbn[]) {
    int i, total = 0, weight = 10;

    if (strlen(isbn) != 10) {
        return 0;
    }

    for (i = 0; i < 9; i++) {
        total += (isbn[i] - '0') * weight;
        weight--;
    }
	//Kiem tra xem tong co chia het cho 11 khong
    int check_digit = isbn[9] - '0';
    if ((total + check_digit) % 11 == 0) {
        return 1;
    }

    return 0;
}

int main() {
    char isbn[11];

    printf("Nhap vao so ISBN: ");
    scanf("%10s", isbn);

    if (validate_isbn(isbn)) {
        printf("So ISBN hop le.\n");
    } else {
        printf("So ISBN khong hop le.\n");
    }

    return 0;
}

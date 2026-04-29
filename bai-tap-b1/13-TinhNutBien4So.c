

/*13. Nhập vào số xe (gồm 4 chữ số) của bạn. 
Cho biết số xe của bạn được mấy nút?*/
#include <stdio.h>
void main() {
    int soXe, sum = 0;
    printf("Nhap so xe (4 chu so): ");
    scanf("%d", &soXe);

    int temp = soXe;
    while (temp > 0) {
        sum += temp % 10;   // lấy chữ số cuối
        temp /= 10;         // bỏ chữ số cuối
    }

    int nut = sum % 10;     // số nút là tổng chữ số mod 10
    printf("So xe %d co %d nut\n", soXe, nut);
}

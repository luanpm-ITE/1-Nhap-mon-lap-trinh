

/*4.  Viết chương trình nhập vào một số 
nguyên 3 
chữ số (từ 100 - 999), sau đó in ra các 
chữ 
số thuộc hàng trăm, hàng chục, hàng đơn 
vị.*/
#include <stdio.h>
void main()
{
   int n;
   printf("Nhap mot so nguyen 3 chu so: ");
   scanf("%d", &n);

   if (n >= 100 && n <= 999)
   {
      printf("Chu so hang tram: %d\n", n / 100);
      printf("Chu so hang chuc: %d\n", (n / 10) % 10);
      printf("Chu so hang don vi: %d\n", n % 10);
   }
   else
   {
      printf("So vua nhap khong phai la so nguyen 3 chu so!\n");
   }
}
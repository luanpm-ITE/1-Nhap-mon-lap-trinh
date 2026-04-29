

/*8.  Viết hàm nhập vào số có hai chữ số , in ra
cách đọc của số đó. Ví dụ : n=35 : ba mươi
lăm.*/
#include <stdio.h>

void docSo(int n)
{
   char *chuSo[] = {"khong", "mot", "hai", "ba", "bon",
                    "nam", "sau", "bay", "tam", "chin"};

   int chuc = n / 10;
   int donvi = n % 10;

   // đọc hàng chục
   if (chuc == 1)
   {
      printf("muoi");
   }
   else
   {
      printf("%s muoi", chuSo[chuc]);
   }

   // đọc hàng đơn vị
   if (donvi != 0)
   {
      if (donvi == 5)
      {
         printf(" lam"); // quy tắc đọc số 5 ở cuối
      }
      else
      {
         printf(" %s", chuSo[donvi]);
      }
   }
   printf("\n");
}

int main()
{
   int n;
   printf("Nhap so co 2 chu so: ");
   scanf("%d", &n);

   if (n < 10 || n > 99)
   {
      printf("Khong hop le! Vui long nhap so co 2 chu so.\n");
   }
   else
   {
      docSo(n);
   }

   return 0;
}

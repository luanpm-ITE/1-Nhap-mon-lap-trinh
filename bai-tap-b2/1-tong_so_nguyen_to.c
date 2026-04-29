

/*1.  Viết chương trình tính tổng các 
số nguyên tố
nhỏ hơn số nguyên dương n. */
#include <stdio.h>
#include <stdbool.h>
// Hàm kiểm tra số nguyên tố
bool isPrime(int x)
{
   if (x < 2)
      return false;
   for (int i = 2; i * i <= x; i++)
   {
      if (x % i == 0)
         return false;
   }
   return true;
}
int main()
{
   int n, sum = 0;
   printf("Nhap so nguyen duong n: ");
   scanf("%d", &n);

   for (int i = 2; i < n; i++)
   {
      if (isPrime(i))
      {
         sum += i;
      }
   }

   printf("Tong cac so nguyen to nho hon %d la %d\n", n, sum);
   return 0;
}

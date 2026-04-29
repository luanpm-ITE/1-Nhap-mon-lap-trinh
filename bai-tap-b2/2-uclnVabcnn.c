

/*2.  Viết  hàm  tìm ướ c  số  chung  lớn  
nhất  và
bô ̣i  số  chung  nhổ  nhát  của  2  số  
nguyên
dương a và b. */
#include <stdio.h>
// Hàm tìm UCLN bằng thuật toán Euclid
int gcd(int a, int b)
{
   while (b != 0)
   {
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}
// Hàm tìm BCNN dựa vào UCLN
int lcm(int a, int b)
{
   return (a * b) / gcd(a, b);
}
int main()
{
   int a, b;
   printf("Nhap hai so nguyen duong a va b: ");
   scanf("%d %d", &a, &b);

   printf("UCLN(%d, %d) = %d\n", a, b, gcd(a, b));
   printf("BCNN(%d, %d) = %d\n", a, b, lcm(a, b));

   return 0;
}

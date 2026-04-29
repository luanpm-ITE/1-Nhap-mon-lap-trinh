

/*10. Nhập 03 số a,b,c từ bàn phím. 
Tìm số lớn nhất
trong 3 số.*/
#include <stdio.h>
void main()
{
   int a,b,c;
   c=(a>b)?a:b;
   printf("Nhap a,b,c: ");
   scanf("%d%d%d",&a,&b,&c);
   printf("\nSo lon nhat la: %d",((b>c)?b:c)); 
}
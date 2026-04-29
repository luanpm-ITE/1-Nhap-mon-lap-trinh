
 
/*1.  Viết chương trình nhập 2 số 
nguyên a và b. 
Tính tổng, hiệu, tính, thương và tổng bình 
phương của hai số.*/
#include <stdio.h>
void main()
{
   float a,b;
   printf("Nhap a,b: ");
   scanf("%f%f",&a,&b);

   printf("\nTong: %.2f",a+b);
   printf("\nHieu: %.2f",a-b);
   printf("\nTich: %.2f",a*b);
   printf("\nThuong: %.2f",a/b);
   printf("\nTong pow 2 so: %.2f",a*a+b*b);
}
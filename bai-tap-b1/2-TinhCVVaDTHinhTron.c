

/*2.  Viết chương trình cho biết bán 
kính của đường tròn. 
Tính chu vi và diện tích của hình tròn đó*/
#include <stdio.h>
void main()
{
   float r;
   const float pi=3.14;
   printf("Nhap r: ");
   scanf("%f",&r);
   
   printf("\nChu vi: %.2f",2*pi*r);
   printf("\nDien tich: %.2f",pi*r*r);
}
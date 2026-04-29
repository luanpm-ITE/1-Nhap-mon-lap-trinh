

/*12. Nhập tên sản phẩm, số lượng và 
đơn giá. 
Tính tiền và thuế giá trị gia tăng 
phải trả, biết: 
a) tiền = số lượng * đơn giá 
b) thuế giá trị gia tăng = 10% tiền*/
#include <stdio.h>
void main()
{
   char tensp[30];
   float sl,dongia,tien,gtgt;
   printf("\nNhap ten san pham(viet lien khong dau): ");
   scanf("%s",&tensp);
   printf("\nNhap so luong: ");
   scanf("%f",&sl);
   printf("\nNhap don gia: ");
   scanf("%f",&dongia);
   printf("\nTong tien: %.2f",tien=sl*dongia);
   printf("\nThue gia tri gia tang: %.2f",
      gtgt=tien*0.1);
}


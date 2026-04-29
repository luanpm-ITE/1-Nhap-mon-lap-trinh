

/*3.  Viết chương trình nhập  điểm  thi  3  môn  Toán,  
Lý,  Hóa  của  một  sinh  viên.  Tính  điểm 
trung bình của sinh viên đó.*/
#include <stdio.h>
void main()
{
   int toan,ly,hoa;
   printf("Nhap diem toan, ly va hoa: ");
   scanf("%d%d%d",&toan,&ly,&hoa);
   
   printf("\nTrung binh: %d",(toan+ly+hoa)/3);
}
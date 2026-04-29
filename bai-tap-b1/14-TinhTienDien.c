

/*14. Nhập  vào  số  Kwh  tiêu  thụ  
điện.  Tính  tiền điện  phải  trả  
biết  rằng  cách  thức  tính  tiền 
theo qui định như sau: 100 kwh định 
mức đầu tiên có đơn giá trung bình 
là 600đ/kwh. 
Các kwh từ 101 đến 150 có đơn giá 
là 700đ/kwh. Các kwh từ 151 đến 200 
có đơn giá 
là 900đ/kwh. Các kwh từ 201 trở đi 
có đơn giá là 1100đ/kwh. */
#include <stdio.h>
#include <conio.h>
void main()
{
   tt:
   float so_kwh;
   printf("\nNhap so kwh tieu thu: ");
   scanf("%f",&so_kwh);
   if(so_kwh!=0)
   {
      if(so_kwh<100&&so_kwh>=1)
         printf("\nDon gia: %.2f",600*so_kwh);
      else if(so_kwh<150&&so_kwh>=101)
         printf("\nDon gia: %.2f",700*so_kwh);
      else if(so_kwh<200&&so_kwh>=151)
         printf("\nDon gia: %.2f",900*so_kwh);
      else printf("\nDon gia: %.2f",1100*so_kwh);
   }
   else printf("\nNhap so kwh tu 1-->500");
   printf("\nCo tiep tuc khong?c/K? ");
   if(getch()=='c'||getch()=='C')goto tt;
}
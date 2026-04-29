

/*//11. Nhập năm sinh của một người. 
Tính tuổi người đó*/
#include <stdio.h>
void main()
{
   int namsinh,namhientai;
   printf("\nNhap nam sinh: ");
   scanf("%d",&namsinh);
   printf("\nNhap nam hien tai: ");
   scanf("%d",&namhientai);

   printf("\nTuoi: %d",namhientai-namsinh);
}
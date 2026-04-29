

/*3.  Viết hàm trả về giá trị nhỏ nhất của 4 số nguyên */
#include <stdio.h>

int timMin(int a,int b,int c,int d,int *s)
{
   c=(a<b)?a:b;
   d=(b<c)?b:c;
   *s=(c<d)?c:d;
   return *s;
}

int main()
{  
   int a,b,c,d,s,kq;
   printf("\nNhap vao a,b,c va d: ");
   scanf("%d%d%d%d",&a,&b,&c,&d);
   kq=timMin(a,b,c,d,&s);
   printf("\nSo nho nhat la: %d",kq);
   return 0;
}
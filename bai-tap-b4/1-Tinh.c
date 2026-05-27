

#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct
{
   char maTinh[10];
   char tenTinh[50];
   long long danSo;
   double dienTich;
}Tinh;
void nhapTinh(Tinh *t)
{
   printf("\nNhap ma tinh: ");
   scanf("%s",&t->maTinh);getchar();
   printf("Nhap ten tinh: ");
   scanf("%s",&t->tenTinh);getchar();
   printf("Nhap dan so: ");
   scanf("%lld",&t->danSo);getchar();
   printf("Nhap dien tich: ");
   scanf("%lf",&t->dienTich);getchar();
}
void xuatTinh(Tinh t)
{
   printf("\n Ma tinh: %s",t.maTinh);
   printf("\n Ten tinh: %s",t.tenTinh);
   printf("\n Dan so: %lld",t.danSo);
   printf("\n Dien tich: %.2lf",t.dienTich);
}
void xuatTinhCoDanSoLon(Tinh ds[],int n)
{
   long long ds1M=1000000;
   for(int i=1;i<n+1;++i)
   {
      if(ds[i].danSo>ds1M)
         xuatTinh(ds[i]);
         printf("----------------\n");
   }
}
Tinh dienTichTinhLonNhat(Tinh ds[],int n)
{
   Tinh maxDT=ds[0];
   for(int i=1;i<n+1;++i)
   {
      if(maxDT.dienTich<ds[i].dienTich)
         maxDT.dienTich=ds[i].dienTich;
   }
   return maxDT;
} 
int main()
{
   Tinh ds[10];
   int n;
   printf("\nNhap so luong tinh: ");
   scanf("%d",&n);
   printf("\n-----NHAP DANH SACH TINH-----");
   for(int i=1;i<n+1;++i)
   {
      printf("\nTinh thu: %d",i);
      nhapTinh(&ds[i]);
   }
   printf("\n-----XUAT DANH SACH TINH-----");
   for(int i=1;i<n+1;++i)
   {
      printf("\nThong tin tinh thu: %d",i);
      xuatTinh(ds[i]);
   }
   printf("\nTinh co dan so hon 1M: ");
   xuatTinhCoDanSoLon(ds,n);
   printf("\nTinh co dien tich lon nhat: ");
   dienTichTinhLonNhat(ds,n);
   return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tagNode
{
   char maSV[10];
   char ht[30];
   float diemtb;
   struct tagNode *next;
}SinhVien;
void nhapSinhVien(SinhVien *sv)
{
   printf("\nMa sv: ");
   scanf("%s",&sv->maSV);getchar();
   printf("Ho ten: ");
   scanf("%s",&sv->ht);getchar();
   printf("Gioi tinh: ");
   scanf("%s",&sv->gt);getchar();
   printf("Dia chi: ");
   scanf("%s",&sv->dc);getchar();
   printf("Diem tb: ");
   scanf("%f",&sv->diemtb);getchar();
}
void xuatSinhVien(SinhVien sv)
{
   printf("\nMa sv: %s",sv.maSV);
   printf("\nHo ten: %s",sv.ht);
   printf("\nGioi tinh: %s",sv.gt);
   printf("\nDia chi: %s",sv.dc);
   printf("\nDiem tb: %.2f",sv.diemtb);
}
SinhVien* timSV(SinhVien dssv[],int n,SinhVien x )
{
   int i=0;
   dssv[n]=x;
   while(dssv[i].maSV!=x.maSV)
      ++i;
   return &dssv[i];
}
int main()
{
   SinhVien dssv[150];int slsv;
   printf("\nNhap so luong sv: ");
   scanf("%d",&slsv);
   for(int i=1;i<slsv+1;++i)
   {
      printf("\nSinh vien thu: %d",i);
      nhapSinhVien(&dssv[i]);
   }
   printf("\n\t---DANH SACH SINH VIEN---");
   for(int i=1;i<slsv+1;++i)
   {
      printf("\nThong tin sv thu: %d",i);
      xuatSinhVien(dssv[i]);
   }
   do
   {
      printf("\n\t\t---MENU---");
      printf("\n 1.Tim kiem SV");
      printf("\n 2.Them 1 SV");
      printf("\n 3.Xoa 1 SV");
      printf("\n 4.Xuat SV no diem");
      printf("\nChon ");int choice;
      scanf("%d",&choice);
      switch (choice)
      {
      case 1:
         printf("dfjjd");
         break;
      
      default:printf("\nChon tu 1-->4 thoi!");
         break;
      }
   } while (0);
   



   return 0;
}
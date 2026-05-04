

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   int choice,m,n,a[10][10],b[10][10],c[10][10];
   int arr[3*3];
   int k=0;
   printf("\nNhap m va n: ");scanf("%d%d",&m,&n);
   for(int i=0;i<m;++i)
   {
      for(int j=0;j<n;++j)
      {
         a[i][j]=(rand()%201)-100;
      }
   }
   for(int i=0;i<m;++i)
   {
      for(int j=0;j<n;++j)
      {
         b[i][j]=(rand()%201)-100;
      }
   }
   tt:
   do
   {
      printf("----MENU-----");
      printf("\n 1. Xuat ma tran ngau nhien");
      printf("\n 2. Tim min max");
      printf("\n 3. Sap xep tang");
      printf("\n 4. Tinh tong & tich cua ma tran");
      printf("\n 5. Tinh tong & tich cua 2 ma tran");
      printf("\n 6. Dem duong");
      printf("\n 7. Dem chan");
      printf("\n Chon: ");
      scanf("%d",&choice);
   } while (0);
   switch (choice)
   {
   case 1:
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            printf("%d\t",a[i][j]);
         }
         printf("\n");
      }
      break;
   case 2:
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            printf("%d\t",a[i][j]);
         }
         printf("\n");
      }
      int min=a[0][0],max=a[0][0];
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            if(a[i][j]<min)
               min=a[i][j];
            if(a[i][j]>max)
               max=a[i][j];
         }
      }
      printf("\nPhan tu min: %d",min);
      printf("\nPhan tu max: %d",max);
      break;
   case 3:
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            printf("%d\t",a[i][j]);
         }
         printf("\n");
      }
      //chuyen ma tran thanh mang 1c
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            arr[k++]=a[i][j];
         }
      }
      //thuat toan sap tang
      for(int i=0;i<k-1;++i)
      {
         for(int j=k-1;j>i;--j)
         {
            if(arr[j-1]>arr[j])
            {
               int temp=arr[j-1];
               arr[j-1]=arr[j];
               arr[j]=temp;
            }
         }
      }
      //chuyen mang 1c thanh ma tran
      k=0;
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            a[i][j]=arr[k++];
         }
      }
      printf("\nMa tran sau khi sap tang:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            printf("%d\t",a[i][j]);
         }
         printf("\n");
      }
      break;
   case 4:
      int tong=0;
      long long tich=0;
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
         {
            printf("%d\t",a[i][j]);
            tong+=a[i][j];
            tich*=a[i][j];
         }
         printf("\n");
      }
      printf("\nTong: %d",tong);
      printf("\nTich: %lld",tich);
      break;
   case 5:
      printf("Ma tran ngau nhien A:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            printf("%d\t",a[i][j]);
         printf("\n");
      }
      printf("Ma tran ngau nhien B:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            printf("%d\t",b[i][j]);
         printf("\n");
      }
      //Thuat toan tong 2 ma tran
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            c[i][j]=a[i][j]+b[i][j];
      }
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            c[i][j]=a[i][j]+b[i][j];
      }
      printf("Ma tran tong C:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            printf("%d\t",c[i][j]);
         printf("\n");
      }
      break;
   case 6:
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            printf("%d\t",a[i][j]);
         printf("\n");
      }
      int count=0;
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            if(a[i][j]>0) ++count;  
      }
      printf("\nSo phan tu duong: %d",count);
      break;
   case 7:
      printf("Ma tran ngau nhien:\n");
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            printf("%d\t",a[i][j]);
         printf("\n");
      }
      int chan=0;
      for(int i=0;i<m;++i)
      {
         for(int j=0;j<n;++j)
            if(a[i][j]%2==0) ++chan;  
      }
      printf("\nSo phan tu chan: %d",chan);
      break;
   default: printf("\nNhap tu 1-->7 thoi nhe!");
      break;
   }
   printf("\nCo tiep tuc khong?c/K? ");
   if(getch()=='c'||getch()=='C')goto tt;
   return 0;
}
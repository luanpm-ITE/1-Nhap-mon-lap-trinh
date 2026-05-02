

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
int main()
{
  int a[100],n,choice,i=0;
  printf("\nNhap n: ");scanf("%d",&n);
  for(int i=0;i<n;++i)
    a[i]=(rand()%201)-100;
  tt:
  do
  {
    printf("-----MENU-----");
    printf("\n 1. Xuat");
    printf("\n 2. Tinh tong");
    printf("\n 3. Sap xep tang/giam");
    printf("\n 4. Dem duong va xuat tong");
    printf("\n 5. Tim x(ban phim) trong mang");
    printf("\n 6. Tim phan tu lon nhat va dem sluong");
    printf("\n 7. Dem chan/le trong mang");
    printf("\n 0. Thoat!");
    printf("\nChon ");
    scanf("%d",&choice);
  } while (0);
  switch (choice)
  {
  case 1 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    break;
  case 2 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int s=0;
    for(int i=0;i<n;++i)
      s+=a[i];
    printf("\nTong mang: %d",s);
    break;
  case 3 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int min,temp;
    for(int i=0;i<n-1;++i)
    {
      min=i;
      for(int j=i+1;j<n;++j)
      {
        if(a[min]>a[j])
        min=j;
      }
      temp=a[min];a[min]=a[i];a[i]=temp;
    }
    printf("\nMang sau khi sap tang: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    printf("\nMang sau khi sap giam: ");
    for(int i=0;i<n/2;++i)
    {
      int temp=a[i];
      a[i]=a[n-1-i];
      a[n-1-i]=temp;
    }
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    break;
  case 4 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int count=0,countSum=0; 
    while(i<n)
    {
      if(a[i]>0)
      {
        ++count;
        countSum+=a[i];
      }
      ++i;
    }
    printf("\nSo phan tu duong: %d\tTong: %d",
      count,countSum);
    break;
  case 5 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int x;int i=0;
    printf("\nNhap x: ");scanf("%d",&x);
    a[n]=x;
    while(a[i]!=x)
    {
      ++i;
    }
    if(i==n) printf("\nTim khong thay");
    else printf("\n%d thuoc mang",x);
    break;
  case 6 :
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int max=a[0],countM=1;
    for(int i=1;i<n;++i)
    {
      if(a[i]>max)
        max=a[i];
      else if(a[i]==max)
        ++countM;
    }
    printf("\nMax: %d",max);
    printf("\nSo luong max: %d",countM);
    break;
  case 7:
    printf("\nMang ngau nhien: ");
    for(int i=0;i<n;++i)
      printf("%d ",a[i]);
    int chan=0,le=0;
    for(int i=0;i<n;++i)
    {
      if(a[i]%2==0)
        ++chan;
      else ++le;
    }
    printf("\nSo phan tu chan: %d",chan);
    printf("\nSo phan tu le: %d",le);
    break;
  default: printf("\nNhap tu 1-->7 thoi nhe!!");
    break;
  }
  printf("\nCo tiep tuc khong?c/K? ");
  if(getch()=='c'||getch()=='C') goto tt;
  return 0;
}
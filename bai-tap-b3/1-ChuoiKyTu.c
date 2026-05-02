

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
char s[]="Hello World!";
int choice;
int main()
{
   tt:
   do
   {
      printf("-----MENU-----");
      printf("\n 1. Tinh do dai chuoi?");
      printf("\n 2. Dao nguoc chuoi?");
      printf("\n 3. Xuat cac ki tu in hoa?");
      printf("\n 4. Nhap x(phim) kiem tra co nam trong s",
         "neu co thi dem xem xuat hien bao nhieu lan?");
      printf("\n 5. Tim chuoi con subs trong s?");
      printf("\nChon ");
      scanf("%d",&choice);
   } while (0);
   switch (choice)
   {
   case 1:
      int len=strlen(s);
      printf("\nDo dai cua chuoi s la: %d",len);
      break;
   case 2:
      printf("\nChuoi s ban dau la: %s",s);
      int l=0,r=strlen(s)-1;
      char temp;
      while(l<r)
      {
         temp=s[l];s[l]=s[r];s[r]=temp;
         ++l;--r;
      }
      printf("\nChuoi s sau khi dao nguoc la: %s",s);
      break;
   case 3:
      printf("\nCac ky tu in hoa trong chuoi s la: ");
      for(int i=0;i<strlen(s);++i)
      {
         if(isupper(s[i]))
            printf("%c ",s[i]);
      }
      printf("\n");
      break;
   case 4:
      char x;
      printf("\nNhap x ");
      scanf("%c",&x);
      int dem=0;
      for(int i=0;i<strlen(s);++i)
      {
         if(s[i]==x);
            ++dem;
      }
      if(dem>0)
         printf("\nKy tu %c nam trong s va xuat hien %d lan"
            ,x,dem);
      else printf("\nKy tu %c khong nam trong s",x);
      break;
   case 5:
      char subs[]="llo";
      char *pos=strstr(s,subs);
      if(pos!=NULL)
         printf("\n%s 'thuoc' %s",subs,s);
      printf("\n%s '!thuoc' %s",subs,s);
      break;
   default: 
      printf("\nNhap tu 1-->5 thoi nhe");
      break;
   }
   printf("\nCo tiep tuc khong?C/k? ");
   if(getch()=='c'||getch()=='C') goto tt;
   return 0;
}
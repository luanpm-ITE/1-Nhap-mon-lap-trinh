

/*7.  Viết chương trình kiểm tra một số 
nguyên n là 
số nguyên tố không?*/
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
bool isPrime(int n)
{
   if(n<2) return false; //so <2 khong la snt
   for(int i=2;i*i<=n;++i)
      if(n%i==0) return false;
   return true;
}
void main()
{  tt:
   int n;
   printf("\nNhap n: ");scanf("%d",&n);
   if(isPrime(n))
      printf("\n%d la so nguyen to",n);
   else printf("\n%d khong la so nguyen to",n);
   printf("\nCo tiep tuc khong?c/k ");
   if(getch()=='c'||getch()=='C') goto tt;
}


/*4.  Viết chương trình giải phương trình 
bậc 2*/
#include <stdio.h>
#include <math.h>
int ptb2(int a,int b,int c,int *x1,int *x2)
{
   int delta;
   delta=b*b-4*a*c;
   if(delta<0)
      printf("\nPT vo ngiem");
   else if(delta==0)
      printf("\nPT co ngiem kep x= %d",
         *x1=*x2=(-b)/(2*a));
   else 
      printf("\nPT co 2 ngiem phan biet x1= %d\tx2= %d",
      *x1=((-b-sqrt(delta))/(2*a)),
      *x2=((-b+sqrt(delta))/(2*a)));
}
int main()
{  
   int a,b,c,x1,x2;
   printf("\nNhap a,b va c: ");
   scanf("%d%d%d",&a,&b,&c);
   ptb2(a,b,c,&x1,&x2);
   return 0;
}
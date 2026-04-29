

/*6.  Viết chương trình nhập 3 số a, b, c. 
Giải và biện luận phương trình bậc 
hai ax2+bx+c=0*/
#include <stdio.h>
void main()
{
   int a,b,c,x1,x2,delta;
   printf("\nNhap a, b, va c: ");
   scanf("%d%d%d",&a,&b,&c);

   delta=b*b-4*a*c;
   if(delta<0) printf("\nPt vo ngiem");
   else if(delta==0)
      printf("\nPt co ngiem kep x1,x2= %d",
      x1=x2=-(b/2*a));
   else printf("\nPt co 2 ngiem phan biet");
}
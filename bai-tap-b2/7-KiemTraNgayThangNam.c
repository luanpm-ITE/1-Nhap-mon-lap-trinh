

/*7.  Viết hàm nhập vào ngày, tháng, 
năm thỏa điều kiện
 (1<=ngày<=31; 1<=tháng<=12;
năm >1900). Cho biết:
a)  Tháng vừa nhập có bao nhiêu ngày 
và thuộc quý mấy
trông năm.
b) Kiểm tra năm vừa nhập có phải năm nhuận ?
c)  Cho biết ngày vừa nhập là ngày thứ 
baô nhiêu
trông năm?
d) Cho biết ngày vừa nhập là ngày thứ 
mấy trong tuần?*/
#include <stdio.h>
#include <stdbool.h>
// Hàm kiểm tra năm nhuận
bool isLeapYear(int year)
{
   return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
// Hàm trả về số ngày trong tháng
int daysInMonth(int month, int year)
{
   switch (month)
   {
   case 1:
   case 3:
   case 5:
   case 7:
   case 8:
   case 10:
   case 12:
      return 31;
   case 4:
   case 6:
   case 9:
   case 11:
      return 30;
   case 2:
      return isLeapYear(year) ? 29 : 28;
   default:
      return 0;
   }
}
// Hàm xác định quý
int quarterOfYear(int month)
{
   if (month <= 3)
      return 1;
   else if (month <= 6)
      return 2;
   else if (month <= 9)
      return 3;
   else
      return 4;
}
// Hàm tính ngày thứ bao nhiêu trong năm
int dayOfYear(int day, int month, int year)
{
   int sum = day;
   for (int m = 1; m < month; m++)
   {
      sum += daysInMonth(m, year);
   }
   return sum;
}
// Hàm tính thứ trong tuần (Zeller’s Congruence)
int dayOfWeek(int day, int month, int year)
{
   if (month < 3)
   {
      month += 12;
      year -= 1;
   }
   int K = year % 100;
   int J = year / 100;
   int h = (day + (13 * (month + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
   // h = 0: Saturday, 1: Sunday, 2: Monday, ...
   return h;
}
int main()
{
   int day, month, year;
   printf("Nhap ngay, thang, nam: ");
   scanf("%d %d %d", &day, &month, &year);

   if (day < 1 || day > 31 || month < 1 || month > 12 || year <= 1900)
   {
      printf("Du lieu khong hop le!\n");
      return 0;
   }

   // a) số ngày trong tháng và quý
   printf("Thang %d nam %d co %d ngay, thuoc quy %d\n",
          month, year, daysInMonth(month, year), quarterOfYear(month));

   // b) năm nhuận?
   if (isLeapYear(year))
      printf("Nam %d la nam nhuan\n", year);
   else
      printf("Nam %d khong phai nam nhuan\n", year);

   // c) ngày thứ bao nhiêu trong năm
   printf("Ngay %d/%d/%d la ngay thu %d trong nam\n",
          day, month, year, dayOfYear(day, month, year));

   // d) ngày thứ mấy trong tuần
   int h = dayOfWeek(day, month, year);
   char *thu[] = {"Thu bay", "Chu nhat", "Thu hai", "Thu ba", "Thu tu", "Thu nam", "Thu sau"};
   printf("Ngay %d/%d/%d la %s\n", day, month, year, thu[h]);

   return 0;
}

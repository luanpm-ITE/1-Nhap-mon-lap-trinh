

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
   int stt;
   char mahp[10];
   char tenmh[30];
   int sotc;
   float diemhp;
}HocPhan;
typedef struct tagNode
{
   HocPhan info;
   struct tagNode *next;
}Node;
typedef struct
{
   Node *head,*tail;
}List;
void createList(List *l)
{
   l->head=NULL;
   l->tail=NULL;
}
Node* createNode(HocPhan hp)
{
   Node *p=(Node*)malloc(sizeof(Node));
   p->info=hp;
   p->next=NULL;
}
void addHead(List *l,Node* p)
{
   if(l->head==NULL)
   {
      l->head=p;
      l->tail=p;
   }
   else
   {
      p->next=l->head;
      l->head=p;
   }
}
void addTail(List *l,Node* p)
{
   if(l->head==NULL)
   {
      l->head=p;
      l->tail=p;
   }
   else
   {
      l->tail->next=p;
      l->tail=p;
   }
}
void layDanhSachHocPhan(List l)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem:%.2f",p->info.stt,
      p->info.mahp,p->info.tenmh,p->info.sotc,p->info.diemhp);
      p=p->next;
   }
}

/*int stt;
   char mahp[10];
   char tenmh[30];
   int sotc;
   float diemhp;*/
int main()
{
   List dshp;Node *p;
   HocPhan hp[]=
   {
      {1,"IT001","Nhap mon lap trinh",4,6.8},
      {2,"MA003","Dai so tuyen tinh",3,7.8},
      {3,"IE005","Gioi thieu nganh CNTT",1,8.5},
      {4,"ENG01","Anh van 1",4,6},
      {5,"MA006","Giai tich",4,5.7},
      {6,"SS006","Phap luat dai cuong",2,6},
      {7,"IT003","Cau truc du lieu va giai thuat",4,7},
      {8,"ENG02","Anh van 2",4,7.5},
      {9,"SS004","Ky nang nghe ngiep",2,7.4},
      {10,"MA004","Cau truc roi rac",4,8.1},
      {11,"IT002","Lap trinh huong doi tuong",4,7.6},
      {12,"IT012","To chuc va cau truc may tinh",4,6.2},
      {13,"IT004","Co so du lieu",4,7.3},
      {14,"ENG03","Anh van 3",4,6},
      {15,"IT005","Nhap mon lap mang may tinh",4,5.8},
      {16,"MA005","Xac suat thong ke",3,8.4},
      {17,"IE103","Quan ly thong tin",4,7.3},
      {18,"SS007","Triet hoc Mac-Lenin",3,6.8},
      {19,"SS003","Tu tuong HCM",2,7},
      {20,"IE101","Co so ha tang CNTT",3,6.8},
      {21,"IT007","He dieu hanh",4,5.8},
      {22,"SS009","Chu nghia xa hoi khoa hoc",0,0},
      {23,"SS008","Kinh te chinh tri Mac-Lenin",0,0},
      {24,"IE303","Cong nghe Java",0,0},
      {25,"IE104","Internet va cong nghe Wed",0,0},
      {26,"IE106","Thiet ke giao dien nguoi dung",0,0}
   };
   createList(&dshp);
   for(int i=0;i<21;++i)
   {
      p=createNode(hp[i]);
      addTail(&dshp,p);
   }
   printf("\nDanh sach hoc phan: ");
   layDanhSachHocPhan(dshp);



   return 0;
}
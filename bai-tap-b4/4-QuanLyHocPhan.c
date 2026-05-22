

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
   int stt;
   char mahp[10];
   char tenhp[30];
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
HocPhan* nhapHocPhan()
{
   HocPhan *hp=(HocPhan*)malloc(sizeof(HocPhan));
   printf("\nNhap stt: ");
   scanf("%d",&hp->stt);getchar();
   printf("\nNhap ma hp: ");
   fgets(hp->mahp,sizeof(hp->mahp),stdin);
   hp->mahp[strcspn(hp->mahp, "\n")] = '\0';
   printf("\nNhap ten hp: ");
   fgets(hp->tenhp,sizeof(hp->tenhp),stdin);
   hp->tenhp[strcspn(hp->tenhp, "\n")] = '\0';
   printf("\nNhap so tc: ");
   scanf("%d",&hp->sotc);
   printf("\nNhap diem hp: ");
   scanf("%f",&hp->sotc);
   return hp;
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
      printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem trung binh:%.2f",p->info.stt,
      p->info.mahp,p->info.tenhp,p->info.sotc,p->info.diemhp);
      p=p->next;
   }
}
void sapXepDanhSachTheoDiemTB(List l)
{
   Node *i,*j;HocPhan temp;
   for(i=l.head;i!=l.tail;i=i->next)
      for(j=i->next;j!=NULL;j=j->next)
         if(i->info.diemhp>j->info.diemhp)
         {
            temp=i->info;
            i->info=j->info;
            j->info=temp;
         }
}
void sapXepDanhSachTheoSTT(List l)
{
   Node *i,*j;HocPhan temp;
   for(i=l.head;i!=l.tail;i=i->next)
      for(j=i->next;j!=NULL;j=j->next)
         if(i->info.stt>j->info.stt)
         {
            temp=i->info;
            i->info=j->info;
            j->info=temp;
         }
}
Node* timHocPhanTheoMa(List l,char* mahp)
{
   Node *p=l.head;
   while(p!=NULL&&strcmp(p->info.mahp,mahp)!=0)
      p=p->next;
   return p;
}
void themHocPhanTangDanTheoSTT(List *l,Node *new)
{
   Node *p=l->head,*q=NULL;
   while(p!=NULL&&p->info.stt<new->info.stt)
   {
      q=p;p=p->next;
   }
   if(q==NULL)
   {
      if(l->head==NULL)
         l->tail=NULL;
      addHead(l,new);
   }
   else 
   {
      if(l->tail==NULL)
         l->tail=new;
      new->next=p;
      q->next=new;
   }
}
void xoaHocPhanTheoMa(List *l,char *mahp)
{
   Node *p=l->head,*q=NULL;
   while(p!=NULL&&(strcmp(p->info.mahp,mahp)!=0))
   {
      q=p;p=p->next;
   }
   if(p!=NULL)
   {
      if(q==NULL)
      {
         if(l->head==NULL)
            l->tail=NULL;
         l->head=p->next;
         free(p);
      }
      else
      {
         if(l->tail==NULL)
            l->tail=q;
         q->next=p->next;
         free(p);
      }
   }
}
void xoaHetDanhSach(List *l)
{
   Node *p;
   while(l->head!=NULL)
   {
      p=l->head;
      p=p->next;
      free(p);
   }l->tail=NULL;
}


/*int stt;
   char mahp[10];
   char tenhp[30];
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
      {11,"MA006","Giai tich",4,5.7},
      {12,"SS006","Phap luat dai cuong",2,6},
      {13,"IT003","Cau truc du lieu va giai thuat",4,7},
      {14,"ENG02","Anh van 2",4,7.5},
      {5,"SS004","Ky nang nghe ngiep",2,7.4},
      {6,"MA004","Cau truc roi rac",4,8.1},
      {7,"IT002","Lap trinh huong doi tuong",4,7.6},
      {8,"IT012","To chuc va cau truc may tinh",4,6.2},
      {15,"IT004","Co so du lieu",4,7.3},
      {16,"ENG03","Anh van 3",4,6},
      {17,"IT005","Nhap mon lap mang may tinh",4,5.8},
      {18,"MA005","Xac suat thong ke",3,8.4},
      {9,"IE103","Quan ly thong tin",4,7.3},
      {10,"SS007","Triet hoc Mac-Lenin",3,6.8},
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
   printf("\nDanh sach sau khi sap xep: ");
   sapXepDanhSachTheoSTT(dshp);
   layDanhSachHocPhan(dshp);
   char *ma=(char*)malloc(10*sizeof(char));
   printf("\nNhap ma hoc phan can tim: ");
   scanf("%s",ma);
   Node *x;//luu hoc phan tim dx
   x=timHocPhanTheoMa(dshp,ma);
   if(x!=NULL)
      {
         printf("\nTim thay hoc phan co ma %s",ma);
         printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem trung binh:%.2f",x->info.stt,
               x->info.mahp,x->info.tenhp,x->info.sotc,x->info.diemhp);
      }
   else printf("\nKhong tim thay hoc phan co ma %s",ma);
   HocPhan *newHocPhan;Node *newNode;
   newHocPhan=nhapHocPhan();
   newNode=createNode(*newHocPhan);
   themHocPhanTangDanTheoSTT(&dshp,newNode);
   printf("\nDanh sach hoc phan: ");
   layDanhSachHocPhan(dshp);
   char *maXoa=(char*)malloc(10*sizeof(char));
   printf("\nNhap ma hoc phan can xoa: ");
   scanf("%s",maXoa);
   xoaHocPhanTheoMa(&dshp,maXoa);
   printf("\nDanh sach hoc phan sau khi xoa %s:",maXoa);
   layDanhSachHocPhan(dshp);
   printf("\nDanh sach sau khi xoa sach:");
   xoaHetDanhSach(&dshp);
   layDanhSachHocPhan(dshp);
   return 0;
}
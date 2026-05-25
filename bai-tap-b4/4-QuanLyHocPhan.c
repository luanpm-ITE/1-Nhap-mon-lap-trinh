

/*Chương trình quản lý học phần được cài đặt vào
danh sách liên kết đơn, triển khai dưới dạng danh 
mục chọn chức năng.Hoàn thiện các chức năng CRUD.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
   return p;
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
   scanf("%f",&hp->diemhp);
   return hp;
}
void xuatHocPhan(HocPhan hp) {
    printf("STT:%d | Ma:%s | Ten:%s | So TC:%d | Diem TB:%.2f\n",
           hp.stt,hp.mahp,hp.tenhp,hp.sotc,hp.diemhp);       
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
void layToanBoDanhSach(List l)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem trung binh:%.2f",p->info.stt,
      p->info.mahp,p->info.tenhp,p->info.sotc,p->info.diemhp);
      p=p->next;
   }
}
Node* layHocPhanTheoMa(List l,char* mahp)
{
   Node *p=l.head;
   while(p!=NULL&&strcmp(p->info.mahp,mahp)!=0)
      p=p->next;
   return p;
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
Node* suaDiemTBHocPhanTheoMa(List l,char *mahp)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      if(strcmp(p->info.mahp,mahp)==0)
      {
         printf("\nNhap vao diem tb moi: ");
         scanf("%f",&p->info.diemhp);
         return p;
      }
      p=p->next;
   }return NULL;
}
int lietKeHocPhan4TCVaDiemTrenTB(List l)
{
   int count=0,sotc=4;float diemtb=5.0;
   Node *p=l.head;
   printf("\nDanh sach hoc phan 4 tin chi & diem tb > %.2f:\n",diemtb);
   while(p!=NULL)
   {
      if(p->info.diemhp>diemtb&&p->info.sotc==sotc)
      {
         ++count;
         xuatHocPhan(p->info);
      }
      p=p->next;
   }
   return count;
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
void xoaToanBoDanhSach(List *l)
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
   List dshp;Node *p;int choice;
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
   for(int i=0;i<26;++i)
   {
      p=createNode(hp[i]);
      addTail(&dshp,p);
   }
   tt:
      printf("\n===========================");
      printf("\n          MENU             ");
      printf("\n===========================");
      printf("\n 1. Xuat danh sach hoc phan.");
      printf("\n 2. Sap xep danh sach hoc phan.");
      printf("\n 3. Xuat hoc phan theo ma.");
      printf("\n 4. Them hoc phan vao danh sach.");
      printf("\n 5. Xoa hoc phan theo ma.");
      printf("\n 6. Huy toan bo danh sach.");
      printf("\n 7. Sua diem hoc phan.");
      printf("\n 8. Liet ke cac hoc phan 4 tin chi va tren 5.0.");
      printf("\nChon: ");scanf("%d",&choice);
   switch (choice)
   {
   case  1:
      printf("\n===========================");
      printf("\n    DANH SACH HOC PHAN     ");
      printf("\n===========================");
      layToanBoDanhSach(dshp);
      break;
   case  2:
      printf("\n===========================");
      printf("\nDANH SACH HOC PHAN SAU KHI SAP XEP");
      printf("\n===========================");
      sapXepDanhSachTheoSTT(dshp);
      layToanBoDanhSach(dshp);
      break;
   case  3:
      char *ma=(char*)malloc(10*sizeof(char));
      printf("\nNhap ma hoc phan can tim: ");
      scanf("%s",ma);
      Node *x;//luu hoc phan tim dx
      x=layHocPhanTheoMa(dshp,ma);
      if(x!=NULL)
         {
            printf("\nTim thay hoc phan co ma %s",ma);
            printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem trung binh:%.2f",x->info.stt,
                  x->info.mahp,x->info.tenhp,x->info.sotc,x->info.diemhp);
         }
      else printf("\nKhong tim thay hoc phan co ma %s",ma);
      break;
   case  4:
      HocPhan *newHocPhan;Node *newNode;
      newHocPhan=nhapHocPhan();
      newNode=createNode(*newHocPhan);
      themHocPhanTangDanTheoSTT(&dshp,newNode);
      printf("\n===========================");
      printf("\n    DANH SACH HOC PHAN     ");
      printf("\n===========================");
      layToanBoDanhSach(dshp);
      break;
   case  5:
      char *maXoa=(char*)malloc(10*sizeof(char));
      printf("\nNhap ma hoc phan can xoa: ");
      scanf("%s",maXoa);
      xoaHocPhanTheoMa(&dshp,maXoa);
      printf("\nDanh sach hoc phan sau khi xoa %s:",maXoa);
      layToanBoDanhSach(dshp);
      break;
   case 6:
      printf("\nDanh sach sau khi xoa sach:");
      xoaToanBoDanhSach(&dshp);
      layToanBoDanhSach(dshp);
      break;
   case 7:
      char maSua[10];
      printf("\nNhap ma hoc phan can sua: ");
      scanf("%s",maSua);
      Node *y;
      y=suaDiemTBHocPhanTheoMa(dshp,maSua);
      printf("\nHoc phan sau khi dieu chinh diem tb:");
      printf("\nSTT:%d|Ma:%s|Ten:%s|So tin chi:%d|Diem trung binh:%.2f",y->info.stt,
                  y->info.mahp,y->info.tenhp,y->info.sotc,y->info.diemhp);
      break;
   case 8:
      int count=lietKeHocPhan4TCVaDiemTrenTB(dshp);
      printf("\tSo hoc phan 4 tin chi & diem tb tren 5: %d",count);
      break;
   default:printf("\nChon tu 1->8 thoi nhe!!!");
      break;
   }
   printf("\nCo tiep tuc khong?c/K? ");
   if(getch()=='c'||getch()=='C')goto tt;
   return 0;
}//xong nhe!!!
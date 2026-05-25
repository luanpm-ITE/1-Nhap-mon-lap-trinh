

/*Chương trình quản lý sinh vien được cài đặt vào
danh sách liên kết đơn, triển khai dưới dạng danh 
mục chọn chức năng.Hoàn thiện các chức năng CRUD.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Cấu trúc sinh viên
typedef struct
{
   char maSV[10];
   char ht[30];
   float diemtb;
}SinhVien;
//Cấu trúc nút lưu sinh viên
typedef struct tagNode
{
   SinhVien info;
   struct tagNode *next;
}Node;
//Cấu trúc list lưu nút
typedef struct
{
   Node *head,*tail;
}List;
//Hàm tạo list
void createList(List *l)
{
   l->head=NULL;l->tail=NULL;
}
//Hàm tạo nút lưu sinh viên 
Node* createNode(SinhVien sv)
{
   Node *p=(Node*)malloc(sizeof(Node));
   p->info=sv;
   p->next=NULL;return p;
}
//Hàm tạo sinh viên
SinhVien* createSV(char masv[],char ht[],float diemtb)
{
   SinhVien *sv=(SinhVien*)malloc(sizeof(SinhVien));
   strcpy(sv->maSV,masv);
   strcpy(sv->ht,ht);
   sv->diemtb=diemtb;
   return sv;
}
//Hàm ghi sinh viên
void xuatSV(SinhVien hp) {
    printf("Ma:%s | Ten:%s | Diem TB:%.2f\n",
           hp.maSV,hp.ht,hp.diemtb);       
}
//Hàm gán nút vào đầu list
void addHead(List *l,Node *p)
{
   if(l->head==NULL)
   {
      l->head=p;l->tail=p;
   }
   else
   {
      p->next=l->head; 
      l->head=p;
   }
}
//Hàm gán nút vào cuối list
void addTail(List *l,Node *p)
{
   if(l->head==NULL)
   {
      l->head=p;l->tail=p;
   }
   else
   {
      l->tail->next=p;
      l->tail=p;
   }
}
//Hàm lấy dssv
void hienThiDanhSachSV(List l)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      printf("\nMa sv: %s\tHo ten: %s\tDiem tb: %.2f"
         ,p->info.maSV,p->info.ht,p->info.diemtb);
      p=p->next;
   }

}
//Hàm lấy sv theo mã sv
Node* hienThiSVTheoMa(List l,char* mssv)
{
   Node *p=l.head;
   while(p!=NULL&&strcmp(p->info.maSV,mssv)!=0)
      p=p->next;
   return p;
}
//Hàm sort sv theo điểm tb
void sapXepSVTheoDiemTB(List l)
{
   Node *i,*j;SinhVien temp;
   for(i=l.head;i!=l.tail;i=i->next)
      for(j=i->next;j!=NULL;j=j->next)
         if(i->info.diemtb>j->info.diemtb)
            {
               temp=i->info;
               i->info=j->info;
               j->info=temp;
            }
}
//Hàm sort sv theo điểm ten
void sapXepSVTheoTen(List l)
{
   Node *i,*j;SinhVien temp;
   for(i=l.head;i!=l.tail;i=i->next)
      for(j=i->next;j!=NULL;j=j->next)
         if(strcmp(i->info.ht,j->info.ht)>0)
            {
               temp=i->info;
               i->info=j->info;
               j->info=temp;
            }
}
//Hàm sort sv theo điểm ma
void sapXepSVTheoMa(List l)
{
   Node *i,*j;SinhVien temp;
   for(i=l.head;i!=l.tail;i=i->next)
      for(j=i->next;j!=NULL;j=j->next)
         if(strcmp(i->info.maSV,j->info.maSV)>0)
            {
               temp=i->info;
               i->info=j->info;
               j->info=temp;
            }
}
//Hàm thêm nút vào list 
void insertSortedList(List *l,Node *new)
{
   Node *p=l->head,*q=NULL;
   while((p!=NULL)&&(strcmp(p->info.maSV,new->info.maSV)<0))
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
//Hàm sửa điểm tb theo mã sv
Node* suaDiemTBTheoMa(List l,char *masv)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      if(strcmp(p->info.maSV,masv)==0)
      {
         printf("\nNhap vao diem tb moi: ");
         scanf("%f",&p->info.diemtb);
         return p;
      }
      p=p->next;
   }return NULL;
}
//Hàm xóa 1 sinh viên theo mã
void xoaSVTheoMa(List *l,char *mssv)
{
   Node  *p=l->head,*q=NULL;
   while((p!=NULL)&&(strcmp(p->info.maSV,mssv)!=0))
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
//Hàm xóa hết dssv
void xoaToanBoDanhSach(List *l)
{
   Node *p=l->head,*temp;
   while(p!=NULL)
   {
      temp=p;
      p=p->next;
      free(temp);
   } 
   l->head=NULL;
   l->tail=NULL;
}
//Hàm ghi dssv ra file .txt
void ghiDanhSachRaFile(List *l,char *tenFile)
{
   FILE *f=fopen(tenFile,"w");
   if(f!=NULL)
   {
      Node *p=l->head;
      while(p!=NULL)
      {
         fprintf(f,"%s\t%s\t%.2f\n",p->info.maSV,
            p->info.ht,p->info.diemtb);
         p=p->next;
      }
   }
   else printf("\nKhong mo duoc file %s",tenFile);
}
int main()
{
   List dssv;Node *p;
   createList(&dssv);
   SinhVien sv[]={{"SV001", "Nguyen Van A", 7.5},
        {"SV002", "Tran Thi B", 8.2},
        {"SV003", "Le Van C", 6.8},
        {"SV004", "Pham Thi D", 9.0},
        {"SV005", "Hoang Van E", 5.5},
        {"SV006", "Do Thi F", 7.0},
        {"SV007", "Nguyen Van G", 8.7},
        {"SV008", "Tran Thi H", 6.2},
        {"SV009", "Le Van I", 7.8},
        {"SV010", "Pham Thi K", 9.3}};
   for(int i=0;i<10;++i)
   {
      p=createNode(sv[i]);
      addTail(&dssv,p);
   }
   printf("\nDanh sach sinh vien: ");
   hienThiDanhSachSV(dssv);
   char ma[10]="SV011";
   Node *kq=hienThiSVTheoMa(dssv,ma);
   if(kq!=NULL)
   {
      printf("\nTim thay sv co ma: %s",ma);
      printf("\n\t%s | %s | %.2f",
         kq->info.maSV,kq->info.ht,kq->info.diemtb);
   }
   else printf("\nKhong tim thay sv co ma: %s",ma);
   printf("\nDanh sach sinh vien sau khi sap xep tang theo diem tb: ");
   sapXepSVTheoDiemTB(dssv);
   hienThiDanhSachSV(dssv);
   SinhVien new={"SV004","Nguyen Van L",3.5};
   Node *q=createNode(new);
   insertSortedList(&dssv,q);
   printf("\nDanh sach sau khi chen: ");
   hienThiDanhSachSV(dssv);
   xoaSVTheoMa(&dssv,"SV004");
   printf("\nDanh sach sau khi xoa SV004:");
   hienThiDanhSachSV(dssv);
   ghiDanhSachRaFile(&dssv,"sv.txt");
   printf("\nDanh sach sau khi huy:");
   xoaToanBoDanhSach(&dssv);
   hienThiDanhSachSV(dssv);
   //xong nhe!
   return 0;
}
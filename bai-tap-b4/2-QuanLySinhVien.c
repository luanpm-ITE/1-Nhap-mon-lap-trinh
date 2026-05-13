

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
   char maSV[10];
   char ht[30];
   float diemtb;
}SinhVien;
typedef struct tagNode
{
   SinhVien info;
   struct tagNode *next;
}Node;
typedef struct
{
   Node *head,*tail;
}List;
void createList(List *l)
{
   l->head=NULL;l->tail=NULL;
}
Node* createNode(SinhVien sv)
{
   Node *p=(Node*)malloc(sizeof(Node));
   p->info=sv;
   p->next=NULL;return p;
}
SinhVien* createSV(char masv[],char ht[],float diemtb)
{
   SinhVien *sv=(SinhVien*)malloc(sizeof(SinhVien));
   strcpy(sv->maSV,masv);
   strcpy(sv->ht,ht);
   sv->diemtb=diemtb;
   return sv;
}
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
void loopList(List l)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      printf("\nMa sv: %s\tHo ten: %s\tDiem tb: %.2f"
         ,p->info.maSV,p->info.ht,p->info.diemtb);
      p=p->next;
   }

}
Node* timSVTheoMa(List l,char* mssv)
{
   Node *p=l.head;
   while(p!=NULL&&strcmp(p->info.maSV,mssv)!=0)
      p=p->next;
   return p;
}
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
void destroyList(List *l)
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
   List l;Node *p;
   createList(&l);
   SinhVien sv[]={{"SV002","Nguyen Van A",5.5},
                  {"SV000","Tran Thi B",3.5},
                  {"SV006","Le Van C",9.5}};
   for(int i=0;i<3;++i)
   {
      p=createNode(sv[i]);
      addTail(&l,p);
   }
   printf("\nDanh sach sinh vien: ");
   loopList(l);
   char ma[10]="SV002";
   Node *kq=timSVTheoMa(l,ma);
   if(kq!=NULL)
   {
      printf("\nTim thay sv co ma: %s",ma);
      printf("\n\t%s | %s | %.2f",
         kq->info.maSV,kq->info.ht,kq->info.diemtb);
   }
   else printf("\nKhong tim thay sv co ma: %s",ma);
   printf("\nDanh sach sinh vien sau khi sap xep tang theo diem tb: ");
   sapXepSVTheoDiemTB(l);
   loopList(l);
   SinhVien new={"SV004","Nguyen Van L",3.5};
   Node *q=createNode(new);
   insertSortedList(&l,q);
   printf("\nDanh sach sau khi chen: ");
   loopList(l);
   xoaSVTheoMa(&l,"SV004");
   printf("\nDanh sach sau khi xoa SV004:");
   loopList(l);
   ghiDanhSachRaFile(&l,"sv.txt");
   printf("\nDanh sach sau khi huy:");
   destroyList(&l);
   //xong nhe!
   return 0;
}
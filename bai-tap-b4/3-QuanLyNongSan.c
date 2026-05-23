

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
   char masp[10];
   char tensp[30];
   int sl;
   float dongia;
}NongSan;
typedef struct tagNode
{
   NongSan info;
   struct tagNode *next;
}Node;
typedef struct
{
   Node *head,*tail;
}Stack;
void createStack(Stack *s)
{
   s->head=NULL;
   s->tail=NULL;
}
Node* createNode(NongSan ns)
{
   Node *p=(Node*)malloc(sizeof(Node));
   p->info=ns;
   p->next=NULL;return p;
}
void push(Stack *s,Node *p)
{
   if(s->head==NULL)
   {
      s->head=p;
      s->tail=p;
   }
   else
   {
      p->next=s->head;
      s->head=p;
   }
}
int pop(Stack *s,NongSan ns)
{
   Node *p;
   if(s->head!=NULL)
   {
      if(s->head==NULL)
         s->tail=NULL;
      p=s->head;
      s->head=s->head->next;
      ns=p->info;
      free(p);
      return 1;
   }
   return 0;
}
void layDanhSachNongSan(Stack s)
{
   Node *p=s.head;
   while(p!=NULL)
   {
      printf("\nMa sp: %s\tTen sp: %s\tSo luong: %d\tDon gia: %.4f"
         ,p->info.masp,p->info.tensp,p->info.sl,p->info.dongia);
      p=p->next;
   }
}
void sapXepTheoSoLuong(Stack s)
{
   Node *i,*j,*min;NongSan temp;
   for(i=s.head;i!=s.tail;i=i->next)
   {
      min=i;
      for(j=i->next;j!=NULL;j=j->next)
      {
         if(min->info.sl>j->info.sl)
            min=j;
      }
      temp=min->info;
      min->info=i->info;
      i->info=temp;
   }
}
Node* timNongSanTheoTen(Stack s,char *tensp)
{
   Node *p=s.head;
   while((p!=NULL)&&(strcmp(p->info.tensp,tensp)!=0))
      p=p->next;
   return p;
}
void insertSortedStack(Stack *s,Node *new)
{
   Node *p=s->head,*q=NULL;
   while(p!=NULL&&strcmp(p->info.masp,new->info.masp)>0)
   {
      q=p;p=p->next;
   }
   if(q==NULL)
   {
      if(s->head==NULL)
         s->tail=NULL;
      push(s,new);
   }
   else
   {
      if(s->tail==NULL)
         s->tail=new;
      new->next=p;
      q->next=new;
   }
}
void xoaNongSanTheoMa(Stack *s,char *masp)
{
   Node *p=s->head,*q=NULL;
   while(p!=NULL&&strcmp(p->info.masp,masp)!=0)
   {
      q=p;p=p->next;
   }
   if(p!=NULL)
   {
      if(q==NULL)
      {
         if(s->head==NULL)
            s->tail=NULL;  
         s->head=p->next;
         free(p);
      }
      else
      {
         if(s->tail==NULL)
            s->tail=q;
         q->next=p->next;
         free(p);
      }
   }
}
int main()
{
   Stack dsns;Node *p;
   createStack(&dsns);
   NongSan  ns[]=
   {
      {"SP001","Dua kho",100,3.000},
      {"SP002","Dua tuoi",55,5.000},
      {"SP003","Trung ga",300,3.000},
      {"SP004","Trung vit",200,3.500},
      {"SP005","Truong lon",150,4.000},
   };
   for(int i=0;i<5;++i)
   {
      p=createNode(ns[i]);
      push(&dsns,p);
   }
   printf("\nDanh sach san pham: ");
   layDanhSachNongSan(dsns);
   Node *kq=timNongSanTheoTen(dsns,"Dua tuoi");
   if(kq!=NULL)
   {
      printf("\nTim thay san pham:");
      printf("\n\t%s | %s | %d | %.4f",kq->info.masp,
         kq->info.tensp,kq->info.sl,kq->info.dongia);
   }
   else printf("\nTim khong thay san pham");
   NongSan new={"SP000","Xoai",50,30.000};
   Node *newNode=createNode(new);
   insertSortedStack(&dsns,newNode);
   printf("\nDanh sach sau khi them sp moi: ");
   layDanhSachNongSan(dsns);
   printf("\nDanh sach sau khi sap xep: ");
   sapXepTheoSoLuong(dsns);
   layDanhSachNongSan(dsns);
   xoaNongSanTheoMa(&dsns,"SP000");
   printf("\nDach sach sau khi xoa SP000: ");
   layDanhSachNongSan(dsns);
   //xong nhe
   return 0;
}
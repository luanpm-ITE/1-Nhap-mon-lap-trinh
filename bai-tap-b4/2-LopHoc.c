

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
int main()
{
   List l;Node *p;
   createList(&l);
   SinhVien sv[]={{"SV001","Nguyen Van A",5.5},
                  {"SV002","Tran Thi B",7.5},
                  {"SV003","Le Van C",9.5}};
   for(int i=0;i<3;++i)
   {
      p=createNode(sv[i]);
      addTail(&l,p);
   }
   printf("\nDanh sach sinh vien: ");
   loopList(l);

   return 0;
}
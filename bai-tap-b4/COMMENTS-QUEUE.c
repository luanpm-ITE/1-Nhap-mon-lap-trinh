

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_comments 5 
/*Chương trình quản lý user được cài đặt vào
hàng đợi, triển khai dưới dạng danh 
mục chọn chức năng.Hoàn thiện các chức năng CRUD.*/
typedef struct 
{
   int id;
   char name[30];
   char email[30];
   char body[50];
}comment;
typedef struct tagNode
{
   comment info;
   struct tagNode *next;
}node;
typedef struct 
{
   node *head,*tail;
}queue;
void createqueue(queue *s)
{
   s->head=NULL;
   s->tail=NULL;
}
node* createNode(comment commt)
{
   node *p=(node*)malloc(sizeof(node));
   p->info=commt;
   p->next=NULL;return p;
}
void push(queue *s,node *p)
{
   if(s->head==NULL)
   {
      s->head=p;
      s->tail=p;
   }
   else
   {
      s->tail->next=p;
      s->tail=p;
   }
}
int pop(queue *s,comment *remove)
{
   node *p=s->head;
   if(s->head!=NULL)
   {
      if(s->head==NULL)
         s->tail=NULL;
      s->head=s->head->next;
      *remove=p->info;
      free(p);
      return 1;
   }
   return 0;
}
void printfComment(comment commt)
{
   printf("\nID: %d",commt.id);
   printf("\nName: %s",commt.name);
   printf("\nEmail: %s",commt.email);
   printf("\nBody: %s\n",commt.body);
}
comment* createComment(int id,char *name,char *email,char *body)
{
   comment *p=(comment*)malloc(sizeof(comment));
   p->id=id;
   strcpy(p->name,name);
   strcpy(p->email,email);
   strcpy(p->body,body);
   return p;
}
void getAllcomments(queue s)
{
   node *p=s.head;
   while(p!=NULL)
   {
      printfComment(p->info);
      p=p->next;
   }
}
node* getCommentByID(queue s,int id)
{
   node *p=s.head;
   while(p!=NULL&&p->info.id!=id)
      p=p->next;
   return p;
}
node* updateNameCommentByID(queue s,int id)
{
   node *p;
   char temp[50];
   while(p!=NULL&&p->info.id!=id);
      s.head=s.head->next;
   printf("\nEnter new name: ");
   scanf("%s",temp);
   strcpy(p->info.name,temp);
   return p;
}
int main()
{
   queue s;node *p;
   int n=5,id;
   comment comments[MAX_comments]= 
   {
      {1, "Alice", "alice@example.com", 
         "This is the first comment."},
      {2, "Bob", "bob@example.com", 
         "I totally agree with this post."},
      {3, "Charlie", "charlie@example.com", 
         "Interesting perspective."},
      {4, "Diana", "diana@example.com", 
         "Could you explain more details?"},
      {5, "Eve", "eve@example.com", 
         "Great work, keep it up!"}
   };
   createqueue(&s);
   for(int i=0;i<n;++i)
   {
      p=createNode(comments[i]);
      push(&s,p);
   }
   //Successful testing
   return 0;
}

/*"id": 1,
    "name": "id labore ex et quam laborum",
    "email": "Eliseo@gardner.biz",
    "body": "laudantium enim quasi  */
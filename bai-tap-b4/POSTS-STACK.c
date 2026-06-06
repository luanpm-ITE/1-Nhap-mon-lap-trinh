

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_POSTs 5 
/*Chương trình quản lý user được cài đặt vào
ngăn xếp, triển khai dưới dạng danh 
mục chọn chức năng.Hoàn thiện các chức năng CRUD.*/
typedef struct 
{
   int id;
   char title[50];
   char body[50];
}post;
typedef struct tagNode
{
   post info;
   struct tagNode *next;
}node;
typedef struct 
{
   node *head,*tail;
}stack;
void createStack(stack *s)
{
   s->head=NULL;
   s->tail=NULL;
}
node* createNode(post pos)
{
   node *p=(node*)malloc(sizeof(node));
   p->info=pos;
   p->next=NULL;return p;
}
void push(stack *s,node *p)
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
int pop(stack *s,post *remove)
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
void printfPost(post pos)
{
   printf("\nID: %d",pos.id);
   printf("\nTitle: %s",pos.title);
   printf("\nBody: %s\n",pos.body);
}
post* createPost(int id,char *title,char *body)
{
   post *p=(post*)malloc(sizeof(post));
   p->id=id;
   strcpy(p->title,title);
   strcpy(p->body,body);
   return p;
}
void getAllPosts(stack s)
{
   node *p=s.head;
   while(p!=NULL)
   {
      printfPost(p->info);
      p=p->next;
   }
}
node* getPostByID(stack s,int id)
{
   node *p=s.head;
   while(p!=NULL&&p->info.id!=id)
      p=p->next;
   return p;
}
node* updateTitlePostByID(stack s,int id)
{
   node *p;
   char temp[50];
   while(p!=NULL&&p->info.id!=id);
      s.head=s.head->next;
   printf("\nEnter new title: ");
   scanf("%s",temp);
   strcpy(p->info.title,temp);
   return p;
}
int main()
{
   stack s;node *p;
   int n=5,id;
   post posts[MAX_POSTs]= 
   {
      {1,
         "sunt aut facere repellat provident",
         "autem sunt rem eveniet architecto"},
      {2,
         "qui est esse",
         "neque nisi nulla"},
      {3,
         "repellat qui ipsa sit aut",
         "velit aut"},
      {4,
         "eum et est occaecati",
         "nquis sunt voluptatem rerum illo velit"},
      {5,
         "nesciunt quas odio",
         "aut tenetur dolor neque"}
   };
   createStack(&s);
   for(int i=0;i<n;++i)
   {
      p=createNode(posts[i]);
      push(&s,p);
   }
   //Successful testing
   return 0;
}

/*"userId": 1,
    "id": 1,
    "title": "sunt aut facere repellat provident occaecati excepturi optio reprehenderit",
    "body": "quia et suscipit\*/
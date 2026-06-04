

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
/*Chương trình quản lý user được cài đặt vào
mảng, triển khai dưới dạng danh mục chọn 
chức năng.Hoàn thiện các chức năng CRUD.*/
#define MAX_TODOs 10
int n=5;
typedef struct 
{
   int id;
   char title[100];
   bool completed;
}Todo;
Todo* createToDo(int id,char title[],int completed)
{
   Todo *t=(Todo*)malloc(sizeof(Todo));
   t->id=id;
   strcpy(t->title,title);
   t->completed=completed;
   return t;
}
void printfToDo(Todo t)
{
   printf("\nId: %d",t.id);
   printf("\nTitle: %s",t.title);
   printf("\nCompleted: %d\n",t.completed);
}
void getAllToDo(Todo t[],int n)
{
   for(int i=0;i<n;++i)
      printfToDo(t[i]);
}
Todo* getToDoByID(Todo t[],int n,int id)
{
   int i=0;
   while(i<n&&t[i].id!=id)
      ++i;
   if(i==n) return NULL;
   else return &t[i];
}
Todo* updateCompletedToDoByID(Todo t[],int n,int id)
{
   int i=0;
   while(i<n&&t[i].id!=id)
      ++i;
   if(i==n) return NULL;
   else
   {  int c;
      printf("\nNhap completed(0|1): ");
      scanf("%d",&c);
      t[i].completed=(c==1);
   } return &t[i];
}
void insertSortedToDoByID(Todo t[],int *n,Todo new)
{
   int i=*n-1;
   //Dịch các phần tử có id lớn hơn sang phải
   while(i>=0&&t[i].id>new.id) {
      t[i+1]=t[i];
      --i;
   }
   //Chèn phần tử mới vào đúng vị trí
   t[i+1]=new;
   ++(*n);//tăng số lượng phần tử
}
void deleteTodoByID(Todo t[],int *n,int id) {
   for(int i=0;i<*n;++i) 
   {
      if (t[i].id==id) 
      {
         // dịch các phần tử sau lên
         for (int j=i;j<*n-1;++j) 
         {
            t[j]=t[j+1];
         }
         --(*n);//giảm số lượng phần tử
      }
   }
}
void clearTodos(Todo t[],int *n)
{
   *n=0;
}
int main()
{
   int id,choice;
   Todo *t;
   Todo todos[MAX_TODOs]= 
   {
        {1, "delectus aut autem", false},
        {2, "quis ut nam facilis et officia qui", false},
        {3, "fugiat veniam minus", false},
        {4, "et porro tempora", true},
        {6, "laboriosam mollitia et", false}
   };
   tt:
         printf("\n===========================");
         printf("\n       MENU-TODO-CRUD      ");
         printf("\n===========================");
         printf("\n 1. GET ALL TODOs.");
         printf("\n 2. GET TODOS BY ID.");
         printf("\n 3. POST TODOS BY ID.");
         printf("\n 4. UPDATE TODOS BY ID.");
         printf("\n 5. DELETE TODOS BY ID.");
         printf("\n 6. CLEAR TODOS.");
         printf("\nChoice: ");scanf("%d",&choice);
   switch (choice)
   {
   case 1:
      getAllToDo(todos,5);
      break;
   case 2:
      printf("\nNhap id: ");
      scanf("%d",&id);
      t=getToDoByID(todos,n,id);
      if(t)
         {
            printf("\nTim thay TODO ID %d",id);
            printfToDo(*t);
         }
      else printf("\nKhong tim thay TODO ID %d",id);
      break;
   case 3:
      Todo *newTodo;
      newTodo=createToDo(5,"lucky boy",true);
      insertSortedToDoByID(todos,&n,*newTodo);
      printf("\nDanh sach Todos sau khi them ID: %d:",newTodo->id);
      getAllToDo(todos,n);
      break;
   case 4:
      printf("\nNhap id: ");
      scanf("%d",&id);
      t=updateCompletedToDoByID(todos,n,id);
      if(t)
         {
            printf("\nTim thay TODO ID %d",id);
            printfToDo(*t);
         }
      else printf("\nKhong tim thay TODO ID %d",id);
      break;
   case 5:
      printf("\nNhap id: ");
      scanf("%d",&id);
      deleteTodoByID(todos,&n,id);
      printf("\nDanh sach Todos sau khi xoa ID: %d:",id);
      getAllToDo(todos,n);
      break;
   case 6:
      clearTodos(todos,&n);
      printf("\nDanh sach Todos sau khi xoa sach:");
      getAllToDo(todos,n);
      break;
   default:printf("\nChon tu 1->6 thoi!!!");
      break;
   }
   printf("\nDo you want continue?y/N? ");
   if(getch()=='y'||getch()=='Y')goto tt;
   return 0;
}

// {
//     "userId": 1,
//     "id": 1,
//     "title": "delectus aut autem",
//     "completed": false
//   },
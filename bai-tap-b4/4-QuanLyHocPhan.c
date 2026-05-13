

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
   float th,qt,gk,ck;
}Diem;
typedef struct tagNode
{
   int stt;
   char mamh[10];
   char tenmh[30];
   int sotc;
   Diem diem;
   float diemhp;
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
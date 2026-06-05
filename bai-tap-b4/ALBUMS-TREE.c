

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_ALBUM 10
typedef struct 
{
   int id;
   char title[50];
   char url[50];
   char thumbnailUrl[50];
}Album;
typedef struct tagNode
{
   Album key;
   struct tagNode *left,*right;
}TNode;
typedef TNode *TREE;
void createTree(TREE *t)
{
   *t=NULL;
}
TNode* createTNode(Album al)
{
   TNode *p=(TNode*)malloc(sizeof(TNode));
   p->key=al;
   p->left=NULL;
   p->right=NULL;
   return p;
}
Album* scanfAlbum()
{
   Album *al=(Album*)malloc(sizeof(Album));
   printf("\nNhap thong tin Album:");
   printf("\nEnter id: ");
   scanf("%d",&al->id);
   getchar();

   printf("nEnter title: ");
   fgets(al->title,sizeof(al->title),stdin);
   al->title[strcspn(al->title,"\n")]='\0';

   printf("nEnter url: ");
   fgets(al->url,sizeof(al->url),stdin);
   al->url[strcspn(al->url,"\n")]='\0';

   printf("nEnter thumbnailUrl: ");
   fgets(al->thumbnailUrl,sizeof(al->thumbnailUrl),stdin);
   al->thumbnailUrl[strcspn(al->thumbnailUrl,"\n")]='\0';
   
   return al;
}
Album* createAlbum(int id,char *title,char *url,char *thumn)
{
   Album *al=(Album*)malloc(sizeof(Album));
   al->id=id;
   strcpy(al->title,title);
   strcpy(al->url,url);
   strcpy(al->thumbnailUrl,thumn);
   return al;
}
void printfAlbum(Album al)
{
   printf("\nID: %d",al.id);
   printf("\nTitle: %s",al.title);
   printf("\nUrl: %s",al.url);
   printf("\nThumbnailUrl: %s\n",al.thumbnailUrl);
}
TNode* insertTNode(TREE *t,TNode *p)
{
   if(*t!=NULL)
   {
      if((*t)->key.id==p->key.id) 
      {
         free(p);
         return NULL;
      }
      else 
      {
         if((*t)->key.id>p->key.id)
            return insertTNode(&(*t)->left,p);
         else return insertTNode(&(*t)->right,p);
      }
      
   }
   *t=p;
   return *t;
}
void LRN(TREE t)
{
   if(t!=NULL)
   {
      LRN(t->left);
      printfAlbum(t->key);
      LRN(t->right);
   }
}
TNode* searchAlbumByID(TREE t,int id)
{
   if(t==NULL) return NULL;
   if(t->key.id==id) return t;
   if(t->key.id>id) return searchAlbumByID(t->left,id);
   return searchAlbumByID(t->right,id);
}
TNode* updateTitleAlbumByID(TREE t,int id)
{
   if(t==NULL) return NULL;
   if(t->key.id==id)
   {
      printf("\nEnter new title: ");
      scanf("%s",&t->key.title);
      return t;
   }
   if(t->key.id>id) return updateTitleAlbumByID(t->left,id);
   return updateTitleAlbumByID(t->right,id);
}
TNode* findMin(TNode* t) {
   while(t->left!=NULL) 
      t=t->left;
   return t;
}
void deleteAlbumByID(TREE *t,int id) 
{
   if(*t==NULL) return;
   if(id<(*t)->key.id) 
      deleteAlbumByID(&(*t)->left,id);
   else if(id>(*t)->key.id) 
      deleteAlbumByID(&(*t)->right,id);
   else 
   {
      // tìm thấy node cần xóa
      if((*t)->left==NULL&&(*t)->right==NULL) 
      {
         free(*t);
         *t=NULL;
      }
      else if((*t)->left==NULL) 
      {
         TNode* temp=(*t)->right;
         free(*t);
         *t=temp;
      }
      else if((*t)->right==NULL) 
      {
         TNode* temp=(*t)->left;
         free(*t);
         *t=temp;
      }
      else
      {
         // có 2 con
         TNode* temp=findMin((*t)->right);
         (*t)->key=temp->key;
         deleteAlbumByID(&(*t)->right, temp->key.id);
      }
   }
}
void destroyTree(TREE *t) 
{
   if (*t == NULL) return;
   destroyTree(&(*t)->left);
   destroyTree(&(*t)->right);
   free(*t);
   *t = NULL; 
}
TNode* postAlbum(TREE *t) 
{
   Album *al=createAlbum(6,"kidbuu","NULL","NULL");   
   TNode *p=createTNode(*al);
   free(al);                   
   return insertTNode(t,p);    
}
int main()
{
   //printf("HelloWorld!");
   int n=5,id,choice;
   Album albums[MAX_ALBUM] = 
      {
      {1, "accusamus beatae ad facilis cum similique",
         "https://via.placeholder.com/600/92c952",
         "https://via.placeholder.com/150/92c952"},
      {2, "reprehenderit est deserunt velit ipsam",
         "https://via.placeholder.com/600/771796",
         "https://via.placeholder.com/150/771796"},
      {3, "officia porro iure quia iusto qui ipsa ut modi",
         "https://via.placeholder.com/600/24f355",
         "https://via.placeholder.com/150/24f355"},
      {4, "culpa odio esse rerum omnis laboriosam",
         "https://via.placeholder.com/600/d32776",
         "https://via.placeholder.com/150/d32776"},
      {5, "natus nisi omnis corporis facere",
         "https://via.placeholder.com/600/f66b97",
         "https://via.placeholder.com/150/f66b97"}
      };
   TREE t;TNode *p;TREE tNew;
   createTree(&t);
   for(int i=0;i<n;++i)
   {
      p=createTNode(albums[i]);
      insertTNode(&t,p);
   }
   tt:
         printf("\n===========================");
         printf("\n       MENU-ALBUM-CRUD      ");
         printf("\n===========================");
         printf("\n 1. GET ALL ALBUM.");
         printf("\n 2. GET ALBUM BY ID.");
         printf("\n 3. POST ALBUM BY ID.");
         printf("\n 4. UPDATE ALBUM BY ID.");
         printf("\n 5. DELETE ALBUM BY ID.");
         printf("\n 6. DESTROY ALBUM.");
         printf("\nChoice: ");scanf("%d",&choice);
   switch (choice)
   {
   case 1:
      printf("\nMY ALBUM.");
      LRN(t);
      break;
   case 2:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      tNew=searchAlbumByID(t,id);
      if(tNew!=NULL)
      {
         printf("\nResult: %d",id);
         printfAlbum(tNew->key);
      }
      else printf("\nNot fount");
      break;
   case 3:
      tNew=postAlbum(&t);
      if(tNew==NULL) 
         printf("\nAlbum with this ID already exists!");
      else
      {
         printf("\nAlbum added successfully:");
         printfAlbum(tNew->key);
      } 
      break;
   case 4:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      tNew=updateTitleAlbumByID(t,id);
      printf("\nAlbum ID %d after updated:",id);
      printfAlbum(tNew->key);
      break;
   case 5:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      deleteAlbumByID(&t,id);
      printf("\nAlbum after delete:");
      LRN(t);
      break;
   case 6:
      destroyTree(&t);
      printf("\nTree destroyed. All albums deleted.\n");
      break;
   default:printf("\nEnter 1->6!!!");
      break;
   }
   printf("\nDo you want continue?y/N? ");
   if(getch()=='y'||getch()=='Y')goto tt;
   return 0;
}


/*
    "albumId": 1,
    "id": 1,
    "title": "accusamus beatae ad facilis cum similique qui sunt",
    "url": "https://via.placeholder.com/600/92c952",
    "thumbnailUrl": "https://via.placeholder.com/150/92c952"*/
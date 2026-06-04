

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
   printf("\nNhap id: ");
   scanf("%d",&al->id);
   getchar();

   printf("Nhap title: ");
   fgets(al->title,sizeof(al->title),stdin);
   al->title[strcspn(al->title, "\n")] = '\0';

   printf("Nhap url: ");
   fgets(al->url,sizeof(al->url),stdin);
   al->url[strcspn(al->url, "\n")] = '\0';

   printf("Nhap thumbnailUrl: ");
   fgets(al->thumbnailUrl,sizeof(al->thumbnailUrl),stdin);
   al->thumbnailUrl[strcspn(al->thumbnailUrl, "\n")] = '\0';
   
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


int main()
{
   //printf("HelloWorld!");
   int n=5;int id;
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
   TREE t;TNode *p;
   createTree(&t);
   for(int i=0;i<n;++i)
   {
      p=createTNode(albums[i]);
      insertTNode(&t,p);
   }
   printf("\nMy ALbum: ");
   LRN(t);
   printf("\nNhap id: ");
   scanf("%d",&id);
   TREE tSearch;
   tSearch=searchAlbumByID(t,id);
   if(tSearch!=NULL)
   {
      printf("\nResult: %d",id);
      printfAlbum(tSearch->key);
   }
   else printf("\nKhong tim duoc Album ID %d",id);
   




   return 0;
}


/*
    "albumId": 1,
    "id": 1,
    "title": "accusamus beatae ad facilis cum similique qui sunt",
    "url": "https://via.placeholder.com/600/92c952",
    "thumbnailUrl": "https://via.placeholder.com/150/92c952"*/
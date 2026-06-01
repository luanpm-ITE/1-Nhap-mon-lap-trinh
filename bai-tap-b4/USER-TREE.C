

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*Chương trình quản lý user được cài đặt vào
cây nhị phân tìm kiếm, triển khai dưới dạng danh 
mục chọn chức năng.Hoàn thiện các chức năng CRUD.*/
typedef struct
{
   char lat[30];
   char lng[30];
}geo;
typedef struct 
{
   char street[30];
   char suite[30]; 
   char city[30];
   char zipcode[30];
   geo geo;
}address;
typedef struct 
{
   char name[30];
   char catchPhrase[50];
   char bs[50];
}company;
typedef struct 
{
   int id;
   char name[30];
   char username[30];
   char email[30];
   address address;
   char phone[30];
   char website[30];
   company company;
}user;
typedef struct tagNode
{
   user key;
   struct tagNode *left,*right;
}TNode;
typedef TNode *TREE;
void printfUser(user us)
{
   //printf("\n-----Thong tin user-----\n");
   printf("\nID: %d\nName: %s\nUsername: %s\nEmail: %s",us.id,
      us.name,us.username,us.email);
   printf("\nAddress: %s | %s | %s | %s",us.address.street,
      us.address.suite,us.address.city,us.address.zipcode);
   printf("\nGeo: lat=%s lng=%s",us.address.geo.lat,
      us.address.geo.lng);
   printf("\nPhone: %s | Website: %s",us.phone,us.website);
   printf("\nCompany name: %s",us.company.name);
   printf("\n\tCatchPhrase: %s",us.company.catchPhrase);
   printf("\n\tBS: %s",us.company.bs);
}
void createTree(TREE *t)
{
   *t=NULL;
}
TNode* createTNode(user us)
{
   TNode *p=(TNode*)malloc(sizeof(TNode));
   p->key=us;
   p->left=NULL;
   p->right=NULL;return p;
}
int insertTNode(TREE *t,TNode *p)
{
   if(*t!=NULL)
   {
      if((*t)->key.id==p->key.id) 
         return 0;//trùng khóa
      else
      {
         if(p->key.id<(*t)->key.id)
            return insertTNode(&(*t)->left,p);
         else 
            return insertTNode(&(*t)->right,p);
      }
   }
   *t=p;
   return 1;
}
void LRN(TREE t)
{
   if(t!=NULL)
   {
      LRN(t->left);
      printfUser(t->key);
      LRN(t->right);
   }
}
TNode* searchUserByID(TREE t,int id)
{
   while(t!=NULL)
   {
      if(t->key.id==id)
         return t;
      else
      {
         if(id<t->key.id)
            return searchUserByID(t->left,id);
         else return searchUserByID(t->right,id);
      }
   }return NULL;
}
TNode* updateUserNameByID(TREE t,int id)
{
   while(t!=NULL)
   {
      if(t->key.id==id)
      {
         printf("Nhap User Name: ");
         scanf("%s",t->key.name);
         return t;
      }
      else
      {
         if(id<t->key.id)
            return updateUserNameByID(t->left,id);
         else return updateUserNameByID(t->right,id);
      }
   }return NULL;
}
int main()
{
   TREE t;TNode *p;
   user users[] = {
        {
            1, "Leanne Graham", "Bret", "Sincere@april.biz",
            {"Kulas Light", "Apt. 556", "Gwenborough", "92998-3874", {"-37.3159", "81.1496"}},
            "1-770-736-8031 x56442", "hildegard.org",
            {"Romaguera-Crona", "Multi-layered client-server neural-net", "harness real-time e-markets"}
        },
        {
            2, "Ervin Howell", "Antonette", "Shanna@melissa.tv",
            {"Victor Plains", "Suite 879", "Wisokyburgh", "90566-7771", {"-43.9509", "-34.4618"}},
            "010-692-6593 x09125", "anastasia.net",
            {"Deckow-Crist", "Proactive didactic contingency", "synergize scalable supply-chains"}
        },
        {
            3, "Clementine Bauch", "Samantha", "Nathan@yesenia.net",
            {"Douglas Extension", "Suite 847", "McKenziehaven", "59590-4157", {"-68.6102", "-47.0653"}},
            "1-463-123-4447", "ramiro.info",
            {"Romaguera-Jacobson", "Face to face bifurcated interface", "e-enable strategic applications"}
        },
        {
            4, "Patricia Lebsack", "Karianne", "Julianne.OConner@kory.org",
            {"Hoeger Mall", "Apt. 692", "South Elvis", "53919-4257", {"29.4572", "-164.2990"}},
            "493-170-9623 x156", "kale.biz",
            {"Robel-Corkery", "Multi-tiered zero tolerance productivity", "transition cutting-edge web services"}
        },
        {
            5, "Chelsey Dietrich", "Kamren", "Lucio_Hettinger@annie.ca",
            {"Skiles Walks", "Suite 351", "Roscoeview", "33263", {"-31.8129", "62.5342"}},
            "(254)954-1289", "demarco.info",
            {"Keebler LLC", "User-centric fault-tolerant solution", "revolutionize end-to-end systems"}
        },
        {
            6, "Mrs. Dennis Schulist", "Leopoldo_Corkery", "Karley_Dach@jasper.info",
            {"Norberto Crossing", "Apt. 950", "South Christy", "23505-1337", {"-71.4197", "71.7478"}},
            "1-477-935-8478 x6430", "ola.org",
            {"Considine-Lockman", "Synchronised bottom-line interface", "e-enable innovative applications"}
        },
        {
            7, "Kurtis Weissnat", "Elwyn.Skiles", "Telly.Hoeger@billy.biz",
            {"Rex Trail", "Suite 280", "Howemouth", "58804-1099", {"24.8918", "21.8984"}},
            "210.067.6132", "elvis.io",
            {"Johns Group", "Configurable multimedia task-force", "generate enterprise e-tailers"}
        },
        {
            8, "Nicholas Runolfsdottir V", "Maxime_Nienow", "Sherwood@rosamond.me",
            {"Ellsworth Summit", "Suite 729", "Aliyaview", "45169", {"-14.3990", "-120.7677"}},
            "586.493.6943 x140", "jacynthe.com",
            {"Abernathy Group", "Implemented secondary concept", "e-enable extensible e-tailers"}
        },
        {
            9, "Glenna Reichert", "Delphine", "Chaim_McDermott@dana.io",
            {"Dayna Park", "Suite 449", "Bartholomebury", "76495-3109", {"24.6463", "-168.8889"}},
            "(775)976-6794 x41206", "conrad.com",
            {"Yost and Sons", "Switchable contextually-based project", "aggregate real-time technologies"}
        },
        {
            10, "Clementina DuBuque", "Moriah.Stanton", "Rey.Padberg@karina.biz",
            {"Kattie Turnpike", "Suite 198", "Lebsackbury", "31428-2261", {"-38.2386", "57.2232"}},
            "024-648-3804", "ambrose.net",
            {"Hoeger LLC", "Centralized empowering task-force", "target end-to-end models"}
        }
   };
   createTree(&t);
   for(int i=0;i<10;++i)
   {
      p=createTNode(users[i]);
      insertTNode(&t,p);
   }
   printf("\nDanh sach User:");
   LRN(t);
   int searchID;TNode *searchTNode;
   printf("\nNhap User ID can tim: ");
   scanf("%d",&searchID);
   searchTNode=searchUserByID(t,searchID);
   if(searchTNode!=NULL)
   {
      printf("\nTim thay User ID: %d",searchID);
      printfUser(searchTNode->key);
   }
   else printf("\nKhong tim thay User ID: %d",searchID);
   int updateID;TNode *updateTNode;
   printf("\nNhap User ID can update: ");
   scanf("%d",&updateID);
   updateTNode=updateUserNameByID(t,updateID);
   if(updateTNode!=NULL)
   {
      printf("\nTim thay User ID: %d",updateID);
      printfUser(updateTNode->key);
   }
   else printf("\nKhong tim thay User ID: %d",updateID);
   return 0;
}
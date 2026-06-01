

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/*Chương trình quản lý user được cài đặt vào
danh sách liên kết đơn, triển khai dưới dạng danh 
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
   user info;
   struct tagNode *next;
}Node;
typedef struct
{
   Node *head,*tail;
}List;
user* scanfUser()
{
   user *us=(user*)malloc(sizeof(user));
   printf("\nNhap ID: ");
   scanf("%d",&us->id);
   printf("\nNhap name: ");
   fgets(us->name,sizeof(us->name),stdin);
   printf("\nNhap username: ");
   fgets(us->username,sizeof(us->username),stdin);
   printf("\nNhap email: ");
   fgets(us->email,sizeof(us->email),stdin);
   printf("\nNhap street: ");
   fgets(us->address.street,sizeof(us->address.street),stdin);
   printf("\nNhap suite: ");
   fgets(us->address.suite,sizeof(us->address.suite),stdin);
   printf("\nNhap city: ");
   fgets(us->address.city,sizeof(us->address.city),stdin);
   printf("\nNhap zipcode: ");
   fgets(us->address.zipcode,sizeof(us->address.zipcode),stdin);
   printf("\nNhap lat: ");
   fgets(us->address.geo.lat,sizeof(us->address.geo.lat),stdin);
   printf("\nNhap lng: ");
   fgets(us->address.geo.lng,sizeof(us->address.geo.lng),stdin);
   printf("\nNhap phone: ");
   fgets(us->phone,sizeof(us->phone),stdin);
   printf("\nNhap website: ");
   fgets(us->website,sizeof(us->website),stdin);
   printf("\nNhap company name: ",us->company.name);
   fgets(us->company.name,sizeof(us->company.name),stdin);
   printf("Nhap catchPhrase: ");
   fgets(us->company.catchPhrase,sizeof(us->company.catchPhrase),stdin);
   printf("Nhap bs: ");
   fgets(us->company.bs,sizeof(us->company.bs),stdin);
   return us;
}
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
void createList(List *l)
{
   l->head=NULL;
   l->tail=NULL;
}
Node* createNode(user us)
{
   Node *p=(Node*)malloc(sizeof(Node));
   p->info=us;
   p->next=NULL;return p;
}
void addHead(List *l,Node* p)
{
   if(l->head==NULL)
   {
      l->head=p;
      l->tail=p;
   }
   else
   {
      p->next=l->head;
      l->head=p;
   }
}
void addTail(List *l,Node* p)
{
   if(l->head==NULL)
   {
      l->head=p;
      l->tail=p;
   }
   else
   {
      l->tail->next=p;
      l->tail=p;
   }
}
void getAllUsers(List l)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      printfUser(p->info);
      p=p->next;
   }
}
Node* getUserByID(List l,int id)
{
   Node *p=l.head;
   while(p!=NULL&&p->info.id!=id)
      p=p->next;
   return p;
}
void postUserSortedByID(List *l,Node *newNode)
{
   Node *p=l->head,*q=NULL;
   while(p!=NULL&&p->info.id<newNode->info.id)
   {
      q=p;p=p->next;
   }
   if(q==NULL)
   {
      if(l->head==NULL)
         l->tail=NULL;
      addHead(l,newNode);
   }
   else 
   {
      if(l->tail==NULL)
         l->tail=newNode;
      newNode->next=p;
      q->next=newNode;
   }
}
Node* updateNameUserByID(List l,int id)
{
   Node *p=l.head;
   while(p!=NULL)
   {
      if(p->info.id==id)
      {
         printf("\nNhap name: ");
         scanf("%s",p->info.name);
         return p;
      }p=p->next;
   }return NULL;
}
void deleteUserByID(List *l,int id)
{
   Node *p=l->head,*q=NULL;
   while(p!=NULL&&p->info.id!=id)
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
void deleteAllUsers(List *l)
{
   Node *p;
   while(l->head!=NULL)
   {
      p=l->head;
      p=p->next;
      free(p);
   }l->tail=NULL;
}

int main()
{
   List userList;Node *p;int id;
   user us[10] = {
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
   createList(&userList);
   for(int i=0;i<10;++i)
   {
      p=createNode(us[i]);
      addTail(&userList,p);
   }
   tt:
   int choice;
      printf("\n===========================");
      printf("\n       MENU-USER-CRUD      ");
      printf("\n===========================");
      printf("\n 1. GET ALL USERS.");
      printf("\n 2. GET USER BY ID.");
      printf("\n 3. POST USER BY ID.");
      printf("\n 4. UPDATE USER BY ID.");
      printf("\n 5. DELETE USER BY ID.");
      printf("\n 6. DESTROY USER.");
      printf("\nChoice: ");scanf("%d",&choice);
   switch (choice)
   {
   case 1:
      printf("\n-----USER LIST-----\n");
      getAllUsers(userList);
      break;
   case 2:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      p=getUserByID(userList,id);
      if(p) printfUser(p->info);
      else printf("\nNot fount user id %d",id);
      break;
   case 3:
      printf("\n-----USER LIST-----\n");
      p=createNode(us[9]);
      postUserSortedByID(&userList,p);
      getAllUsers(userList);
      break;
   case 4:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      p=updateNameUserByID(userList,id);
      printf("\nUser ID %d affter updating: ",id);
      printfUser(p->info);
      break;
   case 5:
      printf("\nEnter ID: ");
      scanf("%d",&id);
      deleteUserByID(&userList,id);
      printf("\n-----USER LIST-----\n");
      getAllUsers(userList);
      break;
   case 6:
      printf("\nUser affter destroy: ");
      deleteAllUsers(&userList);
      break;
   default:printf("\nEnter 1->6!!!");
      break;
   }
   printf("\nDo you want continue?y/N? ");
   if(getch()=='y'||getch()=='Y')goto tt;
   return 0;
}
// {
//     "id": 1,
//     "name": "Leanne Graham",
//     "username": "Bret",
//     "email": "Sincere@april.biz",
//     "address": {
//       "street": "Kulas Light",
//       "suite": "Apt. 556",
//       "city": "Gwenborough",
//       "zipcode": "92998-3874",
//       "geo": {
//         "lat": "-37.3159",
//         "lng": "81.1496"
//       }
//     },
//     "phone": "1-770-736-8031 x56442",
//     "website": "hildegard.org",
//     "company": {
//       "name": "Romaguera-Crona",
//       "catchPhrase": "Multi-layered client-server neural-net",
//       "bs": "harness real-time e-markets"
//     }
//   },
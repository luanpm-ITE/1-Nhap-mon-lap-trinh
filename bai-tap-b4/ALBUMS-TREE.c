

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct 
{
   int id;
   char title[50];
   char url[30];
   char thumbnailUrl[30];
}Album;
typedef struct tagNode
{
   Album key;
   struct tagNode *left,*right;
}TNode;
typedef TNode *TREE;

/*
    "albumId": 1,
    "id": 1,
    "title": "accusamus beatae ad facilis cum similique qui sunt",
    "url": "https://via.placeholder.com/600/92c952",
    "thumbnailUrl": "https://via.placeholder.com/150/92c952"*/
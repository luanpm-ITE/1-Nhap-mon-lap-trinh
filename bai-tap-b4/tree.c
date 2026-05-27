

#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
   int key;
   struct tagNode *left,*right;
}TNode;
typedef TNode *Tree;
void createTree(Tree *t)
{
   *t=NULL;
}
TNode* createTNode(int x)
{
   TNode *p=(TNode*)malloc(sizeof(TNode));
   p->key=x;
   p->left=NULL;
   p->right=NULL;
   return p;
}
int insertTNode(Tree *t,TNode *p)
{
   if(*t!=NULL)
   {
      if((*t)->key==p->key) return 0;
      else
      {
         if(p->key<(*t)->key) 
            return insertTNode(&(*t)->left,p);
         else return insertTNode(&(*t)->right,p);
      }
   }
   *t=p;return 1;
}
void LRN(Tree t)
{
   if(t!=NULL)
   {
      LRN(t->left);
      printf("%d ",t->key);
      LRN(t->right);
   }
}
TNode* searchX(Tree t,int x)
{
   while(t!=NULL)
   {
      if(t->key==x) return t;
      else
      {
         if(x<t->key)
            t=t->left;
         else t=t->right;
      }
   }return NULL;
}
int main()
{
   Tree t;TNode *p;
   int a[]={27,19,7,9,22,20,21,42,32,39,34,47,44},n=13;
   createTree(&t);
   for(int i=0;i<n;++i)
   {
      p=createTNode(a[i]);
      insertTNode(&t,p);
   }
   printf("\nMY TREE: ");
   LRN(t);

   return 0;
}
#ifndef ___BSTREE_HEADER__
#define ___BSTREE_HEADER__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "trackedmemory.h"
#define file 0
#define folder 1
#define up 2
#define uptwice 3
typedef struct hehe Element;
struct hehe{
   char name[21];
   int type;
};
typedef struct _dir_interface dir;
struct _dir_interface{
  dir * (*mkdir)(dir *, Element e[], int a);
  dir * (*touch)(dir *, Element e[], int a);
  void (*preorder)(dir*);
  void (*cd)(dir*, Element e[], int a);
  void (*ls)(dir *, Element e[], int a);
  void (*rm)(dir *, Element e[], int a);
  void (*rmf)(dir *, Element e[], int a);
  void  (*pwd)(dir *);
  void (*find)(dir *, Element e[]);
  void (*destroy)(dir *);
};


dir * newtree();

#endif

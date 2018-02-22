
#include"Mset.h"


int main(int argc, char ** argv){
  char command[30];
  char a[99999];
  Element e[99];
  Element clear;
  for(int b=0;b<21;b++)clear.name[b]=0;
  dir * ms = NULL;
  while(scanf("%s", command) > 0){
    if(ms==NULL){
        ms=newtree();}
    if(strcmp(command, "mkdir") == 0){
        int b=0,e1=0,e2=0;
        gets(a);
        if(a[0]!='\0'){
        b++;
        if(a[b]=='/'){e[e1].name[0]='/';e1++;b++;}
        while(a[b]!=0){
            if(a[b]=='/'&&b!=1&&a[b+1]!=0){
                e1++;
                e2=0;}
            else if(a[b]!='/'){
                e[e1].name[e2]=a[b];e2++;}
                b++;}
        //for(e2=0;e2<=e1;e2++)printf("dir %s\n",e[e2].name);
        ms->mkdir(ms,e,e1);
        }}
    else if(strcmp(command, "touch") == 0){
        int b=0,e1=0,e2=0;
        gets(a);
        if(a[0]!='\0'){
        b++;
        if(a[b]=='/'){e[e1].name[0]='/';e1++;b++;}
        while(a[b]!=0){
            if(a[b]=='/'&&b!=1&&a[b+1]!=0){
                e1++;
                e2=0;}
            else if(a[b]!='/'){
                e[e1].name[e2]=a[b];e2++;}
                b++;}

        ms->touch(ms,e,e1);
        }}
    else if(strcmp(command, "ls") == 0){
        int b=0,e1=0,e2=0;
        gets(a);
        if(a[0]!='\0'){
        b++;
        if(a[b]=='/'){e[e1].name[0]='/';e1++;b++;}
        int c=0;
        while(a[b]!=0){c=1;
            if(a[b]=='/'&&b!=1&&a[b+1]!=0){
                e1++;
                e2=0;}
            else if(a[b]!='/'){
                e[e1].name[e2]=a[b];e2++;}
                b++;}
        if(c==1)
        e1++;
        }ms->ls(ms,e,e1);}
    else if(strcmp(command, "Inorder") == 0){
        printf("Inorder:\n");
        ms->preorder(ms);}
    else if(strcmp(command, "cd") == 0){
        int b=0,e1=0,e2=0;
        gets(a);
        if(a[0]!='\0'){
        b++;
        if(a[b]=='/'){e[e1].name[0]='/';e1++;b++;}
        int c=0;
        while(a[b]!=0){c=1;
            if(a[b]=='/'&&b!=1&&a[b+1]!=0){
                e1++;
                e2=0;}
            else if(a[b]!='/'){
                e[e1].name[e2]=a[b];e2++;}
                b++;}
        }
        ms->cd(ms,e,e1);}
    else if(strcmp(command, "find")==0){
        int b=0,e1=0;
        gets(a);
        if(a[0]!='\0'){
            b++;
            while(a[b]!=0){
                e[0].name[e1]=a[b];e1++;b++;
            }
            ms->find(ms,e);}
    }
    else if(strcmp(command, "rm") == 0){
        int b=0,e1=0,e2=0;
        gets(a);
        if(a[0]!='\0'){
        b++;
        if(a[b]=='-'&&a[b+1]=='f'){
                e[e1].name[0]='-';b++;
                e[e1].name[1]='f';e1++;b++;b++;}
        if(a[b-1]!=0){
        if(a[b]=='/'){e[e1].name[0]='/';e1++;b++;}
        int c=0;
        while(a[b]!=0){c=1;
            if(a[b]=='/'&&b!=1&&a[b+1]!=0){
                e1++;
                e2=0;}
            else if(a[b]!='/'){
                e[e1].name[e2]=a[b];e2++;}
                b++;}
        if(e[0].name[0]=='-'&&e[0].name[1]=='f'){
            ms->rmf(ms,e,e1);}
        else
            ms->rm(ms,e,e1);}
        }
    }
    else if(strcmp(command, "pwd") == 0){
        ms->pwd(ms);}
    for(int b=0;b<99;b++)e[b]=clear;
  }
ms->destroy(ms);

return 0;}


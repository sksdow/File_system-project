#include"Mset.h"


typedef struct mynode node;
typedef struct mybs mbs;
struct mynode{
    Element e;
    node *right,*bottom,*top;
    };
struct mybs{
    dir set;
    node *root;
    node *cwd;
    int size;};


  dir * BSmkdir(dir*,Element e[], int a);
  dir * BStouch(dir *, Element e[], int a);
  void  BSls(dir *, Element e[], int a);
  void  BScd(dir*, Element e[], int a);
  void  BSrm(dir*, Element e[], int a);
  void  BSrmf(dir*, Element e[], int a);
  void BSpreorder(dir*);
  void BSpwd(dir*);
  void destroy(node*);
  void BSfind(dir*, Element e[]);
  void BSdestroy(dir *);




dir * newtree(){
    mbs *l=MALLOC(sizeof(mbs));
    l->set.mkdir=BSmkdir;
    l->set.touch=BStouch;
    l->set.ls=BSls;
    l->set.cd=BScd;
    l->set.rm=BSrm;
    l->set.rmf=BSrmf;
    l->set.preorder=BSpreorder;
    l->set.pwd=BSpwd;
    l->set.find=BSfind;
    l->set.destroy=BSdestroy;
    l->root=MALLOC(sizeof(node));
    l->root->bottom=NULL;l->root->top=NULL;l->root->right=NULL;
    l->cwd=l->root;
    l->size=0;
return (dir*)l;}

int compareabs(Element one, Element two){
    int b=0,one1=0,two1=0;
    while(b<21){
        one1=(int)one.name[b];
        two1=(int)two.name[b];
        if(one1==46) {one1=1;}
        else if(one1==45) {one1=2;}
        else if(one1==95) {one1=3;}
        if(two1==46) {two1=1;}
        else if(two1==45) {two1=2;}
        else if(two1==95) {two1=3;}
        if(one1>two1) {return 1;}
        else if(one1<two1) {return -1;}
        else if(one1==0&&two1==0){return 10;}
        b=b+1;
}return 10;
    }
int Compare(Element one, Element two){
    int b=0,one1=0,two1=0;
    while(b<21){
        one1=(int)one.name[b];
        two1=(int)two.name[b];
        if(one1==46) {one1=1;}
        else if(one1==45) {one1=2;}
        else if(one1==95) {one1=3;}
        if(two1==46) {two1=1;}
        else if(two1==45) {two1=2;}
        else if(two1==95) {two1=3;}

        if(one.type==file)
            one1=one1+999;
        if(two.type==file)
            two1=two1+999;

        if(one1>two1) {return 1;}
        else if(one1<two1) {return -1;}
        else if(one1==0&&two1==0)return 0;

        b=b+1;
}return 0;
    }


node *insertright(node *root, Element e){
    node *cwd;
    if(root->bottom==NULL){
        node *newnode=MALLOC(sizeof(node));
        newnode->e=e;
        newnode->right=NULL;newnode->bottom=NULL;
        root->bottom=newnode;
        cwd=newnode;newnode->top=root;}
    else{
        node *greater=root->bottom ,*lesser=NULL;
        int a=0,exists=0;
        while(greater!=NULL){

            a=Compare(e,greater->e);
            if(a==-1&&lesser==NULL){
                //printf("something\n");
                node *newnode=MALLOC(sizeof(node));
                newnode->e=e;
                newnode->bottom=NULL;
                newnode->right=root->bottom;
                root->bottom=newnode;
                cwd=newnode;newnode->top=root;
                break;}
            else if(a==0){cwd=greater;break;}
            else if(a==-1&&lesser!=NULL){
                node *newnode=MALLOC(sizeof(node));
                newnode->e=e;newnode->bottom=NULL;
                lesser->right=newnode;newnode->right=greater;
                cwd=newnode;newnode->top=root;break;}
            else if(greater->right==NULL){
                node *newnode=MALLOC(sizeof(node));
                newnode->e=e;newnode->bottom=NULL;
                greater->right=newnode;newnode->right=NULL;
                cwd=newnode;newnode->top=root;}
            lesser=greater;
            greater=greater->right;}
            }return cwd;
}

int search2(node *root, Element e, int mode){
    if(root->bottom==NULL)
        return 0;
    node *greater=root->bottom;
    if(mode==0){
    while(greater!=NULL){
        if(compareabs(greater->e,e)==10){
            return 1;}
        greater=greater->right;}
    return 0;}
    else{
        int a=0;
        while(greater!=NULL){
            a=compareabs(greater->e,e);
            if(a==10){break;}
            if(greater->right==NULL)break;
            greater=greater->right;}
        //printf("%d %d\n",a,e.type);
        if(a==10&&greater->e.type==file)
            return 2;}
}

void Abspath(mbs *tree,char print[]){
    node *path=tree->cwd;node *temp=path;
    int b=0,c=0;
    while(path->top!=tree->root){
        path=path->top;}
    while(path!=temp->bottom){
        c=0;
        print[b]='/';b++;
        while(path->e.name[c]!=0){
            //printf("%c ",path->e.name[c]);
            print[b]=path->e.name[c];
            c++;
            b++;}//printf("\n");
        path=path->bottom;}
    for(;print[b]!=0;b++)print[b]=0;
}


void Abspath2(node *node1,char a[]){
    node *path2=node1;
    int b=0,c=0,d=0;
    for(b=0;a[b]!=0;b++)a[b]=0;
    a[b]='/';b++;
    node *temp=path2;
    while(path2->top!=NULL){
        path2=path2->top;}

    while(path2!=temp){
        path2=path2->bottom;
        while(path2->e.name[c]!=0){
            a[b]=path2->e.name[c];c++;b++;}
        a[b]='/';c=0;b++;d=1;}

}


void Abspath3(node *found,char print[]){
    node *last=found;
    node *temp=found->top;
    int a=0,b=0,c=1;
    Element e[99];
    while(temp->top!=NULL){
        c=0;
        e[a]=temp->e;
        temp=temp->top;a++;}
    if(a!=0)a--;
    //for(int d=0;d<=a;d++)printf("%s ",e[d].name);
    while(a>=0&&c!=1){
        c=0;
        print[b]='/';b++;
        while(e[a].name[c]!=0){
            print[b]=e[a].name[c];
            c++;b++;}
        c=0;
        a--;}
    c=0;
    print[b]='/';b++;
    while(found->e.name[c]!=0){
        print[b]=found->e.name[c];
        c++;b++;}
}


dir * BSmkdir(dir *bs, Element e[], int a){
    mbs *tree=(mbs*)bs;
    node *temp=tree->cwd;
    int b=0,c=0,f=0;Element clear;
    for(b=0;b<21;b++)clear.name[b]=0;
    b=0;
    if(e[0].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
        c=0;
        while(b<=a&&e[b].name[0]=='.'){
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
            f=0;
            node*temp2;
            e[b].type=folder;
            if(b==a){
                if(search2(tree->cwd,e[b],0)==1){
                    if(tree->cwd!=tree->root){
                        char s[9999]={0};
                        Abspath3(tree->cwd,s);
                        printf("Path Error: '%s/%s' already exists and cannot be created.\n",s,e[b].name);}
                    else printf("Path Error: '/%s' already exists and cannot be created.\n",e[b].name);
                    printf("Make Dir Error: Cannot create directory.\n");
                }
                else{
                    temp2=insertright(tree->cwd,e[b]);}}
            else{
                if(search2(tree->cwd,e[b],1)==2){
                    if(tree->cwd!=tree->root){
                        char s[9999]={0};
                        Abspath3(tree->cwd,s);
                        printf("Path Error: Cannot create sub-directory content. '%s/%s' is a file.\n",s,e[b].name);}
                    else printf("Path Error: Cannot create sub-directory content. '/%s' is a file.\n",e[b].name);
                    printf("Make Dir Error: Cannot create directory.\n");
                    e[b]=clear;b=a+1;break;}
                else{
                tree->cwd=insertright(tree->cwd,e[b]);}}
            //if(temp!=tree->cwd)tree->size++;
            e[b]=clear;b++;c=1;}
        if(c==1)b--;
    }
    tree->cwd=temp;


return bs;}


dir * BStouch(dir *bs, Element e[], int a){
    mbs *tree=(mbs*)bs;
    node *temp=tree->cwd;
    int b=0,c=0,f=0;Element clear;
    for(b=0;b<21;b++)clear.name[b]=0;
    b=0;
    if(e[0].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
        c=0;
        while(b<=a&&e[b].name[0]=='.'){
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
            f=0;
            node*temp2;
            e[b].type=folder;
            if(b==a){
                if(search2(tree->cwd,e[b],0)==1){
                    if(tree->cwd!=tree->root){
                        char s[9999]={0};
                        Abspath3(tree->cwd,s);
                        printf("Path Error: '%s/%s' already exists and cannot be created.\n",s,e[b].name);}
                    else printf("Path Error: '/%s' already exists and cannot be created.\n",e[b].name);
                    printf("Touch Error: Cannot create file.\n");
                }
                else{
                    e[b].type=file;
                    temp2=insertright(tree->cwd,e[b]);}}
            else{
                if(search2(tree->cwd,e[b],1)==2){
                    if(tree->cwd!=tree->root){
                        char s[9999]={0};
                        Abspath3(tree->cwd,s);
                        printf("Path Error: Cannot create sub-directory content. '%s/%s' is a file.\n",s,e[b].name);}
                    else printf("Path Error: Cannot create sub-directory content. '/%s' is a file.\n",e[b].name);
                    printf("Touch Error: Cannot create file.\n");
                    e[b]=clear;b=a+1;break;}
                else{
                tree->cwd=insertright(tree->cwd,e[b]);}}
            //if(temp!=tree->cwd)tree->size++;
            e[b]=clear;b++;c=1;}
        if(c==1)b--;
    }
    tree->cwd=temp;

return bs;}


node* walk(node *root, Element e, int *b){
    node *cwd=NULL;
    if(root->bottom!=NULL){
        node *greater=root->bottom;node *lesser=NULL;
        int a=0;
        while(greater!=NULL){
            if(*b==1){
                a=compareabs(e,greater->e);
                if(a==10){
                        if(greater->e.type==file){
                            *b=10;
                            break;}
                        else{
                            //printf("something\n");
                            cwd=greater;return cwd;}}}
            else if(*b==0){
                if(greater->e.type==folder)
                    printf("D ");
                else
                    printf("F ");
                printf("%s\n",greater->e.name);}
            lesser=greater;
            greater=greater->right;}
        }
    return cwd;}




void BSls(dir *bs, Element e[], int a){
    mbs *tree=(mbs*)bs;
    int b=0,c=0,d=0,f=0;
    Element clear;
    int *g=MALLOC(sizeof(int));
    for(b=0;b<21;b++)clear.name[b]=0;
    node *temp=tree->cwd;
    b=0;
    if(e[0].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
    c=0;
        while(b<=a&&e[b].name[0]=='.'){//printf("something\n");
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
                f=0;
                if(b==a){
                    if(tree->cwd!=tree->root){
                        char s[9999]={0};
                        //printf("%s\n",tree->cwd->e.name);
                        Abspath3(tree->cwd,s);
                        printf("Listing For '%s':\n",s);}
                    else {printf("Listing For '/':\n");}
                    *g=0;
                    walk(tree->cwd,e[b],g);
                    e[b]=clear;}
                else{
                    *g=1;node *temp2;
                    temp2=walk(tree->cwd,e[b],g);
                    if(temp2==NULL&&*g!=10){
                        if(tree->cwd!=tree->root){
                            char s2[9999]={0};Abspath3(tree->cwd,s2);
                            printf("Path Error: directory '%s/%s' does not exist.\n",s2,e[b].name);}
                        else printf("Path Error: directory '/%s' does not exist.\n",e[b].name);
                        printf("List Error: Cannot perform list operation.\n");d=1;e[b]=clear;
                        break;}
                    else if(temp2==NULL&&*g==10){
                        if(tree->cwd!=tree->root){
                            char s3[9999]={0};
                            Abspath3(tree->cwd,s3);
                            printf("List Error: Cannot perform list operation. '%s/%s' is a file\n",s3,e[b].name);
                            }
                        else printf("List Error: Cannot perform list operation. '/%s' is a file\n",e[b].name);
                        d=1;e[b]=clear;break;}
                    tree->cwd=temp2;}

            b++;c=1;}
        if(c==1)b--;
        if(d==1)break;
    }
    FREE(g);
    tree->cwd=temp;
    }


void BSpwd(dir* bs){
    mbs *tree=(mbs*)bs;
    if(tree->cwd!=tree->root){
        char s[9999]={0};
        Abspath3(tree->cwd,s);int b=0;
        printf("%s\n",s);}
    else {printf("/\n");}
}


void realpreorder(node * root){
    if(root==NULL){
        //printf("\n");
        return;
    }
    else{
        if(root->e.type==folder)
                    printf("D ");
                else
                    printf("F ");
        printf("%s\n",root->e.name);
        realpreorder(root->bottom);

        realpreorder(root->right);}}
void BSpreorder(dir *bs){
    mbs *tree=(mbs*)bs;
    realpreorder(tree->cwd->bottom);}



void BScd(dir *bs, Element e[], int a){
    mbs *tree=(mbs*)bs;
    int b=0,c=0,d=0,f=0;
    //printf("%d\n",a);
    //for(b=0;b<=a;b++)printf("%s\n",e[b].name);
    node *temp=tree->cwd;
    Element clear;
    int *g=MALLOC(sizeof(int));
    for(b=0;b<21;b++)clear.name[b]=0;
    b=0;
    if(e[0].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
    c=0;
        while(b<=a&&e[b].name[0]=='.'){//printf("something\n");
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
                f=0;
                if(e[b].name[0]!=0){
                    *g=1;node *temp2;
                    temp2=walk(tree->cwd,e[b],g);
                    if(temp2==NULL){
                        if(*g!=10){
                        if(tree->cwd!=tree->root){
                            char s2[9999]={0};Abspath3(tree->cwd,s2);
                            printf("Path Error: directory '%s/%s' does not exist.\n",s2,e[b].name);}
                        else printf("Path Error: directory '/%s' does not exist.\n",e[b].name);}
                        printf("Change Dir Error: Cannot change working directory.\n");
                        tree->cwd=temp;
                        d=1;e[b]=clear;break;}
                    e[b]=clear;
                    tree->cwd=temp2;}
                    b++;c=1;}
        if(c==1)b--;
        if(d==1)break;
    }
    FREE(g);
    }



void realfind(node *parent,Element e){
    if(parent==NULL)
        return;
    if(strstr(parent->e.name,e.name)!=NULL){
        char print[9999]={0};
        Abspath3(parent,print);
        if(parent->e.type==folder)
            printf("D ");
        else
            printf("F ");
        printf("%s\n",print);
        }
    realfind(parent->bottom,e);
    realfind(parent->right,e);
}
void BSfind(dir*bs, Element e[]){
    mbs *tree=(mbs*)bs;
    int b=0;Element clear;
    for(b=0;b<21;b++)clear.name[b]=0;
    printf("Searching For '%s':\n",e[0].name);
    realfind(tree->root->bottom,e[0]);
    e[0]=clear;
return;}



void realremove(node* parent, node * child){
    if(parent->bottom==child&&child->right==NULL){
        parent->bottom=NULL;}
    else{
        node *lesser=parent->bottom;
        if(lesser==child){
            parent->bottom=lesser->right;}
        else{
            while(lesser->right!=child)
                lesser=lesser->right;
            lesser->right=child->right;}
    }
}
node* removewalk(node *root, Element e){
    node *cwd=NULL;
    if(root->bottom!=NULL){
        node *greater=root->bottom;node *lesser=NULL;
        int a=0;
        while(greater!=NULL){
                a=compareabs(e,greater->e);
                if(a==10){
                    cwd=greater;return cwd;}
            lesser=greater;
            greater=greater->right;}
        }
    return cwd;
}
void  BSrm(dir*bs, Element e[], int a){
    mbs *tree=(mbs*)bs;
    int b=0,c=0,d=0,f=0;
    node *temp=tree->cwd;
    Element clear;
    int *g=MALLOC(sizeof(int));
    for(b=0;b<21;b++)clear.name[b]=0;
    b=0;
    if(e[0].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
    c=0;
        while(b<=a&&e[b].name[0]=='.'){//printf("something\n");
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
            f=0;
            if(e[b].name[0]!=0){
                if(b==a){
                    *g=1;node *temp2;node *temp3;
                    temp2=removewalk(tree->cwd,e[b]);
                    if(temp2==NULL){
                        printf("Remove Error: Cannot remove file or directory.\n");
                        d=1;e[b]=clear;break;}
                    else if(temp2->bottom!=NULL){
                        if(tree->cwd!=tree->root){
                            char s2[9999]={0};Abspath3(temp2,s2);
                            printf("Remove Error: directory '%s' is not empty.\n",s2,e[b].name);}
                        else printf("Remove Error: directory '/%s' is not empty.\n",e[b].name);
                        d=1;e[b]=clear;break;}
                    realremove(tree->cwd,temp2);
                    destroy(temp2->bottom);
                    FREE(temp2);
                    e[b]=clear;}
                else{
                    *g=1;node *temp2;
                    temp2=walk(tree->cwd,e[b],g);
                    if(temp2==NULL){
                        printf("Remove Error: Cannot remove file or directory.\n");
                        d=1;e[b]=clear;break;}
                    tree->cwd=temp2;e[b]=clear;}
                }
                    b++;c=1;}
        if(c==1)b--;
        if(d==1)break;
    }
    tree->cwd=temp;
    FREE(g);
}


void  BSrmf(dir*bs, Element e[], int a){
    //printf("%d\n",a);
    //for(int b=0;e[b].name[0]!=0;b++)printf("%s\n",e[b].name);
    mbs *tree=(mbs*)bs;
    int b=0,c=0,d=0,f=0;
    node *temp=tree->cwd;
    Element clear;
    int *g=MALLOC(sizeof(int));
    for(b=0;b<21;b++)clear.name[b]=0;
    b=0;e[b]=clear;b++;
    if(e[1].name[0]=='/'){tree->cwd=tree->root;e[b]=clear;b++;}
    for(;b<=a;b++){
    c=0;
        while(b<=a&&e[b].name[0]=='.'){//printf("something\n");
            if(e[b].name[0]=='.'&&e[b].name[1]=='.'){
                if(tree->cwd!=tree->root)tree->cwd=tree->cwd->top;}
            else if(e[b].name[1]!='.'&&e[b].name[1]!=0){f=1;break;}
            e[b]=clear;b++;c=1;}
        while((b<=a&&e[b].name[0]!='.')||f==1){
            f=0;
            if(e[b].name[0]!=0){
                if(b==a){
                    *g=1;node *temp2;node *temp3;
                    temp2=removewalk(tree->cwd,e[b]);
                    if(temp2==NULL){
                        printf("Remove Error1: Cannot remove file or directory.\n");
                        d=1;e[b]=clear;break;}
                    realremove(tree->cwd,temp2);
                    destroy(temp2->bottom);
                    FREE(temp2);
                    e[b]=clear;}
                else{
                    *g=1;node *temp2;
                    temp2=walk(tree->cwd,e[b],g);
                    if(temp2==NULL){
                        printf("Remove Error: Cannot remove file or directory.\n");
                        d=1;e[b]=clear;break;}
                    tree->cwd=temp2;e[b]=clear;}
                }
                    b++;c=1;}
        if(c==1)b--;
        if(d==1)break;
    }
    tree->cwd=temp;
    FREE(g);
}


void destroy(node* parent){
    if(parent==NULL)
        return;
    destroy(parent->bottom);
    destroy(parent->right);
    FREE(parent);
}

void BSdestroy(dir *bs){
    mbs *tree=(mbs*)bs;
    destroy(tree->root);
    FREE(tree);
}




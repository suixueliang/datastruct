#include<stdio.h>
typedef struct LinkListHead{
    int num;
    struct LinkListHead* next;
}LinkListHead;

typedef struct LinkListNode{
    int val;
    struct LinkListNode* next;
    struct LinkListNode* pre;
}LinkListNode;

//初始化
LinkListHead* initD(){
    LinkListHead* head=(LinkListHead*)malloc(sizeof(LinkListHead));
    head->next=NULL;
    head->num=0;
    return head;
}

//向i位置插入x
void insert(LinkListHead* head,int i,int x){
    LinkListNode* node=(LinkListNode*)malloc(sizeof(LinkListNode));
    node->next=node->pre=node;
    node->val=x;
    LinkListNode* cur=head->next;
    LinkListNode* pre=head->next;
    if(head->num==0){
        head->next=node;
        head->num++;
        return;
    }
    LinkListNode* rear=head->next;
    while(rear->next!=head->next){
        rear=rear->next;
    }
    if(i==1){
        node->next=cur;
        node->pre=rear;
        cur->pre=node;
        rear->next=node;
        head->next=node;
        head->num++;
        return;
    }
    if(i==-1){
        node->pre=cur->pre;
        node->next=cur;
        node->pre->next=node;
        cur->pre=node;
        head->num++;
        return;
    }
    if(i>=2){
        for(int j=0;j<i-1;j++){
            cur=cur->next;
            pre=cur->pre;
        }
        pre->next=node;
        node->next=cur;
        cur->pre=node;
        node->pre=pre;
        head->num++;
        return;
    }
}

//删除i个元素
void deli(LinkListHead* head,int i){
    LinkListNode* cur=head->next;
    if(i==1){
        head->next=cur->next;
        cur->next->pre=cur->pre;
        cur->pre->next=cur->next;
        cur->next=cur->pre=NULL;
        head->num--;
        return;
    }
    LinkListNode* pre=cur->pre;
    for(int j=0;j<i-1;j++){
        cur=cur->next;
    }
    pre=cur->pre;
    pre->next=cur->next;
    cur->next->pre=pre;
    cur->next=cur->pre=NULL;
    head->num--;
    return;
}

//删除值为x的节点
void delx(LinkListHead* head,int x){
    LinkListNode* cur=head->next;
    if(cur->val==x){
        head->next=cur->next;
        cur->next->pre=cur->pre;
        cur->pre->next=cur->next;
        cur->next=cur->pre=NULL;
        head->num--;
        return;
    }
    while(cur->val!=x){
        cur=cur->next;
    }
    LinkListNode* pre=cur->pre;
    pre->next=cur->next;
    cur->next->pre=pre;
    cur->next=cur->pre=NULL;
    head->num--;
    return;
}

//查找x的位置
int findx(LinkListHead* head,int x){
    int j=1;
    LinkListNode* cur=head->next;
    while(cur->val!=x){
        j++;
        cur=cur->next;
    }
    return j;
}

//修改x为y
void changeXToY(LinkListHead* head,int x,int y){
    LinkListNode* cur=head->next;
    while(cur->val!=x){
        cur=cur->next;
    }
    cur->val=y;
    return;
}
void show(LinkListHead* head){
    LinkListNode* cur=head->next;
    do{
        printf("%d\n",cur->val);
        cur=cur->next;
    }while(cur!=head->next);
    return;

}

int main(){
    LinkListHead* mylist=initD();
    insert(mylist,1,1);
    insert(mylist,1,2);
    insert(mylist,1,3);
    insert(mylist,-1,4);
    insert(mylist,5,5);
    insert(mylist,2,6);
    insert(mylist,2,7);
    show(mylist);
    puts("-------------------");
    deli(mylist,1);
    deli(mylist,3);
    show(mylist);
    puts("-------------------");
    delx(mylist,1);
    show(mylist);
    puts("-------------------");
    int x;
    x=findx(mylist,6);
    printf("%d\n",x);
    puts("-------------------");
    changeXToY(mylist,7,1);
    show(mylist);
}

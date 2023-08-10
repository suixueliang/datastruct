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

LinkListHead* initLinkList(){
    LinkListHead* head=(LinkListHead*)malloc(sizeof(LinkListHead));
    head->num=0;
    head->next=NULL;
    return head;
}

void insertvalue(LinkListHead* head,int i,int x){
    LinkListNode* node=(LinkListNode*)malloc(sizeof(LinkListNode));
    LinkListNode* cur=head->next;
    node->val=x;
    node->next=NULL;
    node->pre=NULL;
    if(head->num==0){
        head->next=node;
        node->next=NULL;
        head->num++;
        return;
    }
    if(i==1){
        node->next=cur;
        cur->pre=node;
        head->next=node;
        //cur->pre=node;
        head->num++;
        return;
    }
    if(i==2){
        node->next=cur->next;
        cur->next->pre=node;
        cur->next=node;
        node->pre=cur;
        head->num++;
        return;
    }
    if(i==-1){
        LinkListNode* rear=head->next;
        while(rear->next!=NULL){
            rear=rear->next;
        }
        node->next=NULL;
        rear->next=node;
        node->pre=rear;
        head->num++;
        return;
    }
    if(i>2&&i<head->num){
        for(int j=0;j<i-2;j++){
            cur=cur->next;
        }
        node->next=cur->next;
        cur->next->pre=node;
        cur->next=node;
        node->pre=cur;
        head->num++;
        return;
    }

}
//删除第i个位置的元素
void delIOfDouble(LinkListHead* head,int i){
    LinkListNode* cur=head->next;
    LinkListNode* pre=head->next;
    if(i==1){
        head->next=cur->next;
        cur->next->pre=NULL;
        cur->next=NULL;
        head->num--;
        return;
    }
    if(i==2){
        cur->next->next->pre=cur;
        cur->next=cur->next->next;
        head->num--;
        return;
    }
    if(i==head->num){
        LinkListNode* rear=head->next;
        while(rear->next->next!=NULL){
            rear=rear->next;
        }
        rear->next->pre=NULL;
        rear->next=NULL;
        head->num--;
        return;
    }
    for(int j=0;j<i-2;j++){
        cur=cur->next;
    }
    cur->next->next->pre=cur;
    cur->next=cur->next->next;
    head->num--;
    return;

}

//删除值为x的元素
void delXOfDouble(LinkListHead* head,int x){
    LinkListNode* cur=head->next;
    if(cur->val==x){
        head->next=cur->next;
        cur->next->pre=NULL;
        cur->next=NULL;
        head->num--;
        return;
    }
    LinkListNode* rear=head->next;
    while(rear->next->next!=NULL){
        rear=rear->next;
    }
    if(rear->next->val==x){
        rear->next->pre=NULL;
        rear->next=NULL;
        head->num--;
        return;
    }
    while(cur->next->val!=x){
        cur=cur->next;
    }
    cur->next->next->pre=cur;
    cur->next=cur->next->next;
    head->num--;
    return;

}
//查找值为x的元素的位置
int searchX(LinkListHead* head,int x){
    LinkListNode* cur=head->next;
    int j=1;
    while(cur->val!=x){
        j++;
        cur=cur->next;
    }
    return j;
}
//将x改为y
void changextoy(LinkListHead* head,int x,int y){
    LinkListNode* cur=head->next;
    while(cur->val!=x){
        cur=cur->next;
    }
    cur->val=y;
}
void show(LinkListHead* head){
    LinkListNode* cur=head->next;
    do{
        printf("%d\n",cur->val);
        cur=cur->next;
    }while(cur!=NULL);
}

int main(){
    LinkListHead* mylist=initLinkList();
    insertvalue(mylist,1,1);
    insertvalue(mylist,-1,2);
    insertvalue(mylist,-1,3);
    insertvalue(mylist,-1,4);
    insertvalue(mylist,-1,5);
    insertvalue(mylist,3,6);
    insertvalue(mylist,2,7);
    show(mylist);
    puts("------------------");
    delIOfDouble(mylist,1);
    delIOfDouble(mylist,2);
    delIOfDouble(mylist,5);
    delIOfDouble(mylist,3);
    show(mylist);
    puts("------------------");
    delXOfDouble(mylist,4);
    show(mylist);
    puts("------------------");
    int x=searchX(mylist,6);
    printf("这个值的位置是%d\n",x);
    puts("------------------");
    changextoy(mylist,6,5);
    show(mylist);
    return 0;
}

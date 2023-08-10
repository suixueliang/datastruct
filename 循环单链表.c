#include<stdio.h>
#include<stdbool.h>

typedef struct Node{
    int val;
    struct Node* next;
}LinkListNode;

typedef struct head{
    int num;
    LinkListNode* next;
}LinkListHead;

//初始化循环单链表
LinkListHead* initLinkList(void){
    LinkListHead* head =(LinkListHead*)malloc(sizeof(LinkListHead));
    head->num = 0;
    head->next=NULL;
    return head;
}

//遍历单链表
void showLinkedList(LinkListHead* head){
    LinkListNode* pnode=head->next;
    do{
        printf("%d\n",pnode->val);
        pnode=pnode->next;
    }while(pnode!=head->next);
}

//向i个位置插入x
void insertvalueInI(LinkListHead* head,int i,int x){
    if(!head||i==0||i>head->num+1) return;
    LinkListNode* tmp=(LinkListNode*)malloc(sizeof(LinkListNode));
    tmp->val=x;
    tmp->next=tmp;
    if(head->num==0){
        head->next=tmp;
        head->num++;
        return;
    }
    //找尾节点
    LinkListNode* rear=head->next->next;//从第二个节点开始
    while(rear->next!=head->next){
        rear=rear->next;
    }
    if(i==1){
        rear->next=tmp;                 //头插
        tmp->next=head->next;
        head->next=tmp;
        head->num++;
        return;
    }
    if(i==-1){                          //尾插
        tmp->next=head->next;
        rear->next=tmp;
        head->num++;
        return;
    }
    if(i>1){
        LinkListNode* pnode=head->next;
        for(int j=0;j<i-2;j++){
            pnode=pnode->next;
        }
        tmp->next=pnode->next;
        pnode->next=tmp;
        head->num++;
        return;
    }
}
//删除第i个位置的节点
void delI(LinkListHead* head,int i){
    LinkListNode* cur=head->next;
    LinkListNode* pre=head;
    //找尾节点
    LinkListNode* rear=head->next->next;//从第二个节点开始
    while(rear->next!=head->next){
        rear=rear->next;
    }
    if(i==1){
        head->next=cur->next;
        rear->next=head->next;
        cur->next=NULL;
        head->num--;
    }else{
        pre->next=cur;
        for(int j=0;j<i-1;j++){
            cur=cur->next;
            pre=pre->next;
        }
        pre->next=cur->next;
        cur->next=NULL;
        head->num--;
    }
}
//删除值为x的节点
void delX(LinkListHead* head,int x){
    LinkListNode* cur=head->next;
    LinkListNode* pre=head;
    LinkListNode* rear=head->next->next;//从第二个节点开始
    while(rear->next!=head->next){
        rear=rear->next;
    }
    if(head->next->val==x){
        head->next=cur->next;
        rear->next=head->next;
        cur->next=NULL;
        head->num--;
    }else{
        while(cur->val!=x){
            cur=cur->next;
            pre=pre->next;
        }
        pre->next=cur->next;
        cur->next=NULL;
        head->num--;
    }

}
//查找值为x的节点
int findX(LinkListHead* head,int x){
    LinkListNode* cur=head->next;
    int j=0;
    while(cur->val!=x){
        j++;
        cur=cur->next;
    }
    return j;
}

//修改值为x的到y
void changeXToY(LinkListHead* head,int x,int y){
    LinkListNode* cur=head->next;
    int j=0;
    while(cur->val!=x){
        j++;
        cur=cur->next;
    }
    cur->val=y;
}
int main(){
    LinkListHead* mylist=initLinkList();
    insertvalueInI(mylist,1,1);
    insertvalueInI(mylist,2,2);
    insertvalueInI(mylist,3,3);
    insertvalueInI(mylist,4,4);
    insertvalueInI(mylist,-1,5);
    showLinkedList(mylist);
    puts("---------------------");
    delI(mylist,1);
    delI(mylist,2);
    showLinkedList(mylist);
    puts("---------------------");
    delX(mylist,2);
    showLinkedList(mylist);
    puts("---------------------");
    int x=findX(mylist,5);
    printf("这个值的位置是%d\n",x+1);
    puts("---------------------");
    changeXToY(mylist,5,2);
    showLinkedList(mylist);
    return 0;
}

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

//初始化单链表
LinkListHead* initLinkList(void){
    LinkListHead* head =(LinkListHead*)malloc(sizeof(LinkListHead));
    head->num = 0;
    head->next=NULL;
    return head;
}

//向链表中第i个位置插入x,i=1头插，i=-1尾插
void insertValueLinkedList(LinkListHead* head,int value,int i){
    //判误

    if(!head) return;
    if(i==1){
        LinkListNode* tmp=(LinkListNode*)malloc(sizeof(LinkListNode));
        tmp->val=value;
        tmp->next=NULL;
        tmp->next = head ->next;
        head->next = tmp;
        head->num++;
        return;
    }
    if(i ==-1){
        LinkListNode* tmp =head->next;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=(LinkListNode*)malloc(sizeof(LinkListNode));
        tmp->next->val = value;
        tmp->next->next = NULL;
        head->num++;
        return;
    }
    LinkListNode* tmp =head->next;
    for(int j=0;j<i-2;j++){
        tmp = tmp->next;
    }
    LinkListNode* node=(LinkListNode*)malloc(sizeof(LinkListNode));
    node->next = tmp->next;
    tmp->next = node;
    node->val = value;
    head->num++;
    return;
}

//遍历单链表
void showLinkedList(LinkListHead* head){
    LinkListNode* pnode=head->next;
    for(int i=0;i<head->num;i++){
        printf("%d\n",pnode->val);
        pnode=pnode->next;
    }
}

//删除第i个元素
void delILinkedList(LinkListHead* head,int i){
    if(!head) return;
    LinkListNode* pre=head->next;
    LinkListNode* cur=head->next;
    if(i==1){
        head->next=pre->next;
        pre->next=NULL;
        head->num--;
        return;
    }
    if(i==2){
        cur=pre->next;
        pre->next=cur->next;
        cur->next=NULL;
        head->num--;
        return;
    }
    if(i>2){
        for(int j=0;j<i-2;j++){
            pre=pre->next;
        }
        cur=pre->next;
        pre->next = cur->next;
        cur->next=NULL;
        head->num--;
        return;
    }
}

//删除值为X的元素
void delXLinkedList(LinkListHead* head,int x){
    if(!head) return;
    LinkListNode* pre=head->next;
    LinkListNode* cur=head->next;
    if(head->num==1){
        if(pre->val==x){
            head->next=NULL;
            head->num--;
            return;
        }
    }
    if(head->num==2){
        if(cur->val==x){
            pre->next=cur->next;
            cur->next=NULL;
            head->num--;
            return;
        }
    }
    if(head->num>2){
        cur=pre->next;
        if(head->next->val==x){
            head->next=pre->next;
            pre->next=NULL;
            head->num--;
            return;
        }
        if(cur->val==x){
                pre->next=cur->next;
                cur->next=NULL;
                head->num--;
                return;
            }
        for(int j=0;j<head->num-2;j++){
            pre=pre->next;
            cur=pre->next;
            if(cur->val==x){
                pre->next=cur->next;
                cur->next=NULL;
                head->num--;
                return;
            }
        }
    }

}

//查找值为x的单链表

LinkListNode* FindXLinkList(LinkListHead* head,int x){
    if(!head||!head->num) return NULL;
    int i=1;
    LinkListNode* cur=head->next;
    while(cur){
        if(cur->val==x){
            printf("所要找的x的位置在第%d个\n",i);
            return cur;
        }
        cur=cur->next;
        i++;
    }

}

//将其中的x改为y
void changeXToY(LinkListHead* head,int x,int y){
    if(!head||!head->num) return;
    if(head->num==1){
        if(head->next->val==x){
            head->next->val=y;
            return;
        }
    }
    if(head->num>=2){
        LinkListNode* cur=head->next;
        while(cur){
            if(cur->val==x){
                cur->val=y;
                return;
            }
            cur=cur->next;
        }
    }
}

//清空单链表
bool clearLinkList(LinkListHead* head){
    if(!head||!head->num) return true;
    LinkListNode* cur=head->next;
    LinkListNode* next=cur->next;
    while(cur){
        free(cur);
        head->num--;
        cur=next;
        if(next) next=next->next;
    }
    head->next=NULL;
    if(!head->num) return true;
    return false;
}
//快慢指针，时间复杂度O(n)找到单链表的中中间节点
LinkListNode* findMiddle(LinkListHead* head){
    if(!head||!head->num) return NULL;
    if(head->num==1||head->num==2){
        printf("中间节点是%d\n",head->next->val);
        return head->next;
    }
    LinkListNode* fast=head->next;
    LinkListNode* slow=head->next;
    while(fast&&fast->next){     //当有一个不满足时变会停下
        fast=fast->next->next;
        slow=slow->next;
    }
    printf("中间节点是%d\n",slow->val);
    return slow;
}
int main(){
    LinkListHead* mylist=initLinkList();
    insertValueLinkedList(mylist,1,1);
    insertValueLinkedList(mylist,2,2);
    insertValueLinkedList(mylist,3,3);
    insertValueLinkedList(mylist,4,4);
    insertValueLinkedList(mylist,5,5);
    showLinkedList(mylist);
    puts("----------------------");
    delILinkedList(mylist,5);
//    delILinkedList(mylist,4);
//    delILinkedList(mylist,1);
    showLinkedList(mylist);
    puts("----------------------");
    delXLinkedList(mylist,1);
    showLinkedList(mylist);
    puts("----------------------");
    FindXLinkList(mylist,3);
    puts("----------------------");
    changeXToY(mylist,2,1);
    showLinkedList(mylist);
    puts("----------------------");
    insertValueLinkedList(mylist,1,1);
    insertValueLinkedList(mylist,2,2);
    insertValueLinkedList(mylist,3,3);
    insertValueLinkedList(mylist,4,4);
    insertValueLinkedList(mylist,5,5);
    showLinkedList(mylist);
    findMiddle(mylist);
    puts("----------------------");
    clearLinkList(mylist);
    showLinkedList(mylist);
    return 0;
}

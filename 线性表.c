#include<stdio.h>
#include<stdbool.h>
//#define maxSize 100
const int maxSize = 100;//推荐第二种写法
typedef struct {
    int num;//线性表中当前元素的个数
    int* arr;//存储数据的主体，大小是maxSize
}LinearList;
//线性表的初始化
LinearList* initLinearList(void){
    LinearList* list = (LinearList*)malloc(sizeof(LinearList));
    list->num = 0;
    list->arr =(int*)malloc(sizeof(int)*maxSize);//创建完成后数组为乱值
    //初始化数组
    for(int i=0;i<maxSize;i++){
        list->arr[i] = 0;
    }
    return list;
}

//在第i个位置插入x
bool insertList(LinearList* list, int i,int x){
    //判断
    if(!list || list->num == maxSize ||i<=0 ||i>list->num+1) return false;
    //从i-1下标的元素向后移一位
    for(int j=list->num-1;j>=i-1;j--){
        list->arr[j+1] = list->arr[j];
    }
    list->arr[i-1] = x;   //添加元素
    list->num++;  //元素个数增加
    return true;

}
//遍历顺序表
void showLinearList(LinearList* list){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    for(int i=0;i<list->num;i++){
        printf("第%d个元素为：%d\n",i,list->arr[i]);
    }
    return;
}
//删除x元素
void delLinearList(LinearList* list,int x){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    for(int i=0;i<list->num;i++){
        if(list->arr[i] != x) continue;
        else{
            for(;i<list->num-1;i++){
                list->arr[i]=list->arr[i+1];
            }
            list->num--;
        }

    }
}

//删除第i个元素
void deliLinearList(LinearList* list, int i){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    if(i-1>=0||i-1<list->num){
        for(int j=i-1;j<list->num;j++){
            list->arr[j]=list->arr[j+1];
        }
        list->num--;
    }
    else{
        puts("i溢出");
    }

}

//查找值为x的下标
int findIndexOfVlue(LinearList* list,int x){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    for(int i=0;i<list->num;i++){
        if(list->arr[i] != x) continue;
        else{
            return i;
            }
        }
}

//查找第i个元素
int findValueOfIndex(LinearList* list,int i){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    return list->arr[i-1];
}

//修改x到y
void changeXToYLinearList(LinearList* list,int x,int y){
    //判断
    if(list->num == 0) printf("列表为空");
    if(!list) printf("列表不存在");
    for(int i=0;i<list->num;i++){
        if(list->arr[i] == x){
            list->arr[i] = y;
        }
    }
}

int main(void){
    int x,y=0;
    LinearList* mylist = initLinearList();
    insertList(mylist,1,2);
    insertList(mylist,2,3);
    insertList(mylist,2,4);
    insertList(mylist,2,5);
    insertList(mylist,2,6);
    insertList(mylist,2,7);
    insertList(mylist,1,1);
    showLinearList(mylist);
    puts("-----------------------------");
    delLinearList(mylist,3);
    delLinearList(mylist,1);
    delLinearList(mylist,2);
    showLinearList(mylist);
    puts("-----------------------------");
    deliLinearList(mylist,2);
    showLinearList(mylist);
    x = findIndexOfVlue(mylist,5);
    printf("%d\n",x);
    y = findValueOfIndex(mylist,1);
    printf("%d\n",y);
    changeXToYLinearList(mylist,7,1);
    showLinearList(mylist);
    return 0;
}













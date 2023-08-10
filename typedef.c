#include <stdio.h>
typedef struct Student {
    int id;
    char name[100];
    char sex;
}St;


int main(){
    St student;
    student.id=2012;
    student.sex="man";
    printf("%d,%s",student.id,student.sex);

}

//(a)下面结构体类型的变量的内存布局是怎样的？
//请使用VS的debug模式展示内存布局并截图
//
//typedef struct stundent_s {
//    int number;
//    char name[25];
//    char gender;
//    int chinese;
//    int math;
//    int english;
//} Student;
//​
//Student s;
//(b)如何通过结构体获取成员，如何通过指向结构体的指针获取成员？
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int number;
    char name[25];
    char gender;
    int chinese;
    int math;
    int english;
} Student;

int main(void) {
    Student s;
    return 0;
    //(b)如何通过结构体获取成员，如何通过指向结构体的指针获取成员？
    s.chinese;//通过结构体获取成员
    Student *s1;//通过指向结构体的指针获取成员
    printf("%d", s1->chinese);




}



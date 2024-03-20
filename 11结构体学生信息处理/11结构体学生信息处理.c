//(学生信息处理)有这样一种学生结构体类型，其数据成员有包括学号，姓名和3门课程的成绩。
//实现下列功能：
//从键盘输入5个学生的信息，将这些同学的信息采用结构体数组的方式存储起来。
//输出每门课程最高分的学生信息。
//输出每门课程的平均分。
//按照总分从高到低对学生进行排序，并输出排序后的学生信息。
//（排序话自己写个选择或冒泡排序即可）

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SWAP(arr,a,b) {\
	Student* t=arr[a];\
	arr[a] = arr[b];\
	arr[b]=t;\
}

typedef struct student
{
	int number;
	char name[10];
	int chinese;
	int maths;
	int english;
}Student;

int higgest_score(Student* s) {
	//输出每个学生的最高成绩
	int higgest = s->chinese;
	for (int i = 0; i < 5; i++)
	{
		if (s[i].maths>higgest)
		{
			higgest = s[i].maths;
		}
		else if (s[i].english > higgest) {
			higgest = s[i].english;
			}
		printf("Student %s's higgest score is %d.\n", s[i].name, higgest);
	}
}

void avarage_score(Student* s) {
	//输出各科目的平均成绩
	int chinese_total_score = 0;
	int maths_total_score = 0;
	int english_total_score = 0;
	for (int i = 0; i < 5; i++)
	{
		chinese_total_score += s->chinese;
		maths_total_score += s->maths;
		english_total_score += s->english;
	}
	printf("Average Chinese score is %d.\n", chinese_total_score / 5);
	printf("Average Maths score is %d.\n", maths_total_score / 5);
	printf("Average English score is %d.\n", english_total_score / 5);
	
}

int total_score(Student* s) {
	//计算一个学生的总成绩
	return (s->chinese + s->maths + s->english);
}

void sort_score(Student* s[],int n) {
	//按照总分从高到低对学生进行排序，并输出排序后的学生信息
	for (int i = 0; i < n-1; i++)
	{
		int max_index = i;
		for (int j = i+1; j < n; j++)
		{
			if (total_score(s[j])>total_score(s[max_index]))
			{
				max_index = j;
			}
		}
		SWAP(s, i, max_index);
		printf("No.%d student's score is %d.\n", i + 1, total_score(s[max_index]));
	}

}
int main() {
	//定义存储5个学生信息的结构体数组
	Student students[5];

	for (int i = 0; i < 5; i++)
	{//输入五个学生信息
		scanf("%d%s%d%d%d",
			&students[i].number,
			students[i].name,
			&students[i].chinese,
			&students[i].maths,
			&students[i].english);

	}

	//指向结构体数组的指针数组
	Student* pstudents[5] = { students,students + 1,students + 2,students + 3,students + 4 };
	
	higgest_score(pstudents);
	avarage_score(pstudents);
	sort_score(pstudents,5);
	return 0;


}
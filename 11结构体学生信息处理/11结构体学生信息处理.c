//(ѧ����Ϣ����)������һ��ѧ���ṹ�����ͣ������ݳ�Ա�а���ѧ�ţ�������3�ſγ̵ĳɼ���
//ʵ�����й��ܣ�
//�Ӽ�������5��ѧ������Ϣ������Щͬѧ����Ϣ���ýṹ������ķ�ʽ�洢������
//���ÿ�ſγ���߷ֵ�ѧ����Ϣ��
//���ÿ�ſγ̵�ƽ���֡�
//�����ִܷӸߵ��Ͷ�ѧ���������򣬲����������ѧ����Ϣ��
//�������Լ�д��ѡ���ð�����򼴿ɣ�

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
	//���ÿ��ѧ������߳ɼ�
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
	//�������Ŀ��ƽ���ɼ�
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
	//����һ��ѧ�����ܳɼ�
	return (s->chinese + s->maths + s->english);
}

void sort_score(Student* s[],int n) {
	//�����ִܷӸߵ��Ͷ�ѧ���������򣬲����������ѧ����Ϣ
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
	//����洢5��ѧ����Ϣ�Ľṹ������
	Student students[5];

	for (int i = 0; i < 5; i++)
	{//�������ѧ����Ϣ
		scanf("%d%s%d%d%d",
			&students[i].number,
			students[i].name,
			&students[i].chinese,
			&students[i].maths,
			&students[i].english);

	}

	//ָ��ṹ�������ָ������
	Student* pstudents[5] = { students,students + 1,students + 2,students + 3,students + 4 };
	
	higgest_score(pstudents);
	avarage_score(pstudents);
	sort_score(pstudents,5);
	return 0;


}
//��������������Ԫ�غ͵ڶ����Ԫ�أ��������Ƿֱ������� largest �� second_largest ָ��ı����С�
//
//void find_two_largest(int arr[], int n, int* largest, int* second_largest);
//ע�⣺
//Ϊ�˼򻯳������鲻�����ظ�Ԫ�ء�

#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void find_two_largest(int arr[], int n, int* largest, int* second_largest) {
	* largest = arr[0];
	* second_largest = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>*largest)
		{
			*largest = arr[i];
		}
		else if (arr[i]>*second_largest)
		{
			*second_largest = arr[i];
		}
		
	}
}

int main() {
	int arr[] = { 9,5,6,0,8,4,3,2,55,669,88,12,35,65 };
	int largest, secondlargest;
	find_two_largest(arr, SIZE(arr), &largest, &secondlargest);
	printf("The largest one is %d, the second_largest one is %d.\n", largest, secondlargest);
	return 0;
}
//查找数组中最大的元素和第二大的元素，并将它们分别存放在由 largest 和 second_largest 指向的变量中。
//
//void find_two_largest(int arr[], int n, int* largest, int* second_largest);
//注意：
//为了简化程序，数组不存在重复元素。

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
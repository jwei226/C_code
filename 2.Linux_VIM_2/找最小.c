//假定一个数组有 n 个元素，这 n 个元素各不相同，
//并且循环有序，请找出最小的那个元素。
//int findMin(int arr[], int n);
//
//示例1：
//输入：[3, 4, 5, 1, 2]
//输出：1
//
//示例2：
//输入：[4, 5, 6, 7, 0, 1, 2]
//输出：0
//​
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SWAP(a,b) {\
		int temp = a;\
		a=b;\
		b=temp;\
}

void qsort_Y(int q[], int l, int r) {
	//大雪菜版本
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
	while (i < j) {
		do i++; while (q[i] < x);//向右找到>x的数停在那里
		do j--; while (q[j] > x);
		if (i < j) SWAP(q[i], q[j]);
	}
	qsort_Y(q, l, j), qsort_Y(q, j + 1, r);
}

int findMin(int arr[], int n) {
	qsort_Y(arr, 0, n-1);
	return arr[0];
}
int main() {
	int arr1[] = { 3, 4, 5, 1, 2 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("Original array is: \n");
	for (int i = 0; i < n1; i++) {
		printf("%d  ", arr1[i]);
	}
	int min1 = findMin(arr1, n1);
	printf("\nSorted array is: \n");
	for (int i = 0; i < n1; i++) {
		printf("%d  ", arr1[i]);
	}
	printf("\nMin number is：%d\n", min1);

	return 0;
}
//a.����һ�������е�kС��Ԫ��(˼��: �ܷ�ʱ�临�ӶȽ��͵�O(n)��)
//
//int find_kth_minimum(int arr[], int n, int k);
//b.����һ���������飬��������λ��
//
//int find_median(int arr[], int n);
//
//���룺[3, 1, 2]
//�����2
//
//����[4, 1, 3, 2]
//�����2
#include<stdio.h>
#define SWAP(a,b) {\
		int temp = a;\
		a=b;\
		b=temp;\
}


void quicksort(int arr[], int l, int r) {
	//����
	if (l >= r) return;
	int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
	while (i < j) {
		do i++; while (arr[i] < x); 
		do j--; while (arr[j] > x);
		if (i < j) SWAP(arr[i], arr[j]);
	}
	quicksort(arr, l, j), quicksort(arr, j + 1, r);
}

int find_kth_minimun(int arr[], int n, int k) {
	//���������е�kС��Ԫ��
	quicksort(arr, 0, n);
	return arr[k];

}
int main() {
	int arr[]= { 16, 11, 45, 23, 99, 2, 18, 67, 42, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array is: \n");
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	int k = 3;
	printf("\nSorted array is: \n");
	int result = find_kth_minimun(arr, n-1, k-1);
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\nThe %d number is %d.\n", k, result);
	return 0;
}

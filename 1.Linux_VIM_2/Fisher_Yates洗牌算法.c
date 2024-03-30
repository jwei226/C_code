//给定一个排好序的数组，请设计一个算法将数组随机打乱。
//
//void shuffle(int arr[], int n)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int arr[], int n) {
	srand(time);
	for (int i = 0; i < n; i++) {
		int j = rand() % (n + 1);
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int main() {
	int arr[20] = { 0 };
	for (int i = 0; i < 20; i++) {
		arr[i] = i;
	}
	int n = 20;
	printf("Original array is: \n");
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	shuffle(arr, n);
	printf("\nShuffle array is: \n");
	for (int i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	return 0;
}
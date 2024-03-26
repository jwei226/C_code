#include"Sort.h"
#include<stdio.h>

int main() {
	int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Original array is: \n");
	for (int i = 0; i < n; i++) {
		printf("%5d",arr[i]);
	}
	printf("\n*****************************************************\n");
	/*select_sort(arr, n);
	printf("\nSelect sorted: ");*/
	/*bubble_sort(arr, n);
	printf("\nBubble sorted: ");*/
	/*insert_sort(arr, n);
	printf("\nInsert sorted: ");*/
	/*shell_sort(arr, n);
	printf("\nShell sorted: ");*/
	/*merge_sort(arr, n);
	printf("\nMerge sorted: ");*/
	/*qsort_Y(arr, 0, 9);
	printf("\nQuick sorted: ");*/
	/*quick_sort(arr, n);
	printf("\nQuick sorted: ");*/
	heap_sort(arr, n);
	printf("\nHeap sorted: ");

	for (int i = 0; i < n; i++) {
		printf("%d  ",arr[i]);
	}

	return 0;
}
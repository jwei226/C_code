#include<stdio.h>
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
int binary_search1(int arr[], int n, int key) {
	//循环二分查找
	int left = 0;
	int right = n - 1;
	
	
	while (left <= right) {
		int mid = left + (right - left >> 1);
		int cmp = key - arr[mid];
		if (cmp < 0) {
			//key < arr[mid]落在左区间
			right = mid - 1;
		}
		else if (cmp > 0) {
			//key > arr[mid]落在右区间
			left = mid + 1;
		}
		else return mid;
	}
	return -1;//没找到
}

int search(int arr[], int l, int r, int key) {
	//在闭区间[l, r]上二分查找key值
	if (l > r) return -1;
	int mid = l + (r - l >> 1);
	int cmp = key - arr[mid];
	if (cmp < 0) return search(arr, l, mid - 1, key);
	if (cmp > 0) return search(arr, mid + 1, r, key);
}
int binary_search2(int arr[], int n, int key) {
	//递归二分查找
	return search(arr, 0, n - 1, key);
}

//二分查找变种
int search_first_key(int arr[], int n, int key) {
	//查找第一个与 key 相等的元素
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l >> 1);
		int cmp = key - arr[mid];
		if (cmp > 0) {//去右区间key > arr[mid]
			r = mid - 1;
		}
		else if (cmp < 0) {
			l = mid + 1;
		}
		else {//找到为key值的元素
			//若前一个元素小于key则是第一个与key值相等的元素
			if (mid == l || arr[mid - 1] < key) {
				return mid;
			}//继续往前
			r = mid - 1;
			
		}
	}//没找到与key值相等的元素
	return -1;
}

//二分查找变种二
int search_last_key(int arr[], int n, int key) {
	//查找最后一个与key值相等的元素
	int l = 0, r = n - 1;
	while (r >= l) {
		int m = l + (r - l >> 1);
		int cmp = arr[m] - key;
		if (cmp > 0) {
			r = m - 1;
		}
		else if (cmp < 0) {
			l = m + 1;
		}
		else {
			if (m == r || arr[m + 1] > key) {
				return m;
			}
			l = m + 1;
		}
	}
	return -1;
}

//二分查找变种
int search_first_more_than_key(int arr[], int n, int key) {
	//查找第一个大于等于 key 值的元素
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l >> 1);
		int cmp =  arr[m]-key;
		if (cmp < 0) {//去右区间arr[m]<key
			l = m + 1;
		}else {
			if (m == l || arr[m - 1] < key) {
				return m;
			}
			r = m - 1;
	}

}

int search_last_less_than_key(int arr[], int n, int key) {
	//查找最后一个小于等于 key 值的元素
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l >> 1);
		int cmp = arr[m] - key;
		if (cmp > 0) {//去左区间arr[m]>key
			r = m - 1;
		}
		else {
			if (m == r || arr[m + 1] > key) {
				return m;
			}
			l = m + 1;
		}
}
int main() {
	int arr[] = { 1,2,5,5,5,5,5,6,8,9,10,25,65 };
	
	int idx1= binary_search1(arr, SIZE(arr), 6);
	printf("%d\n", idx1);// 7
	int idx2 = binary_search2(arr, SIZE(arr), 8);
	printf("%d\n", idx2);// 8
	printf("********************\n");
	//查找第一个与key值相等的元素
	int idx3 = search_first_key(arr, SIZE(arr), 5);
	printf("%d\n", idx3);// 2

	//查找最后一个与key值相等的元素
	int idx4 = search_last_key(arr, SIZE(arr), 5);
	printf("%d\n", idx4);// 6

	//查找第一个大于等于 key 值的元素
	int idx5 = search_first_more_than_key(arr, SIZE(arr), 2);
	printf("%d\n", idx5);// 2

	//查找最后一个小于等于 key 值的元素
	int idx6 = search_first_more_than_key(arr, SIZE(arr), 6);
	printf("%d\n", idx6);// 6

	return 0;
}
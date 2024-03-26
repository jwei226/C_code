#include<stdio.h>
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
int binary_search1(int arr[], int n, int key) {
	//ѭ�����ֲ���
	int left = 0;
	int right = n - 1;
	
	
	while (left <= right) {
		int mid = left + (right - left >> 1);
		int cmp = key - arr[mid];
		if (cmp < 0) {
			//key < arr[mid]����������
			right = mid - 1;
		}
		else if (cmp > 0) {
			//key > arr[mid]����������
			left = mid + 1;
		}
		else return mid;
	}
	return -1;//û�ҵ�
}

int search(int arr[], int l, int r, int key) {
	//�ڱ�����[l, r]�϶��ֲ���keyֵ
	if (l > r) return -1;
	int mid = l + (r - l >> 1);
	int cmp = key - arr[mid];
	if (cmp < 0) return search(arr, l, mid - 1, key);
	if (cmp > 0) return search(arr, mid + 1, r, key);
}
int binary_search2(int arr[], int n, int key) {
	//�ݹ���ֲ���
	return search(arr, 0, n - 1, key);
}

//���ֲ��ұ���
int search_first_key(int arr[], int n, int key) {
	//���ҵ�һ���� key ��ȵ�Ԫ��
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l >> 1);
		int cmp = key - arr[mid];
		if (cmp > 0) {//ȥ������key > arr[mid]
			r = mid - 1;
		}
		else if (cmp < 0) {
			l = mid + 1;
		}
		else {//�ҵ�Ϊkeyֵ��Ԫ��
			//��ǰһ��Ԫ��С��key���ǵ�һ����keyֵ��ȵ�Ԫ��
			if (mid == l || arr[mid - 1] < key) {
				return mid;
			}//������ǰ
			r = mid - 1;
			
		}
	}//û�ҵ���keyֵ��ȵ�Ԫ��
	return -1;
}

//���ֲ��ұ��ֶ�
int search_last_key(int arr[], int n, int key) {
	//�������һ����keyֵ��ȵ�Ԫ��
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

//���ֲ��ұ���
int search_first_more_than_key(int arr[], int n, int key) {
	//���ҵ�һ�����ڵ��� key ֵ��Ԫ��
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l >> 1);
		int cmp =  arr[m]-key;
		if (cmp < 0) {//ȥ������arr[m]<key
			l = m + 1;
		}else {
			if (m == l || arr[m - 1] < key) {
				return m;
			}
			r = m - 1;
	}

}

int search_last_less_than_key(int arr[], int n, int key) {
	//�������һ��С�ڵ��� key ֵ��Ԫ��
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l >> 1);
		int cmp = arr[m] - key;
		if (cmp > 0) {//ȥ������arr[m]>key
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
	//���ҵ�һ����keyֵ��ȵ�Ԫ��
	int idx3 = search_first_key(arr, SIZE(arr), 5);
	printf("%d\n", idx3);// 2

	//�������һ����keyֵ��ȵ�Ԫ��
	int idx4 = search_last_key(arr, SIZE(arr), 5);
	printf("%d\n", idx4);// 6

	//���ҵ�һ�����ڵ��� key ֵ��Ԫ��
	int idx5 = search_first_more_than_key(arr, SIZE(arr), 2);
	printf("%d\n", idx5);// 2

	//�������һ��С�ڵ��� key ֵ��Ԫ��
	int idx6 = search_first_more_than_key(arr, SIZE(arr), 6);
	printf("%d\n", idx6);// 6

	return 0;
}
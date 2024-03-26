#include<stdio.h>
#include<stdbool.h>

#define SWAP(a,b) {\
		int temp = a;\
		a=b;\
		b=temp;\
}


void array_print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");
}

//简单选择排序
void select_sort(int s[],int n){
	for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (s[j] < s[min]) min = j;
		}
		//把最小值更新到已排序序列中
		if(s[i] > s[min]) SWAP(s[min], s[i]);//或i!=min
		array_print(s, n);
	}
}


//冒泡排序
void bubble_sort(int b[],int n) {
	for (int i = 0; i < n; i++) {
		bool swap = false;
		for (int j = 1; j < n; j++) {
			if (b[j] < b[j-1]) {//若为j+1，注意数组越界
				SWAP(b[j], b[j - 1]);
				swap = true;
			}
			 
		}
		if (!swap) return;
		array_print(b, n);
	}
}

//插入排序
void insert_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int value = a[i];//待插入元素
		while (j >= 0 && a[j] > value) {
			a[j + 1] = a[j];
			j--;
		}//空出待插入位置
		a[j+1] = value;
		array_print(a, n);
	}
}

//希尔排序
void shell_sort(int s[], int n) {
	int gap = n / 2;
	while(gap>0){
		for (int i = gap; i < n; i++) {
			int value = s[i];//存储插入值
			int j = i - gap;//相隔前一个间隔
			while (j >= 0 && s[j] > value) {
				s[j+gap] = s[j];
				j -= gap;//继续往前比较
			}
		}
		gap /= 2;
		array_print(s, n);
	}
	
}

//归并排序,递归
int tmp[10];//声明全局变量用于复制原数组
void merge(int arr[], int left, int right, int n) {
	//合并两个有序数组[left, mid]和[mid+1,right]
	int mid = left + ((right - left) >> 1);
	int i = left;//左区间对头元素
	int j = mid + 1;//右区间队头元素
	int tmp_idx = left;//tmp数组的索引
	while (i <= mid && j <= right) {
		//左右区间都有元素
		if (arr[i] <= arr[j]) {
			tmp[tmp_idx++] = arr[i++];
		}
		else if (arr[j] <= arr[i]) {
			tmp[tmp_idx++] = arr[j++];
		}
	}
	while (i <= mid) tmp[tmp_idx++] = arr[i++];
	while (j <= right) tmp[tmp_idx++] = arr[j++];
	//将排序后的元素复制到原数组中
	for (int idx = left; idx <= right; idx++) {
		arr[idx] = tmp[idx];
	}

}

void msort(int arr[], int left, int right, int n) {
	//边界条件
	if (left >= right) return;
	//递归公式
	int mid = left + ((right - left) >> 1);
	msort(arr, left, mid, n);
	msort(arr, mid + 1, right, n);
	merge(arr, left, mid, right);
	array_print(arr, n);
}
void merge_sort(int m[],int n) {
	//归并排序,递归
	msort(m, 0, n - 1, n);
	
}
//快速排序，分治，递归
void qsort_Y(int q[],int l,int r) {
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

//花生老师
//快速排序

int partion(int  arr[], int left, int right) {
	//分区，返回[left,right]区间
	int i = left;
	int j = right;
	int pivot = arr[left + ((right - left) >> 1)];//基准值
	while (i < j) {
		while (i < j && arr[j] >= pivot) j--;	
		arr[i] = arr[j];
		
		while (i < j && arr[i] <= pivot) i++;
		arr[j] = arr[i];
		
	}
	arr[i] = pivot;
	
	return i;
}
void qsort(int arr[], int left, int right) {
	//边界条件
	if (left >= right) return;
	//递归公式
	int idx = partion(arr, left, right);
	
	qsort(arr, left, idx - 1);
	qsort(arr, idx + 1, right);
	array_print(arr, 10);
}
void quick_sort(int arr[], int n) {
	qsort(arr, 0, n - 1);

}

//堆排序
void heapify(int arr[],int i, int len) {
	//调整为大顶堆,i为根结点索引
	while (i < len) {
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		// 求根结点，左子树和右子树的最大值
		int maxIdx = i;
		if (lchild < len && arr[lchild] > arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < len && arr[rchild] > arr[maxIdx]) {
			maxIdx = rchild;
		}

		if (maxIdx == i) return;
		// 交换根结点i和maxIdx的值
		SWAP(arr[i], arr[maxIdx]);
		// 将i往下移动大maxIdx的位置
		i = maxIdx;
	}
}
void heap_create(int arr[], int n) {
	//构建大顶堆，找第一个非叶子结点
	/*int lchild = 2 * i + 1;*/
	//lchild<=n-1
	for (int i = n - 2 >> 1; i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n) {
	int len = n;//无序区长度
	heap_create(arr,n);
	array_print(arr, n);
	while (len > 1) {
		SWAP(arr[0], arr[len - 1]);//逻辑上删除堆顶最大元素
		len--;
		heapify(arr, 0, len);
		array_print(arr, n);
	}
}

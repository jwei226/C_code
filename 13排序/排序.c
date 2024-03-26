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

//��ѡ������
void select_sort(int s[],int n){
	for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (s[j] < s[min]) min = j;
		}
		//����Сֵ���µ�������������
		if(s[i] > s[min]) SWAP(s[min], s[i]);//��i!=min
		array_print(s, n);
	}
}


//ð������
void bubble_sort(int b[],int n) {
	for (int i = 0; i < n; i++) {
		bool swap = false;
		for (int j = 1; j < n; j++) {
			if (b[j] < b[j-1]) {//��Ϊj+1��ע������Խ��
				SWAP(b[j], b[j - 1]);
				swap = true;
			}
			 
		}
		if (!swap) return;
		array_print(b, n);
	}
}

//��������
void insert_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int value = a[i];//������Ԫ��
		while (j >= 0 && a[j] > value) {
			a[j + 1] = a[j];
			j--;
		}//�ճ�������λ��
		a[j+1] = value;
		array_print(a, n);
	}
}

//ϣ������
void shell_sort(int s[], int n) {
	int gap = n / 2;
	while(gap>0){
		for (int i = gap; i < n; i++) {
			int value = s[i];//�洢����ֵ
			int j = i - gap;//���ǰһ�����
			while (j >= 0 && s[j] > value) {
				s[j+gap] = s[j];
				j -= gap;//������ǰ�Ƚ�
			}
		}
		gap /= 2;
		array_print(s, n);
	}
	
}

//�鲢����,�ݹ�
int tmp[10];//����ȫ�ֱ������ڸ���ԭ����
void merge(int arr[], int left, int right, int n) {
	//�ϲ�������������[left, mid]��[mid+1,right]
	int mid = left + ((right - left) >> 1);
	int i = left;//�������ͷԪ��
	int j = mid + 1;//�������ͷԪ��
	int tmp_idx = left;//tmp���������
	while (i <= mid && j <= right) {
		//�������䶼��Ԫ��
		if (arr[i] <= arr[j]) {
			tmp[tmp_idx++] = arr[i++];
		}
		else if (arr[j] <= arr[i]) {
			tmp[tmp_idx++] = arr[j++];
		}
	}
	while (i <= mid) tmp[tmp_idx++] = arr[i++];
	while (j <= right) tmp[tmp_idx++] = arr[j++];
	//��������Ԫ�ظ��Ƶ�ԭ������
	for (int idx = left; idx <= right; idx++) {
		arr[idx] = tmp[idx];
	}

}

void msort(int arr[], int left, int right, int n) {
	//�߽�����
	if (left >= right) return;
	//�ݹ鹫ʽ
	int mid = left + ((right - left) >> 1);
	msort(arr, left, mid, n);
	msort(arr, mid + 1, right, n);
	merge(arr, left, mid, right);
	array_print(arr, n);
}
void merge_sort(int m[],int n) {
	//�鲢����,�ݹ�
	msort(m, 0, n - 1, n);
	
}
//�������򣬷��Σ��ݹ�
void qsort_Y(int q[],int l,int r) {
	//��ѩ�˰汾
	if (l >= r) return;

	int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
	while (i < j) {
		do i++; while (q[i] < x);//�����ҵ�>x����ͣ������
		do j--; while (q[j] > x);
		if (i < j) SWAP(q[i], q[j]);
	}
	qsort_Y(q, l, j), qsort_Y(q, j + 1, r);
}

//������ʦ
//��������

int partion(int  arr[], int left, int right) {
	//����������[left,right]����
	int i = left;
	int j = right;
	int pivot = arr[left + ((right - left) >> 1)];//��׼ֵ
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
	//�߽�����
	if (left >= right) return;
	//�ݹ鹫ʽ
	int idx = partion(arr, left, right);
	
	qsort(arr, left, idx - 1);
	qsort(arr, idx + 1, right);
	array_print(arr, 10);
}
void quick_sort(int arr[], int n) {
	qsort(arr, 0, n - 1);

}

//������
void heapify(int arr[],int i, int len) {
	//����Ϊ�󶥶�,iΪ���������
	while (i < len) {
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		// �����㣬�������������������ֵ
		int maxIdx = i;
		if (lchild < len && arr[lchild] > arr[maxIdx]) {
			maxIdx = lchild;
		}
		if (rchild < len && arr[rchild] > arr[maxIdx]) {
			maxIdx = rchild;
		}

		if (maxIdx == i) return;
		// ���������i��maxIdx��ֵ
		SWAP(arr[i], arr[maxIdx]);
		// ��i�����ƶ���maxIdx��λ��
		i = maxIdx;
	}
}
void heap_create(int arr[], int n) {
	//�����󶥶ѣ��ҵ�һ����Ҷ�ӽ��
	/*int lchild = 2 * i + 1;*/
	//lchild<=n-1
	for (int i = n - 2 >> 1; i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heap_sort(int arr[], int n) {
	int len = n;//����������
	heap_create(arr,n);
	array_print(arr, n);
	while (len > 1) {
		SWAP(arr[0], arr[len - 1]);//�߼���ɾ���Ѷ����Ԫ��
		len--;
		heapify(arr, 0, len);
		array_print(arr, n);
	}
}

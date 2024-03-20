//有三根杆子A，B，C。A杆上有 N 个(N > 1) 穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至 C 杆：
//
//1. 每次只能移动一个圆盘;
//2. 大盘不能叠在小盘上面。
//
//提示：可将圆盘临时置于 B 杆，也可将从 A 杆移出的圆盘重新移回 A 杆，但都必须遵循上述两条规则。
//
//问：最少需要移动多少次？如何移？

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int hanoi(char start, char middle, char target, int n) {
	//边界条件
	if (n == 1) {
		printf("%c --> %c\n", start, target);
		return;
	}
	//递归公式
	hanoi(start, target, middle, n - 1);
	printf("%c --> %c\n", start, target);
	hanoi(middle, start, target, n - 1);
}
int main() {
	int n;
	printf("n = " );
	scanf("%d", &n);
	hanoi('A', 'B', 'C', n);
	printf("total steps: %d\n", (1 << n) - 1);
	return 0;

}
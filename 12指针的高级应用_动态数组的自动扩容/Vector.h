typedef int E;

typedef struct {
    E* elements;   // 指向堆空间的数组
    int size;	// 元素的个数
    int capacity; // 数组的容量
} Vector;

//创建空的动态数组
Vector* vector_create(void);

void push_back(Vector* v, E val);
// 在数组最前面添加元素，所有元素依次后移
void push_front(Vector* v, E val);
// 删除最后一个元素, 并把最后一个元素返回
E pop_back(Vector* v);
// 删除第一个元素，并把第一个元素返回
E pop_front(Vector* v);

void vector_destroy(Vector* v);
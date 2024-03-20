typedef int E;

typedef struct {
    E* elements;   // ָ��ѿռ������
    int size;	// Ԫ�صĸ���
    int capacity; // ���������
} Vector;

//�����յĶ�̬����
Vector* vector_create(void);

void push_back(Vector* v, E val);
// ��������ǰ�����Ԫ�أ�����Ԫ�����κ���
void push_front(Vector* v, E val);
// ɾ�����һ��Ԫ��, �������һ��Ԫ�ط���
E pop_back(Vector* v);
// ɾ����һ��Ԫ�أ����ѵ�һ��Ԫ�ط���
E pop_front(Vector* v);

void vector_destroy(Vector* v);
#include"BitMap.h"
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

#define BITMAP_SHIFT 5//λ����������5λ����λ����תΪ������
#define BITMAP_PER_WORD 32//ÿ���ֽ�(Ԫ��)�ܴ��λ��
#define BITMAP_SIZE(bits) ((bits+BITMAP_PER_WORD-1)>>BITMAP_SHIFT)
//��bitsλ����Ҫ���ֽ���������ȡ���ٳ���32
#define BITMAP_MASK 31//0b00000000000000000000000000011111��&�ɵ�offset

BitMap* bitmap_create(size_t bits){
	//����һ��λͼ
	//��̬�����ڴ�ռ�
	BitMap* bm = malloc(bits * sizeof(BitMap));
	//��ʼ��
	bm->bits = bits;

	//Ҫ����
	bm->array = calloc(BITMAP_SIZE(bits) , sizeof(uint32_t));
	
	return bm;
}

void bitmap_destroy(BitMap* bm) {
	//����λͼ
	//���ͷ�����,���ͷŽṹ��
	free(bm->array);
	free(bm);
	
}


void bitmap_expand(BitMap* bm, size_t bits) {
	//���ݣ�bitsΪҪ���ݵ�λ��
	//���·����µ��ڴ�ռ�
	bm->array = realloc(bm->array, BITMAP_SIZE(bits) * sizeof(uint32_t));
	int expand = (BITMAP_SIZE(bits) - BITMAP_SIZE(bm->bits)) * sizeof(uint32_t);
	memset(bm->array + BITMAP_SIZE(bm->bits), 0, expand);//����ʼ��ַ��expand�ֽ�������


}
void bitmap_set(BitMap* bm, size_t n) {
	//���Ԫ�أ�������Ϊn��λ��Ϊ1
	//�ж��Ƿ���Ҫ����
	if (BITMAP_SIZE(n + 1) > BITMAP_SIZE(bm->bits)) {
		bitmap_expand(bm, n + 1);
	}
	//�ҵ�λ���ĸ�λ(word,offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//��(word,offset)λ��1,1����offset�ٺ͸�λ��λ��
	bm->array[word] |= (0x1 << offset);
}

void bitmap_unset(BitMap* bm, size_t n) {
	//ɾ��Ԫ�أ�������Ϊn��λ��0
	//�ж��Ƿ񳬳�λͼ�ķ�Χ
	if (n >= bm->bits) return;
	//�ҵ�����Ϊn��λ(word,offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//��0,0x1 << offset��offset��Ϊ1����λΪ0������,��λ��Ǻ�����
	bm->array[word] &= ~(0x1 << offset);


}

bool bitmap_isset(BitMap* bm, size_t n) {
	//��������Ϊn��λ�Ƿ�Ϊ1
	//�ж�n�Ƿ�λͼ��Χ
	if (n >= bm->bits) return;
	//�ҵ���λ
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//
	return bm->array[word] & (0x1 << offset);
}

void bitmap_clear(BitMap* bm) {
	//ȫ��Ϊ0
	memset(bm->array, 0, BITMAP_SIZE(bm->bits) * sizeof(uint32_t));
}
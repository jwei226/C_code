#include"BitMap.h"
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

#define BITMAP_SHIFT 5//位移量，右移5位，将位索引转为字索引
#define BITMAP_PER_WORD 32//每个字节(元素)能存的位数
#define BITMAP_SIZE(bits) ((bits+BITMAP_PER_WORD-1)>>BITMAP_SHIFT)
//存bits位所需要的字节数，向上取整再除以32
#define BITMAP_MASK 31//0b00000000000000000000000000011111，&可得offset

BitMap* bitmap_create(size_t bits){
	//创建一个位图
	//动态申请内存空间
	BitMap* bm = malloc(bits * sizeof(BitMap));
	//初始化
	bm->bits = bits;

	//要清零
	bm->array = calloc(BITMAP_SIZE(bits) , sizeof(uint32_t));
	
	return bm;
}

void bitmap_destroy(BitMap* bm) {
	//销毁位图
	//先释放数组,再释放结构体
	free(bm->array);
	free(bm);
	
}


void bitmap_expand(BitMap* bm, size_t bits) {
	//扩容，bits为要扩容的位数
	//重新分配新的内存空间
	bm->array = realloc(bm->array, BITMAP_SIZE(bits) * sizeof(uint32_t));
	int expand = (BITMAP_SIZE(bits) - BITMAP_SIZE(bm->bits)) * sizeof(uint32_t);
	memset(bm->array + BITMAP_SIZE(bm->bits), 0, expand);//从起始地址将expand字节数清零


}
void bitmap_set(BitMap* bm, size_t n) {
	//添加元素，将索引为n的位置为1
	//判断是否需要扩容
	if (BITMAP_SIZE(n + 1) > BITMAP_SIZE(bm->bits)) {
		bitmap_expand(bm, n + 1);
	}
	//找到位于哪个位(word,offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//将(word,offset)位置1,1左移offset再和该位按位或
	bm->array[word] |= (0x1 << offset);
}

void bitmap_unset(BitMap* bm, size_t n) {
	//删除元素，将索引为n的位置0
	//判断是否超出位图的范围
	if (n >= bm->bits) return;
	//找到索引为n的位(word,offset)
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//置0,0x1 << offset是offset处为1其余位为0的掩码,按位与非后清零
	bm->array[word] &= ~(0x1 << offset);


}

bool bitmap_isset(BitMap* bm, size_t n) {
	//查找索引为n的位是否为1
	//判断n是否超位图范围
	if (n >= bm->bits) return;
	//找到该位
	size_t word = n >> BITMAP_SHIFT;
	size_t offset = n & BITMAP_MASK;
	//
	return bm->array[word] & (0x1 << offset);
}

void bitmap_clear(BitMap* bm) {
	//全置为0
	memset(bm->array, 0, BITMAP_SIZE(bm->bits) * sizeof(uint32_t));
}
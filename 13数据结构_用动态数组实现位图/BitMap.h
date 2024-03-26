#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

typedef struct {
	uint32_t* array;
	size_t bits;
}BitMap;

//要实现的API
BitMap* bitmap_create(size_t bits);
void bitmap_destroy(BitMap* bm);
void bitmap_set(BitMap* bm, size_t n);
void bitmap_unset(BitMap* bm, size_t n);
bool bitmap_isset(BitMap* bm, size_t n);
void bitmap_clear(BitMap* bm);
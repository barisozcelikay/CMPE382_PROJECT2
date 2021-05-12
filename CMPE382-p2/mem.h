#ifndef MEM_H_
#define MEM_H_

#include<stdio.h>
#include<stddef.h>

struct block{
 size_t size;
 int free; // 1 if area is free 0 if it is not
 int init;
 struct block *next_block;

};

void Mem_Init(int sizeOfRegion);
struct block TEDU_alloc(size_t byte_size);
int TEDU_Free(struct block *ptr);

void TEDU_split(struct block *fitting_slot,size_t _size);
void TEDU_merge();


int Mem_IsValid(struct block *ptr);
int Mem_GetSize(struct block *ptr);
int TEDU_GetStats();


#endif // MEM_H_

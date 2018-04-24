#pragma once

typedef struct heap_s heap_t;

heap_t *createHeap();
char insert(heap_t* h,int val);
int minimum(heap_t* h);
char extractMin(heap_t *h);
char getError(heap_t *h);
char* toString(heap_t *h);
void destroyHeap(heap_t *h);
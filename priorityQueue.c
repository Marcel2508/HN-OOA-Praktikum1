#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <priorityQueue.h>

struct pqentry_s {
    char *data;
    float priority;
}

struct priorityqueue_s {
    pqentry_t* arr;
    int size;
    int count;
    char error;
};

/// STATIC METHODS:
static int getHeapGrowSize(priorityqueue_t *h){
    if(h->size==0)return 7;
    else return h->size*2+1;
}
static int getHeapShrinkSize(priorityqueue_t *h){
    if(h->size<=7){
        h->error=1;
        return 7;
    }
    else{
        return (h->size-1)/2;
    }
}
static void growHeap(heap_t *h){
    h->size=getHeapGrowSize(h);
    h->arr = (int*)realloc(h->arr,h->size*sizeof(int));
}
static void shrinkHeap(heap_t *h){
    h->size=getHeapShrinkSize(h);
    h->arr = (int*)realloc(h->arr,h->size*sizeof(int));
}

static void versickern(heap_t *h,int pos){
    int l = 0;int r=0; int x=0;
    if((r=2*pos+2)<h->count&&h->arr[r]<h->arr[pos]){
        x = h->arr[r];
        h->arr[r] = h->arr[pos];
        versickern(h,pos);
        versickern(h,r);
    }
    else if((l=2*pos+2)<h->count&&h->arr[l]<h->arr[pos]){
        x = h->arr[l];
        h->arr[l] = h->arr[pos];
        versickern(h,pos);
        versickern(h,l);
    }
}

static void aufsteigen(heap_t *h,int pos){
    int p = 0;int x=0;
    if((p=(pos-1)/2)>=0){
        if(h->arr[p]>h->arr[pos]){
            x=h->arr[pos];
            h->arr[pos]=h->arr[p];
            h->arr[p]=x;
            aufsteigen(h,p);
            aufsteigen(h,pos);
        }
    }
}
///


priorityqueue_t* pqueue_create(){
    priorityqueue_t *new = (priorityqueue_t*)calloc(sizeof(priorityqueue_t));
    new->arr = (int*)calloc(7*sizeof(pqentry_t));
    new->size=7;
    new->count=0;
    return new;
}
void pqueue_insert(priorityqueue_t *pq, char* value, float p){
    pqentry_t* newEntry = calloc(sizeof(pqentry_t));
    newEntry->data=value;
    newEntry->priority=p;
    
}
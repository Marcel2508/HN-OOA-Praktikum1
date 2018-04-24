#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

struct heap_s {
    int *arr;
    int size;
    int count;
    char error;
};

static int getHeapGrowSize(heap_t *h){
    if(h->size==0)return 7;
    else return h->size*2+1;
}
static int getHeapShrinkSize(heap_t *h){
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

heap_t* createHeap(){
    heap_t *temp = (heap_t*)malloc(sizeof(heap_t));
    temp->error=0;
    temp->arr = (int*)malloc(7);
    //growHeap(temp);
    temp->count=0;
    return temp;
}

char insert(heap_t *h,int val){   
    h->arr[h->count]=val;
    aufsteigen(h,h->count++);
    growHeap(h);
}

int minimum(heap_t *h){
    printf("MIN: %d\n",h->arr[0]);
    if(h->count>0)return h->arr[0];
    else{
        h->error=2;
        return -1;
    }
}

char extractMin(heap_t *h){
    printf("Extract\n");
    minimum(h);
    if(h->count>0){
        h->arr[0] = h->arr[(--(h->count))];
        minimum(h);
        //if(h->count<h->size/2)shrinkHeap(h);
        versickern(h,0);
        return 0;
    }
    else{
        h->error=3;
        return -1;
    }
}
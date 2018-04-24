#pragma once

typedef struct priorityqueue_s priorityqueue_t; 
typedef struct pqentry_s pqentry_t;

priorityqueue_t* pqueue_create();
void pqueue_insert (priorityqueue_*pq, char*value, float p);
char* pqueue_extractMin(priorityqueue_t *pq);
void pqueue_decreaseKey(priorityqueue_t *pq, char*value, float p);
void pqueue_remove(priorityqueue_t *pq, char*value);
void pqueue_destroy(priorityqueue_t *pq);
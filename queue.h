#pragma once 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int newtype;
typedef struct queuenode
{
	struct queuenode* next;
	newtype data;
}qnode;

typedef struct queue
{
	qnode* head;
	qnode* tail;
	int size;
}que;

void queueinit(que* pq);
void queuedestory(que* pq);
void queuepush(que* pq, newtype x);
void queuepop(que* pq);
newtype queuefront(que* pq);
newtype queueback(que* pq);
bool queueempty(que* pq);
int queuesize(que* pq);
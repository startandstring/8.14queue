#include"queue.h"
void queueinit(que* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void queuedestory(que* pq)
{
	assert(pq);
	qnode* cur = pq->head;
	while (cur)
	{
		qnode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void queuepush(que* pq, newtype x)
{
	assert(pq);

	qnode* newnode = (qnode*)malloc(sizeof(qnode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}
void queuepop(que* pq)
{
	assert(pq);
	assert(!queueempty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		qnode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}

	pq->size--;
}
newtype queuefront(que* pq)
{
	assert(pq);
	assert(!queueempty(pq));

	return pq->head->data;
}
newtype queueback(que* pq)
{
	assert(pq);
	assert(!queueempty(pq));

	return pq->tail->data;
}
bool queueempty(que* pq)
{
	assert(pq);

	return pq->head;
}
int queuesize(que* pq)
{
	assert(pq);

	return pq->size;
}
#include <bits/stdc++.h>

using namespace std;

void fio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
}

class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

Queue *createQ(unsigned capacity)
{
    Queue *q = new Queue();
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    int a[capacity];
    q->array = a;
    return q;
}

int isFull(Queue *q)
{
    return (q->size == q->capacity);
}

int isEmpty(Queue *q)
{
    return (q->size == 0);
}

void enQ(Queue *q, int item)
{
    if (isFull(q))
    {
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
}

int deQ(Queue *q)
{
    if (isEmpty(q))
    {
        return INT_MIN;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        return INT_MIN;
    }
    return q->array[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        return INT_MIN;
    }
    return q->array[q->rear];
}

int main()
{

    fio();
    Queue *q = createQ(10);
    enQ(q, 10);
    enQ(q, 20);
    enQ(q, 30);
    enQ(q, 40);
    deQ(q);
    cout << q->array[q->front];

    return 0;
}
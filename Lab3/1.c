#include <stdio.h>
//Реалзіація черги
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void init(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int is_empty(Queue *q) {
    return q->count == 0 || q->count < 0;
}

int is_full(Queue *q) {
    return q->count == MAX_SIZE;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        return;
    }

    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        return -1;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;

    return value;
}

int peek_front(Queue *q) {
    if (is_empty(q)) {
        return -1;
    }

    return q->data[q->front];
}
//Вирішення задачі
int main() {
    Queue q;
    int n, k;

    init(&q);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter k: ");
    scanf("%d", &k);

    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }
    if(is_full(&q)) {
        printf("Queue is full!\n");
        return 1;
    };
    if(is_empty(&q)) {
        printf("Queue is empty!\n");
        return 1;
    };

    printf("Elimination order: ");

    while (q.count > 1) {

        for (int i = 1; i < k; i++) {
            int number = dequeue(&q);
            enqueue(&q, number);
        }

        int eliminated = dequeue(&q);
        printf("%d ", eliminated);
    }

    printf("\nLast number: %d\n", peek_front(&q));

    return 0;
}

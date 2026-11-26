#include <stdio.h>
#include <stdlib.h>
//Реалізація черги
typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

void init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int is_empty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->count++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        return -1;
    }

    Node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->count--;

    return value;
}

int peek_front(Queue *q) {
    if (is_empty(q)) {
        return -1;
    }

    return q->front->data;
}

void clear(Queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
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
    if (is_empty(&q))
    {
        printf("Queue is empty!");
        return 1;
    }

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

    clear(&q);

    return 0;
}
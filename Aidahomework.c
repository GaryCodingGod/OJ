#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EVENT 1000
#define MAX_TELLER 100

typedef struct {
    int time;
    char code;
    int index;
} Event;

typedef struct {
    int front, rear;
    int capacity;
    int* array;
    int status; // 出納員狀態：0（閒置）或 1（正在服務）
} Queue;

int Search(int N, Queue* queues[]);
Queue* createQueue(int capacity);
void enQueue(Queue* queue, int item);
int deQueue(Queue* queue);
bool isQueueEmpty(Queue* queue);

int main() {
    int Tmax, NMax;
    int Nteller;
    int TSistem = 0;
    Event events[MAX_EVENT];
    Queue* queues[MAX_TELLER];

    scanf("%d %d", &Tmax, &NMax);
    scanf("%d", &Nteller);

    for (int i = 0; i < Nteller; ++i) {
        queues[i] = createQueue(NMax); // 為每個隊列分配獨立的記憶體空間
    }

    while (TSistem <= Tmax) {
        scanf("%d %c %d", &events[TSistem].time, &events[TSistem].code, &events[TSistem].index);

        if (events[TSistem].index < 0 || events[TSistem].index >= Nteller) {
            printf("Error: Invalid teller index: %d\n", events[TSistem].index);
            TSistem++;
            continue; // 跳過此事件
        }

        if (events[TSistem].code == 'A') {
            printf("%d %c %d\n", events[TSistem].time, events[TSistem].code, events[TSistem].index);
            int i = Search(Nteller, queues); // 找到最短隊列
            enQueue(queues[i], TSistem);
            printf("%d %c %d\n", events[TSistem].time, events[TSistem].code, i);
            queues[i]->status = 1; // 標記為正在服務
        } else if (events[TSistem].code == 'D') {
            int i = events[TSistem].index;
            int removed = deQueue(queues[i]);
            if (removed != -1) {
                printf("%d %c %d\n", events[TSistem].time, events[TSistem].code, removed);
            } else {
                printf("Queue is empty\n");
            }
            if (isQueueEmpty(queues[i])) {
                queues[i]->status = 0; // 標記為閒置
            }
        }

        TSistem++;
    }

    for (int i = 0; i < Nteller; ++i) {
        while (!isQueueEmpty(queues[i])) {
            int removed = deQueue(queues[i]);
            printf("%d %c %d\n", TSistem, 'D', i);
            TSistem++;
        }
    }

    return 0;
}

int Search(int N, Queue* queues[]) {
    int minIndex = 0;
    int minSize = queues[minIndex]->rear - queues[minIndex]->front + 1;

    for (int i = 1; i < N; ++i) {
        int size = queues[i]->rear - queues[i]->front + 1;
        if (size < minSize || (size == minSize && i < minIndex)) {
            minIndex = i;
            minSize = size;
        }
    }

    return minIndex;
}

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    queue->status = 0; // 初始化狀態為閒置
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enQueue(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear++;
}

int deQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    return item;
}

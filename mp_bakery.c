// Bakery Serving System
// Lina Fatima Azzahra Badr NRP 5025251168

#include <stdio.h>
#include <string.h>

// max number of commands
#define max 20
// max length for pastry names
#define name_len 101

// struct for storing orders
typedef struct {
    int num; // order number
    char name[name_len]; // pastry name
} order;


// stack for normal baked goods
order stack[max];
int top = -1;

// push orders to stack
void push(order o) {
    if (top < max - 1) {
        stack[++top] = o;
    }
}

// pop orders from stack
int pop(order *o) {
    if (top >= 0) {
        *o = stack[top--];
        return 1;
    }
    return 0;
}

// remove specific orders from stack by order number
int cancel_stack(int num) {
    for (int i = 0; i <= top; i++) {
        if (stack[i].num == num) {
            // shift left
            for (int j = i; j < top; j++) {
                stack[j] = stack[j + 1];
            }
            top--;
            return 1;
        }
    }
    return 0;
}

// queue for bread
order queue[max];
int qfront = 0, qrear = -1;

// insert orders into queue
void enqueue(order o)
{
    if (qrear < max - 1)
    {
        queue[++qrear] = o;
    }
}

// extract orders from queue
int dequeue(order *o)
{
    if (qfront <= qrear)
    {
        *o = queue[qfront++];

        // reset queue if empty
        if (qfront > qrear) {
            qfront = 0;
            qrear = -1;
        }
        return 1;
        }
    return 0;
}

// remove specific orders from queue by order number
int cancel_queue (int num)
{
    for (int i = qfront; i <= qrear; i++)
    {
        if (queue[i].num == num)
        {
            for (int j = i; j < qrear; j++)
            {
                queue[j] = queue[j + 1];
            }
            qrear--;

            // reset queue if empty
            if (qfront > qrear)
            {
                qfront = 0;
                qrear = -1;
            }
            return 1;
        }
    }
    return 0;
}


// deque for macarons
order deque[max];
int front = -1, rear = -1;

// push even orders to the front
void push_front(order o) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = o;
    } else if (front > 0) {
        deque[--front] = o;
    } else {
        // shift everything right
        for (int i = rear; i >= front; i--) {
            deque[i + 1] = deque[i];
        }
        rear++;
        deque[front] = o;
    }
}

// push odd orders to the back
void push_back(order o) {
    if (front == -1) {
        front = rear = 0;
        deque[rear] = o;
    } else if (rear < max - 1) {
        deque[++rear] = o;
    } else {
        // shift left
        for (int i = front; i <= rear; i++) {
            deque[i - 1] = deque[i];
        }
        front--;
        rear--;
        deque[++rear] = o;
    }
}

// pop orders from the front
int pop_front(order *o) {
    if (front == -1) {return 0;}

    *o = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {front++;}
    return 1;
}

// remove specific orders from deque by order number
int cancel_deque(int num) {
    if (front == -1) return 0;

    for (int i = front; i <= rear; i++) {
        if (deque[i].num == num) {
            for (int j = i; j < rear; j++) {
                deque[j] = deque[j + 1];
            }
            rear--;
            if (rear < front) {
                front = rear = -1;
            }
            return 1;
        }
    }
    return 0;
}


int main()
{
    char cmd[20];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);

        // cmd ORDER
        if (strcmp(cmd, "ORDER") == 0) {
            order o;
            scanf("%d %99[^\n]", &o.num, o.name);

            if (strcmp(o.name, "macarons") == 0) {
                if (o.num % 2 == 0) {
                    push_front(o);
                } else {
                    push_back(o);
                }
            }
            else if (strcmp(o.name, "bread") == 0) {
                enqueue(o);
            } else {
                push(o);
            }
        }

        // cmd SERVE
        else if (strcmp(cmd, "SERVE") == 0) {
            order o;

            // macarons > bread > others hierarchy
            if (pop_front(&o)) {
                printf("macarons %d served!\n", o.num);
            }
            else if (dequeue(&o))
            {
                printf("bread %d served!\n", o.num);
            }
            else if (pop(&o)) {
                printf("%s %d served!\n", o.name, o.num);
            }
            else {
                printf("no orders to serve!\n");
            }
        }

        // cmd CANCEL
        else if (strcmp(cmd, "CANCEL") == 0) {
            int num;
            scanf("%d", &num);

            if (!cancel_deque(num)) {
                if (!cancel_queue(num)) {
                    cancel_stack(num);
                }
            }
        }
    }
    return 0;
}

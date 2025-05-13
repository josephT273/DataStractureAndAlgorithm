#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int max_queue;
    int rear;
    int front;

public:
    Queue(int);
    ~Queue();
    void enqueue(int);
    void dequeue();
    int peek();
    void display();
    bool isFull();
    bool isEmpty();
};

Queue::Queue(int size_of_queue) {
    max_queue = size_of_queue;
    arr = new int[size_of_queue];
    front = -1;
    rear = -1;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue overflow detected" << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }

    arr[rear] = value;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow detected" << endl;
        return;
    }

    cout << "Dequeued: " << arr[front] << endl;
    front++;

    if (front > rear) {
        // Reset queue
        front = -1;
        rear = -1;
    }
}

int Queue::peek() {
    if (!isEmpty()) {
        return arr[front];
    } else {
        cout << "Queue is empty" << endl;
        return -1; // Sentinel value
    }
}

bool Queue::isFull() {
    return rear == max_queue - 1;
}

bool Queue::isEmpty() {
    return front == -1 || front > rear;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue contents:" << endl;
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    Queue queue(10);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Queue after enqueue operations:" << endl;
    queue.display();

    cout << "\nQueue after dequeue operations:" << endl;
    queue.dequeue();
    queue.dequeue();
    queue.display();

    return 0;
}

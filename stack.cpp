#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int max_stack;
    int top;

public:
    Stack(int);
    ~Stack();
    void push(int);
    void pop();
    int peek();
    void display();
    bool isFull();
    bool isEmpty();
};

Stack::Stack(int size_of_stack) {
    max_stack = size_of_stack;
    arr = new int[max_stack];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int value) {
    if (isFull()) {
        cout << "Stack overflow detected" << endl;
        return;
    }
    arr[++top] = value;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow detected" << endl;
        return;
    }
    cout << "Popped: " << arr[top--] << endl;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty, nothing to peek." << endl;
        return -1; // Sentinel value
    }
    return arr[top];
}

bool Stack::isFull() {
    return top == max_stack - 1;
}

bool Stack::isEmpty() {
    return top < 0;
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack contents (bottom to top):" << endl;
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    Stack stack(10);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);

    cout << "\nStack after push operations:" << endl;
    stack.display();

    cout << "\nTop element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "\nStack after pop operations:" << endl;
    stack.display();

    return 0;
}

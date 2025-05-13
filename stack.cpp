#include<iostream>

using namespace std;

class Stack{
    private:
        int* arr;
        int max_stack = 0;
        int top = -1;
    public:
        Stack(int);
        void push(int);
        void pop();
        int peek();
        void display();
        bool isFull();
        bool isEmpty();
};

Stack::Stack(int size_of_stack){
    max_stack = size_of_stack;
    arr = new int[size_of_stack];
}

void Stack::push(int value){
    if(top >= max_stack - 1){
        cout << "Stack overflow detected" << endl;
        return;
    }
    top++;
    arr[top] = value;
}

void Stack::pop(){
    if (top < 0) {
        cout << "Stack underflow detected" << endl;
        return;
    }
    arr[top] = 0;
    top--;
}

int Stack::peek(){
    return arr[top];
}

bool Stack::isFull() {
    return top == max_stack;
}

bool Stack::isEmpty(){
    return top < 0;
}

void Stack::display(){
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << endl;
    }
}
int main(){
    Stack* stack = new Stack(10);
    stack->push(10);
    stack->push(20);
    stack->push(30);
    stack->push(40);
    
    cout << "Stack push operation" << endl;
    stack->display();

    cout << "Top element: " << stack->peek() << endl;
    
    stack->pop();
    stack->pop();
    cout << "Stack pop operation" << endl;
    stack->display();



    return 0;
}
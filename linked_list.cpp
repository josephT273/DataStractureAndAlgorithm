#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert_at_end(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_list(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

void insert_at_beginning(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insert_at(Node** head, int data, int position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_at(Node** head, int key){
    if (*head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = *head;
    if(key == 0){
        *head = temp->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    for (int i = 0; i < key && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    
}

int main() {
    Node* head = nullptr;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_beginning(&head, 5);
    insert_at(&head, 15, 2);
    cout << "List after inserting at end: ";
    print_list(head);

    delete_at(&head, 2);
    cout << "List after deleting at position 2: ";
    print_list(head);
    delete_at(&head, 0);
    cout << "List after deleting at position 0: ";
    print_list(head);
}
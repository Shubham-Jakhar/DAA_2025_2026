#include<iostream>
using namespace std;
class Queue {
    struct Node {
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
    };
    Node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    void peek() {
        if (front == NULL)
            cout << "Queue is Empty";
        else
            cout << "Front Element:"<<front->data << endl;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is Empty";
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.peek();
    return 0;
}
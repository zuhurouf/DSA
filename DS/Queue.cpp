#include <iostream>

using namespace std;


struct node {
    int data;
    struct node* ptr;
};

struct node* FRONT = NULL;
struct node* REAR = NULL;


void display() {
    struct node* CURR_NODE;
    if (FRONT != NULL) {
        CURR_NODE = FRONT;
        while(CURR_NODE != NULL) {
            cout << CURR_NODE->data << " -> ";
            CURR_NODE = CURR_NODE->ptr;
        }
    }
    else {
        cout << "Queue is empty" << endl;
    }
}


void dequeue() {
    if (FRONT == NULL) {
        cout << "Empty queue" << endl;
    }
    else if (FRONT->ptr == NULL) {
        FRONT = NULL;
        REAR = NULL;
    }
    else {
        REAR = REAR->ptr;
    }

    display();
}


void enqueue(int data) {
    struct node* CURR_NODE;
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    if (FRONT == NULL) {
        n->ptr = NULL;
        FRONT = n;
        REAR = n;
    }
    else {
        n->ptr = FRONT;
        FRONT = n;
    }
    cout << "Front: " << FRONT << endl;
    cout << "Rear: " << REAR << endl;
    display();
}


int main() {
    int choice, data;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Data: ";
            cin >> data;
            enqueue(data);
            break;
        
        case 2:
            dequeue();
            break;
        
        default:
            display();
            break;
        }
    }
    return 0;
}
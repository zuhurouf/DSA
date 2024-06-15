#include <iostream>


using namespace std;


struct node {
    int data;
    struct node* ptr;
};

struct node* TOP = NULL;


void peek() {
    if (TOP == NULL) {
        cout << "Stack is empty" << endl;
    }
    else {
        cout << "Top element: " << TOP->data << endl;
    }
}


void pop() {
    if (TOP == NULL) {
        cout << "Stack is empty" << endl;
    }
    else if (TOP->ptr == NULL){
        TOP = NULL;
    }
    else {
        TOP = TOP->ptr;
    }
}


void push(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    if (TOP == NULL) {
        n->ptr = NULL;
        TOP = n;
    }
    else {
        n->ptr = TOP;
        TOP = n;
    }
}


int main() {
    int choice, data;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Peek" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Data: ";
            cin >> data;
            push(data);
            break;
        
        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
        
        default:
            break;
        }
    }
    return 0;
}
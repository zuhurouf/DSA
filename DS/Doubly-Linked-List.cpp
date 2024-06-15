#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* HEAD = NULL;
struct node* TAIL = NULL;


void display(string from = "front") {
    struct node* CURR_NODE;
    if (from == "front") {
        CURR_NODE = HEAD;
        while (CURR_NODE != NULL) {
            cout << CURR_NODE->data << " -> ";
            CURR_NODE = CURR_NODE->next;
        }
    }
    else {
        CURR_NODE = TAIL;
        while (CURR_NODE != NULL) {
            cout << CURR_NODE->data << " -> ";
            CURR_NODE = CURR_NODE->prev;
        }
    }
}


void delete_at_end() {
    struct node* CURR_NODE;
    if (HEAD == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else if (HEAD->next == NULL) {
        HEAD = NULL;
        TAIL = NULL;
    }
    else {
        CURR_NODE = TAIL;
        TAIL = CURR_NODE->prev;
        CURR_NODE->prev->next = NULL;
    }

    display();
}


void delete_at_front() {
    if (HEAD == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else if (HEAD->next == NULL) {
        HEAD = NULL;
        TAIL = NULL;
    }
    else {
        HEAD->next->prev = NULL;
        HEAD = HEAD->next;
    }

    display();
}


void insert_at_front(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->prev = NULL;
    if (HEAD == NULL) {
        n->next = NULL;
        HEAD = n;
        TAIL = n;
    }
    else {
        n->next = HEAD;
        HEAD = n;
    }
    display();
}


void insert_at_end(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    struct node* PREV_NODE;
    n->data = data;
    if (HEAD == NULL) {
        free(n);
        insert_at_front(data);
    }
    else {
        PREV_NODE = TAIL;
        PREV_NODE->next = n;
        n->prev = PREV_NODE;
        n->next = NULL;
        TAIL = n;
    }

    display();
}


int main() {
    int choice, data, pos;
    while (true) {
        cout << "\n1. Insert at front\n2. Insert at end\n3. Delete at front\n4. Delete at end\n5. Display in descending order\n6. Display in ascending order?";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Data: ";
                cin >> data;
                insert_at_front(data);
                break;
            
            case 2:
                cout << "Data: ";
                cin >> data;
                insert_at_end(data);
                break;

            case 3:
                delete_at_front();
                break;
            
            case 4:
                delete_at_end();
                break;
            
            case 5:
                display("end");
                break;
            
            default:
                display();
                break;
        }
    }
    return 0;
}
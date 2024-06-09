#include <iostream>
#include <cstdlib>


using namespace std;


struct node {
    int data;
    struct node* ptr;
};


struct node* HEAD = NULL;


void display() {
    struct node* CURR_NODE = HEAD;
    int pos = 0;
    cout << "\n";
    while (CURR_NODE != NULL) {
        cout << CURR_NODE->data << " -> ";
        CURR_NODE = CURR_NODE->ptr;
        pos++;
    }
}


void delete_at_pos(int data) {
    struct node* CURR_NODE, *PREV_NODE;
    if (HEAD == NULL) {
        cout << "Linked list is empty" << endl;
    }
    else {
        if (HEAD->data == data) {
            HEAD = HEAD->ptr;
        }
        else {
            CURR_NODE = HEAD;
            while (CURR_NODE != NULL and CURR_NODE->data != data) {
                PREV_NODE = CURR_NODE;
                CURR_NODE = CURR_NODE->ptr;
            }
            PREV_NODE->ptr = CURR_NODE->ptr;
        }
    }

    display();
}


void insert(int data, int pos) {
    int curr_pos = 0;
    struct node* CURR_NODE;
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    CURR_NODE = HEAD;
    while (curr_pos != pos) {
        CURR_NODE = CURR_NODE->ptr;
        curr_pos++;
    }
    n->ptr = CURR_NODE->ptr;
    CURR_NODE->ptr = n;

    display();
}


void insert_at_end(int data) {
    struct node* CURR_NODE;
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->ptr = NULL;
    if (HEAD == NULL) {
        HEAD = n;
    }
    else {
        CURR_NODE = HEAD;
        while (CURR_NODE->ptr != NULL) {
            CURR_NODE = CURR_NODE->ptr;
        }
        CURR_NODE->ptr = n;
    }

    display();
}


void insert_at_front(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    if (HEAD == NULL) {
        n->ptr = NULL;
        HEAD = n;
    }
    else {
        n->ptr = HEAD;
        HEAD = n;
    }

    display();
}


int main() {
    int choice, data, pos;
    while (true) {
        cout << "\n1 Insert\n2 Delete" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                cout << "1 Front  2 Rear 3 Middle: ";
                cin >> pos;
                if (pos == 1) {
                    insert_at_front(data);
                }
                else if (pos == 2) {
                    insert_at_end(data);
                }
                else {
                    cout << "Position: ";
                    cin >> pos;
                    insert(data, pos);
                }
                break;
            case 2:
                cout << "Delete?: ";
                cin >> data;
                delete_at_pos(data);
                break;
        }
    }
    return 0;
}
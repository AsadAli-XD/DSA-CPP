#include <iostream>
using namespace std;

// Structure of Node.
struct Node{
    int data;
    Node* next;
    // Constructors
    Node() { data = 0; next = NULL; }
    Node(int val) { data = val; next = NULL; }
};

// Starting point of a linked list.
Node *head = NULL;

// Size of ll
int size = -1;

// -> Makes a new node & returns it's address.
Node* makeNode(int val){
    Node *newnode = new Node(val);
    size++;
    return newnode;
}

// Adds value at the start of linked list. 
int AddFirst(int val){
    if(head == NULL){
        head = makeNode(val);
    }
    else{
        Node *temp = makeNode(val);
        temp->next = head;
        head = temp;
    }
    return 0;
}

// Inserts a node at the end of linked list.  
int AddLast(int val){
    if(head == NULL){
        head = makeNode(val);
    }
    if(head->next == NULL){
        head->next = makeNode(val);
    }
    else{
        Node *tmp = head;
        while(tmp->next != NULL) { tmp = tmp->next; }
        tmp->next = makeNode(val);
    }
    return 0;
}

// Inserts a node afer a node with a specific value. 
int AddAfterVal(int n, int val){
    if(head == NULL) {
        cout << " List is empty, Required index not found. \n";
    }
    if(head->next == NULL){
        if(head->data == n){
            head->next = makeNode(val);
        }
        else{
            cout << " Required Index not found. \n";
        }
    }
    else{
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == n){
                Node *t = makeNode(val);
                t->next = temp->next;
                temp->next = t;
            }
            temp = temp->next;
        }
    }
    return 0;
}

// Adds value on a specific index. 
int AddOnIndex(int index, int val){
    // check for invalid index.
    if(index < -1 || index > size +1) { cout << " ~ Invalid Index, Please Try again. \n"; }

    // 0 is the very first index of linked list.
    if(index == 0) { AddFirst(val); }

    // IF size of Linked list is >2.
    else{
        Node *temp = head;
        for( int i = 0; i != index-1; i++ ){
            temp = temp->next;
        }
        Node *t = makeNode(val);
        t->next = temp->next;
        temp->next = t;
    }
    return 0;
}

// Deletes the first node.
int removeFirst(){
    if(head == NULL) { cout << " Linked List is empty, Nothing to remove. \n"; }
    Node *t = head;
    head = head->next;
    delete(t);
    return 0;
}

int removelast(){
    if(head == NULL) { cout << " Linked List is empty, Nothing to remove. \n"; }
    Node *t = head;
    Node * p = t;
    
    while( t->next != NULL){
        p = t;
        t = t->next;
    }
    p->next = NULL;
    delete(t);
    return 0;
}

// Remove Node with a specific value. 
int removeVal(int val){
    if(head == NULL) { cout << " Linked list is Empty, Nothing to remove. \n"; }
    Node *t = head;
    Node *p = t;
    while(t != NULL){
        if(t->data == val){
            break;
        }
        p = t;
        t=t->next;
    }
    p->next = t->next;
    delete(t);
    return 0;
}

// Remove specific Index
int removeIndex(int n){
    if(n > size){
        cout << " ~ Given Index is invalid, please try again. \n";
    }
    Node *t, *p;
    t = head; p = t;
    for (int i = 0; i != n; i++) {
        p = t;
        t = t->next;
    }
    p->next = t->next;
    delete(t);
    return 0;
}

// A function to show linked list.
const void display(){
    cout << " Linked List: \n";
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " -> ";
        tmp = tmp->next;
    }
    cout << " NULL\n";
    return;
}

int main()
{
    AddFirst(10);
    AddLast(20);
    AddLast(30);
    // display();
    AddAfterVal(30,40);
    // display();
    AddOnIndex(4, 50);
    AddLast(60);
    AddLast(70);
    AddLast(80);
    AddLast(90);
    AddLast(100);
    display();
    removeFirst();
    display();
    removelast();
    display();
    removeVal(50);
    display();
    removeIndex(5);
    display();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int v;  // v stands for value.
    Node *n;    // n stands for next.
    Node *p;    // p stands for previous.
    // Constructors
    Node():v{-1} { n = p = NULL; }          // Assign -1 to "v" & put Null in next & pre ptr.
    Node(int x):v{x}{ n = p = NULL; }       // Assign x to "v" & put NULL in ...
};

class Queue{
    public:
    Node *front;            // Pointer to front Node in Queue.
    Node *rear;             // Pointer to rear Node in Queue. 

    // Constructor
    Queue() { front = rear = NULL; }

    // Utility Functions
    bool isEmpty(){ if(front == NULL && rear == NULL){return true; } else return false; }
    Node *makenode(int x) { return new Node(x); }

    // Queue Functions
    int enqueue(int x){
        if(isEmpty()){
            front = makenode(x);
            rear = front;
            return 0;
        }
        else if(front->n == NULL){
            front->n = makenode(x);         // Make a newnode next to front ptr. 
            rear = front->n;                // rear ptr now points to newly created node. 
            rear->p = front;                // pre ptr now points to front node because it's next to front node.
            return 0;
        }
        else{
            rear->n = makenode(x);          // create a newnode at last of list.
            Node *t = rear;                 // Save current last node in temporary ptr.
            rear = rear->n;                 // rear now points to newly created node which is new rear node.
            rear->p = t;                    // rear->previous ptr points to temporary node as it's next to it. 
            return 0;
        }
        return -1;                         // if none of these cases apply, this function returns -1 flagging error
    }

    int dequeue(){
        if(isEmpty()) {return -1;}          // If list is Empty, return -1 flagging error. 
        else if(front == rear){             // if front & rear point to same node. means it's last node in list.
            int a = front->v;               // store node's value in a variable.
            Node *t = front;                // store node's address in temp ptr
            front = rear = NULL;            // put NULL in front & rear making list NULL. 
            delete t;                       // delete temp node from memory.
            return a;                       // Return stored value.
        }
        else{
            int a = front->v;               // Store node's value in a variable.
            Node *t = front;                // temp ptr points to front node.
            front = front->n;               // move front ptr to it's next node.
            front->p = NULL;                // make front->previous ptr "NULL".
            delete t;                       // delete node stored in temp pts.
            return a;                       // return stored value of node recently removed. 
        }
        return 0;
    }

    // See what value is on top of queue.
    int peek(){
        if(!isEmpty()) { return front->v; } // If list not empty, return value on front of queue.
        else{ return -1;}                   // else return -1 flagging error. 
    }

    // See all values in list.
    const int show(){
        if(isEmpty()){ return -1; }
        Node *t = front;                    // store address of front node in temp ptr.
        while(t != NULL){                   // while temp is not equal to NULL i.e reached the end of list.
            cout << "| " << t->v << " |";   // Print value of this->node.
            t = t->n;                       // move temp ptr to it's next
        }
        return 0;
    }
};

// Home function Declaration
int home(Queue &q);

// Driver program.
int main(){
    Queue q1;
    home(q1);
    return 0;
}

// Defination of Home funcition. 
int home(Queue &q)
{
    system("clear");
    cout << "1) Enqueue \n";
    cout << "2) Dequeue \n";
    cout << "3) Peek \n";
    cout << "4) Check if Empty \n";
    cout << "5) Show All \n";
    cout << "0) Exit \n";
    cout << "_: ";
    int d;
    cin >> d;
    switch (d)
    {
    case 0:
    {
        exit(0);
    }
    break;
    case 1:
    {
        cout << " Enter Value: ";
        int a;
        cin >> a;
        q.enqueue(a);
        cin.get();
        home(q);
    }
    break;
    case 2:
    {
        if (!q.isEmpty())
        {
            cout << q.dequeue() << " is now popped out of queue. \n";
            cin.ignore();
            cin.get();
            home(q);
        }
        else{
            cout << " Queue is currently Empty. \n";
            cin.ignore(); cin.get();
            home(q);
        }
    }
    break;
    case 3:
    {
        if (q.peek() == -1)
        {
            cout << " Queue is currently empty. Nothing to show. \n";
        }
        else
        {
            cout << q.peek() << " is on the top of Queue. \n";
        }
        cin.ignore();
        cin.get();
        home(q);
    }
    break;
    case 4:
    {
        if (q.isEmpty())
        {
            cout << " Queue is Empty. \n";
        }
        else
        {
            cout << " Queue is not Empty. \n";
        }
        cin.ignore();
        cin.get();
        home(q);
    }
    break;
    case 5:
    {
        if(q.show() == -1) { cout << " Queue is currently Empty. \n";};
        cin.ignore();
        cin.get();
        home(q);
    }
    break;
    default:
    {
        cout << " Invalid choice. \n";
        cin.ignore();
        cin.get();
        home(q);
    }
    break;
    }
    return 0;
}
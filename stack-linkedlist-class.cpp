#include <bits/stdc++.h>
using namespace std;

// Class Node
class Node{
    public:
    int val;                // Data part of class Node
    Node *next;             // Pointer to next Node
    Node *pre;              // Pointer to previous Node

    // Constructor
    Node() { val = -1; next = pre = NULL; }         // Simple constructor
    Node(int x) {val = x; next = pre = NULL; }      // Parameterized constructor
};

// Class Stack
class Stack{
    public:                 
    Node *head;                 // Starting point of List
    int tval;                   // Hold temporary values             

    // Constructor
    Stack() { head = NULL; tval = -1; }     // Simple constructor

    // Utility Functions

    // Check Stack is Empty
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else return false;
    }

    // Method to create a new Node with parameterized Constructor
    Node *makeNode(int x){
        return new Node(x);             // Make a new Node & return it's address.
    }

    // Return the top value in Stack
    int showTop() {
        if(isEmpty()) return -1;
        else return head->val;
    }
    // Stack Functions

    // Push a value onto stack.
    int push(int x){
        if(isEmpty()){                          // If stack is Empty, 
            head = makeNode(x);                 // make a new Node & store it's address in Head / Top
            head->next = NULL;                  // Make next ptr NULL ( to avoid any core segmentation faults )
            head->pre = NULL;                   //    //
        }
        else{
            Node *t = makeNode(x);              // If List isn't empty, ptr Node *t hold address of new Node
            t->next = head;                     // ptr t->next hold the address of current head.
            head->pre = t;                      // Link head to newly created Node. 
            head = t;                           // Move head ptr to start of list. 
            return 0;
        }
        return 0;
    }

    // Pop Function
    int pop(){
        // Incase list is Empty
        if(isEmpty()) { cout << "\t Stack Underflow. \n"; return -1; }
        // If there's only one Node in Stack.
        else if(head->next == NULL) { tval = head->val; head = NULL; return tval; }
        // if N > 1
        else{
            tval = head->val;
            head = head->next;
            head->pre = NULL;
        }
        return tval;
    }

    // Print whole Stack.
    const void show(){
        if(isEmpty()) { cout << "\tList is Empty. Nothing to show. \n"; return; }
        else{
            Node *t = head;
            while(t != NULL){
                cout<< " | " << t->val << " | \n";
                t = t->next;
            }
            // cout << " NULL. \n";
        }
        return;
    }

};

// Home function Declaration
int home(Stack &s);

int main(){
    Stack s;            // Stack Declaration
    home(s);            // Pass Stack to homoe Function

    return 0;
}

    // Defination of Driver Program.
int home(Stack &s){
    system("clear");
    cout << "1) Push \n";
    cout << "2) Pop \n";
    cout << "3) Show Top value \n";
    cout << "4) Check if Empty \n";
    cout << "5) Show All \n";
    cout << "0) Exit \n";
    cout << "_: "; int c; cin >> c;
    switch (c)
    {
    case 0:{
        exit(0);
    }
        break;
    case 1:{
        cout << " Enter Value: "; int a; cin >> a;
        s.push(a);
        cin.get(); 
        home(s);
    }
    break;
    case 2:{
        if(!s.isEmpty()) { cout << s.pop() << " is now popped out of stack. \n"; cin.ignore(); cin.get(); home(s); }
    }
    break;
    case 3:{
        if(s.showTop() == -1) { cout << " Stack is currently empty. Nothing to show. \n"; } 
        else { cout << s.showTop() << " is on the top of Stack. \n"; }
        cin.ignore();
        cin.get();
        home(s);
    }
    break;
    case 4:{
        if(s.isEmpty()) { cout << " Stack is Empty. \n"; }
        else { cout << " Stack is not Empty. \n"; }
        cin.ignore(); cin.get(); home(s); 
    }
    break;
    case 5:{
        s.show();
        cin.ignore();
        cin.get();
        home(s);
    }
    break;
    default:{ cout << " Invalid choice. \n"; cin.ignore(); cin.get(); home(s); }
        break;
    }
    return 0;
}
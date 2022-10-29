#include <bits/stdc++.h>
using namespace std;

// Struct Node
struct Node{
    int val;        // Data Container. 
    Node *next;     // Pointer variable to hold address of next Node in list. 

    // Constructors
    Node() { val = 0; next = NULL; }
    Node(int v) { val = v; next = NULL; }
};

// Starting Point of Stack.
Node *head = NULL;
// Top Pointer of Stack
Node *top = NULL;

// Utility Functions

// A function to check if Stack is Empty. 
bool isEmpty(){
    if(head == NULL) { return true; } else return false;
}

// Show value at the top in Stack. 
int showTop() { return top->val; }

// Function to create a New Node in Stack List. 
Node *makeNode(int x) { return new Node(x); }  // Create a new Node(x) & return it's address. 

// Stack functions.

// Push Function
int push(int x){
    if(isEmpty()){                          // If list is Empty, Create first Node and save it's address in head.
        head = makeNode(x);
        top = head;                         // point top to the first node in list. 
        return 0;
    }
    else{                                   // If list is not empty, top is pointing to last node. 
        top->next = makeNode(x);            // Create a node & save it in next ptr of last node. 
        top = top->next;                    // Move top ptr to the newly added node.
        return 0;
    }
    return -1;                              // Return -1 for Error Detection purposes. 
}

// Pop Function
int pop(){
    if(isEmpty()) { cout << "\n stack underflow. \n "; return 0; }
    else{
        int a = 0;                  // container to hold popped value to return it.
        Node *t = head;             //  Create a temp ptr that points to head. 
        while(t->next != top){      //  This loop will stop when temp pointer is at the node before top node.
            t = t->next;
        }
        top = t;                    // top will point to it's previous node. 
        t = t->next;                // temp ptr is moved to the top most node in stack. 
        a = t->val;                 //  Save value of node to be popped out. 
        delete(t);                  // pop out top node.
        return a;                   // return popped value. 
    }
    return -1;                  
}

// Home function of Driver Program. 
int home();

// Main Function.
int main()
{
    cout << "\t\t\t\t Stack ( Linked List Based ). \n";
    home();
    return 0;
}

// Defination of Home Function. 
int home(){
    // Variables declaration.
    int x = 0; // Temp variable to hold inputs & values.
    system("clear");
    cout << " \n\n";
    cout << "1) Push \n";
    cout << "2) Pop \n";
    cout << "3) Top Value \n";
    cout << "4) Check if stack is Empty \n";
    cout << "0) Exit \n";
    cout << " _: ";
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 0:
    {
        exit(0);
    }
    break; // Exit program.
    case 1:
    {
        cout << " Value: ";
        cin >> x;
        cout << push(x);
        cin.get();
        home();
    }
    break; // Take value & pass in parameter of push function.
    case 2:
    {
        cout << pop() << " is now popped out of stack. \n";
        cin.ignore();
        cin.get();
        home();
    }
    break;
    case 3:
    {
        cout << showTop() << " is the top value in stack. \n";
        cin.ignore();
        cin.get();
        home();
    }
    break;
    case 4:
    {
        if (isEmpty())
        {
            cout << " Stack is Empty. \n";
        }
        else
            cout << " Stack is not Empty. \n";
        cin.ignore();
        cin.get();
        home();
    }
    break;
    default:
    {
        cout << " Invalid Input. Please Try again. \n";
        cin.ignore();
        cin.get();
        home();
    }
    }
    return 0;
}

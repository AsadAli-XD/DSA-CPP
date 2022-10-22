#include <bits/stdc++.h>
using namespace std;

// Defining class Node
class Node{
    public:             // Public Members & Methods of class Node
    int data; 
    Node *next;
    // Constructors
    Node() { data = 0; next = NULL; }
    Node(int x) { data = x; next = NULL; }
};

class LinkedList{
    private:            // Private Data-Part of class: LinkedList
    Node *head;         // Starting Point of Linked List
    Node *min, *max;    // Ptr of type Node, containing Address of Min & Max value Nodes.
    
    public:
    // Constructors
    LinkedList() { head = min = max = NULL; }   // Initializing All Members to NULL.

    Node *makeNode(int v)           // A utility Function to make a new node using Parameterized constructor. 
    {
        Node *t = new Node(v);      // Creates a new Node & saves it address in *t.
        if (!min || (min && v <= min->data)){
                // If we find a Node which is smaller than present min, min points to it.
                min = t;
            }    
        if(!max || (min && v >= max->data)) { max = t; }    // If we find a Node which is greater than present max, max points to it.
        return t;   // return newly created node. 
    }

    // A utility Function to check if List is Empty or not. 
    bool isEmpty() { if(head == NULL ) { return true; } else return false; }

    // Insert at start of list. 
    int addFirst(int x){
        if(isEmpty()) { head = makeNode(x); return 0;}   // If list is Empty, head points to newly created node.
        Node *t = makeNode(x);  // If list isn't empty, *t points to newnode with value of x;
        t->next = head;         // newnode now points to head;
        head = t;               // head node points to newnode, making it first node of list. 
        return 0;
    }

    // Insert at the end of list.
    int addLast(int x){
        if(isEmpty()) { head = makeNode(x); return 0;}
        Node *t = head;   // *t now points to start of list. 
        while(t->next != NULL){     // Traversing list until we reach last node in list. 
            t = t->next;            // Statement to iterate to next node in list. 
        }
        // now, *t points to last node in the last. So, create new node at the next ptr of last node. 
        t->next = makeNode(x);
        return 0;
    }

    // Display List.
    const void show(){
        Node *t = head;         // *t points to the start of list.
        while(t != NULL ){      //  until t reaches last->next node, this loop will keep iterating. 
            cout << t->data << " -> ";      // Show data part of Node
            t = t->next;                    // Iterate *t to next node in List.
        }
        cout << "NULL" << endl;

        cout << " Min Node: " << min->data << endl;
        cout << " Max Node: " << max->data << endl;
        return;
    }

    // Sum of Linked List. 
    int sumList(){
        int sum = 0;        // Variable to hold Sum
        Node *t = head; 
        while(t != NULL){
            sum+= t->data;      // Adds data of each node to existing value of Sum in each iteration.
            t = t->next;        // Iterate to next node in list. 
        }
        return sum;
    }
};

int main()
{
    // Creating a Linked List First
    LinkedList A;
    for(int i = 10; i < 18; i++){
        A.addLast(i+1);         // Starts values from 11.
    }
    A.show();
    cout << endl << " Sum of all values in List: " << A.sumList() << endl;
    return 0;
}
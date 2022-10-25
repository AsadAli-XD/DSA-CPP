#include <bits/stdc++.h>
using namespace std;
// Class of Node. 
class Node{
    public: 
    int data;
    Node *next;
    Node *pre; 

    // Constructors & Destructor
    Node() { data = 0; next = pre = NULL; }
    Node(int v) { data = v; next = pre = NULL; }
    ~Node() {};
};

class DLL{
    private:
        Node *head;         // Starting Point of doubly linked list. 
    public:
    DLL() { head = NULL; }      // DLL constructor.

    // Utility Functions.

    // If ll empty returns true, else false;
    bool isEmpty(){ if (head == NULL) {return true; } else return false;}  

    // Makes and return new node with parameter x.
    Node *makeNode(int x) { return new Node(x); }
    
    // Class Methods. 

    // Insert at start of Linked List.
    int addFirst(int x){
        // if head is NULL, Insert there.
        if(isEmpty()) { head = makeNode(x); head->pre = head->next = NULL; return 0; }

        // otherwise, insert at head->pre & move head ptr to new Node. 
        else {
            Node *t = makeNode(x);
            t->next = head;  // link head to next of t
            head->pre = t;      // link previous of head to t
            head = t;       // Move Head ptr to t.
            return 0;
        }
        return -1;
    }

    // Insert at the end of linked list. 
    int addLast(int x){
        // If list is Empty, create first Node on the start of linked list.
        if(isEmpty()) { head = makeNode(x); return 0;}
        // If there's only one element in Linked list, Insert at it's next;
        else if(head->next == NULL){
            Node *t = makeNode(x);
            head->next = t;     // Inserting at next of head;
            t->pre = head;      // Linking previous ptr of newNode to head;
            return 0;
        }
        // Traverse linked list & insert at the next of last node.
        else{
            Node *tmp = head;
            // Traverse the list.
            while(tmp->next != NULL){
                tmp = tmp->next;
            }
            // Create new Node
            Node *t = makeNode(x);
            tmp->next = t;  // Insert at the next of last node.
            t->pre = tmp;   // Link previous ptr to the last node.
            return 0;
        }
        return -1;
    }

    // Remove from the start of List.    
    int removeFirst(){
        if(isEmpty()) { cout << " List is Empty, \n"; return 0;}
        else{
            Node *x = head;
            head = head->next;  // Move head ptr to it's next;
            head->pre = NULL;   // Make Previous ptr NULL to avoid ambiguities. 
            delete(x);          // Delete Broken Node.
        }
        return 0;
    }

    // Remove from the last of List.
    int removeLast(){
        Node *p, *t;        // Two pointers of previous & temp. 
        t = head;           
        while(t->next != NULL){
            p = t;          // Previous = temp. before we move temp forward.
            t= t->next;     // Iterate temp variable. 
        }
        p->next = NULL;     // breaking the link to last node.
        delete(t);          // Delete Broken Node.
        return 0;
    }

    // Display the contents of List. 
    const void show(){
        if(isEmpty()) { cout << "List is Empty, Nothing to show. \n"; return;}
        else{
            Node *t = head;
            while(t != NULL){
                cout << t->data << " -> ";
                t = t->next;
            }
            cout << " NULL. \n";
        }
        return;
    }

    // Show list from last to first. 
    const void showl(){
        if(isEmpty()) { cout << "List is Empty, Nothing to show. \n"; return;}
        
        // Traverse to the last of list, to show last - first.
        Node *tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        while(tmp != NULL){
            cout << tmp->data << " <- ";
            tmp = tmp->pre; // Traverse backwards.
        }
        cout << " Head. \n";
        return;
    }

};


// Driver Program. 
int main()
{
    DLL obj;
    obj.addFirst(20);
    obj.addFirst(10);
    obj.addFirst(0);
    obj.addLast(30);
    obj.show();
    cout << endl;
    obj.showl();
    obj.removeFirst();
    obj.show();
    obj.removeLast();
    obj.showl();

    return 0;
}

        
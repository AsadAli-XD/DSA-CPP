#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    stack<int> main;                            // Stack 1, using it as main stack to carry queue values.
    stack<int> ext;                             // Stack 2, using it as a supporting stack to perform queue funcitons. 
    public:
    // Constructor
    Queue(){};                                 // As these stacks are stl so they're already initialized we don't need to define anything.
    
    // Utility Function
    bool isEmpty(){ if(main.empty()) { return  true; } else return false; }     // if main stack is empty, means Queue is Empty. 

    // enqueue Function
    int enqueue(int x){
        main.push(x);                           // put values in main stack. 
        return 0;
    }

    // dequeue function
    int dequeue(){
        int size_of_main = main.size();             // variable to hold size of main stack. 
                                                    // For loop to pop size_of_main stack - 1 elements from stack. 
        for(int i = 0; i < size_of_main-1; i++){
            ext.push(main.top());                   // Push top element from main stack & push elements in supporting stack. 
            main.pop();                             // Remove the top element from the main stack. 
        }

        int val = main.top();                       // store value of last item in main stack to return it.
        main.pop();                                 // pop last item from main stack. 
        int size_of_ext = ext.size();               // variable to store size of supporting stack

                        // This while loop will transfer elements back to main stack from supporting stack.
        while(!ext.empty()){
            main.push(ext.top());
            ext.pop();
        }
        return val;                                 // Return stored value of element. 
    }

    // return element on Front of Queue
    int const frontval() {
        if(isEmpty()) { return -1; }            // Check if the queue is empty. 
        
        while (!main.empty())                   // check while main stack is not empty,
        {
            ext.push(main.top());               // put main[top] element in supporting stack
            main.pop();                         // pop main[top] element
        }
        int a = ext.top();                      // put value of ext[top] in variable to return later.
                                    // This loop first shows ext[top] element, then transfer it back to main stack. & pops it from ext. 
        while (!ext.empty())
        {
            cout << " |" << ext.top() << "| ";
            main.push(ext.top());
            ext.pop();
        }
        return a;
    }

    // Return rear value of Queue
    int const rearval(){
        if(!isEmpty()){             // if queue is not empty, return top value of main stack. 
            return main.top();
        }
        else return -1;             // otherwise return -1 as error flag or NULL.
    }

    // show function for Queue
    const void show(){
        if(isEmpty()) {return; }                // check if Queue is Empty.
        while(!main.empty()){
            ext.push(main.top());
            main.pop();
        }
        while(!ext.empty()){
            cout <<" |" << ext.top() << "| "; 
            main.push(ext.top());
            ext.pop();
        }
        return; 
    }
};

// Home Fucntion Declaration
int home(Queue &obj);

// Main Function
int main(){
    Queue one;
    cout << "\n Driver Program for Queue implemented by 2 Stacks. \n";
    cin.ignore(); cin.get();
    home(one);
    return 0;
}

// Home Function Defination
int home(Queue &obj){
    system("clear");
    cout << "1) Enqueue \n";
    cout << "2) Dequeue \n";
    cout << "3) Show Front value \n";
    cout << "4) Show Rear value\n";
    cout << "5) Check if Empty \n";
    cout << "6) Show All \n";
    cout << "0) Exit \n";
    cout << "_: ";
    int c;
    cin >> c;
    switch (c)
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
        obj.enqueue(a);
        cin.get();
        home(obj);
    }
    break;
    case 2:
    {
        if (!obj.isEmpty())
        {
            cout << obj.dequeue() << " is now Dequeued. \n";
            cin.ignore();
            cin.get();
            home(obj);
        }
    }
    break;
    case 3:
    {
        if (obj.frontval() == -1)
        {
            cout << " Queue is currently empty. Nothing to show. \n";
        }
        else
        {
            cout << obj.frontval() << " is on the front of Queue. \n";
        }
        cin.ignore();
        cin.get();
        home(obj);
    }
    break;
    case 4: 
    {
        if (obj.rearval() == -1)
        {
            cout << " Queue is currently empty. Nothing to show. \n";
        }
        else
        {
            cout << obj.rearval() << " is on the Rear of Queue. \n";
        }
        cin.ignore();
        cin.get();
        home(obj);
    }
    break;
    case 5:
    {
        if (obj.isEmpty())
        {
            cout << " Queue is Empty. \n";
        }
        else
        {
            cout << " Queue is not Empty. \n";
        }
        cin.ignore();
        cin.get();
        home(obj);
    }
    break;
    case 6:
    {
        obj.show();
        cin.ignore();
        cin.get();
        home(obj);
    }
    break;
    default:
    {
        cout << " Invalid choice. \n";
        cin.ignore();
        cin.get();
        home(obj);
    }
    break;
    }
    return 0;
}
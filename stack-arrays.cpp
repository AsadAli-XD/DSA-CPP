#include <iostream>
using namespace std;
#define size 10
// Size of stack.

// ptr to top element in Stack.
int top = -1;
// Declaring Stack. 
int stack[size];

// Utility Functions

// Utility function to check if Stack is Empty.
bool isEmpty(){
    if(top == -1) {return true;}
    else return false;
}

// Utility function to check if Stack is Full.
bool isFull(){
    if(top >= size) { return true; }
    else return false;
}

// Display value at the top of stack.
int showTop(){
    return stack[top];   // Returning the value of at top index of Stack
}

// Push function for stack
int push( int x){
    if(isFull()) { cout << "Stack overflow. \n"; return -1; }   // check if the stack is Full.
    else{
        top++;              // Increment the top pointer to move it one index forward. 
        stack[top] = x;     // Insert value at this index.
    }
    return 0;
}

// Pop function for stack
int pop(){
    if(isEmpty()) { cout << " Stack underflow. \n"; return -1; }
    else{
        int x = stack[top];     // Hold value to be popped out in a temp variable. (in this case it's x).
        top--;                  // Decrement top pointer. 
        return x;               // Return popped value. 
    }
    return -1;                  // Incase these conditions don't work due to a problem, this function returning -1
    //                             will tell us that.
}


// Driver program. 
int main(){
    for(int i = 0; i < 10; i++){
        push(i+10);
        cout << stack[top] << " ";
    }
    cout << endl;
    showTop();
    cout << endl;
    for(int i = 10; i >0; i--){
        cout << pop() << " ";
    }

    cin.get();
    return 0;
}
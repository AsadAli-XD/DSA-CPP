#include <bits/stdc++.h>
using namespace std;
#define size 10
// Defined the variable SIZE, for array of Stack

class Stack{
    private:
        int top;                // Ptr to top value in stack.
        int stack[size];        // Array of Stack.
    public:
        // Constructor & Desturctor
        Stack() { top = -1; }   // Constructor for stack. 
        ~Stack() {}             // Destructor for stack.

        // Utility Functions
        
        // If top is NULL, means stack is empty, so return true. otherwise, return false. 
        bool isEmpty() { if(top == -1) { return true; } else {return false; }}     
        
        // If top is > or = to ::size, means Stack is full. so retrn true. otherwise return false.
        bool isFull()  {if(top >= size) {return true; } else {return false; }}

        // Show to Top value on the stack. 
        int showTop() { return stack[top]; }

        // Class Methods

        // Push Function to add Values onto stack. value is passed in parameter. 
        int push(int x){
            // Check if stack is already full, if so, print stack overflow, means it is already filled to its max capacity. 
            if(isFull()){ cout << " Stack Overflow. \n"; return -1; }

            // If there's space in stack, increment the top ptr to next empty cell & insert the value x there. 
            else{
                top+=1;              // Increment top ptr.
                stack[top] = x;     // Insert value in Empty cell. 
                return stack[top];           // Return the parameter if push operation is successful. 
            }
            return 0;               // if none of above conditions work, we shall know if this function returns 0.
        }

        // Pop function to pop values out of stack. 
        int pop(){
            // if stack is Empty, there's nothing to pop out of stack.
            if(isEmpty()) { cout << " Stack Underflow. \n"; return -1; } // check if the stack is empty.

            //  Store the value in a tmp variable, & return the popped value. 
            else{
                int a = stack[top];     // Storing value at the top in temporary variable. 
                top--;                  // Decrement top ptr. 
                return a;               // return the popped value. 
            }
        }

        // clearStack function to clear the whole stack. (Warning, Once this function is called, all values in stack will be cleared. )
        int clearStack(){
            // Loop to traverse backwards from top ptr to starting index of array. 
            for(int i = top; i > -1; i--){
                stack[top] = -1;        // set each cell to -1 (empty)
                top--;                  // Decrement top pointer with each iteration.
            }
            return 1;                   // return 1 if this operation execution is successful. 
        }
}a;

// Home Function Declaration
int home();

// Driver Program.
int main()
{
    cout << "    Array based Stack using Class. \n";
    home();
    return 0;
}

// Home function Defination
int home(){
    // Variables declaration. 
    int x = 0;                  // Temp variable to hold inputs & values.
    system("clear");
    cout << " \n\n";
    cout << "1) Push \n";
    cout << "2) Pop \n";
    cout << "3) Top Value \n";
    cout << "4) Check if stack is Empty \n";
    cout << "5) Check if stack is Full \n";
    cout << "0) Exit \n";
    cout << " _: ";
    int choice = 0; cin >> choice;
    switch(choice){
        case 0: { exit (0); } break;                                               // Exit program.
        case 1: { cout << " Value: "; cin >> x; cout << a.push(x); cin.get(); home(); } break;               // Take value & pass in parameter of push function. 
        case 2: { cout << a.pop() << " is now popped out of stack. \n"; cin.ignore(); cin.get(); home(); } break;
        case 3: { cout << a.showTop() << " is the top value in stack. \n"; cin.ignore(); cin.get();  home(); } break;
        case 4: {
                    if(a.isEmpty()){ cout << " Stack is Empty. \n";} 
                    else cout << " Stack is not Empty. \n"; 
                    cin.ignore(); cin.get(); home();
                } break;
        case 5: {
                    if(a.isFull()) { cout << " Stack is Full. \n"; } 
                    else cout << " Stack is not Full. \n"; 
                    cin.ignore(); cin.get(); home(); 
                } break;
        default: { cout << " Invalid Input. Please Try again. \n"; cin.ignore(); cin.get(); home(); }
    }
    return 0;
}

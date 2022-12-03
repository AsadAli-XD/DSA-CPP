#include <bits/stdc++.h>
using namespace std;
#define size 10

string emptyq = " Queue is Empty. No values can be dequeued. \n "; 
string full = " Queue is Full. No more values can be added. \n ";

class Queue{
    private:
        int q[size];
        int front, rear, c; // c stands for count
    public:
        Queue(): c{0} { front = rear = -1;}

        // utility Functions
        bool isEmpty() { if( rear == -1) {return true; } else return false; }
        bool isFull() { if(c >= 10) { return true; } else return false; }

        // Queue Functions
        int enqueue(int x){
            if(!isFull()){
                if (isEmpty())
                {
                    front = rear = 0;
                    q[rear] = x;
                    c++;
                }
                else
                {
                    if (rear + 1 < size)
                    {
                        rear++;
                        q[rear] = x;
                        c++;
                        return 0;
                    }

                    else if(rear+1 >= size){
                        rear = 0; 
                        q[rear]= x;
                        c++;
                        return 0;
                    }
                }
            }
            else{
                cout << full << endl; return 0;
            }
            return -1;
        }

        int dequeue(){
            if(!isEmpty()){
                if(front == rear){
                    int a = q[front];
                    front = rear = -1;
                    c--;
                    return a;
                }
                else if(front +1 >= size){
                    int a = q[front];
                    front = 0;
                    c--;
                    return a;
                }
                else{
                    int a = q[front];
                    front++;
                    c--;
                    return a;
                }
            }
            else{
                cout << emptyq << endl;
            }
            return -1;
        }

        int peek() const {
            if(front == -1) { return -1;}
            return  q[front];
        }

        const void show(){
            int i = front;
            if(i == 0) { 
                for(i; i < c; i++){
                    cout << " | " << q[i] << " | \n";
                }
            }
            else{
                while(i != front-1){
                    cout << " | " << q[i] << " | \n";
                    if(i+1 >= size){ i = -1; }
                    i++;
                }
            }
            cout << endl;
            return; 
        }

};

// Home function declaration
int home(Queue &q);

int main(){
    Queue q1;
    home(q1);
    return 0;
}

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
            q.show();
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
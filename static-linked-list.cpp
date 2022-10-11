#include <iostream>
#include <conio.h>
#define SIZE 6
using namespace std;

class StaticLinkedList
{
private:
    int values[SIZE];
    int Next_E[SIZE];
    int Next_F[SIZE];
    int empty;
    int head;

public:
    StaticLinkedList() : values{-1}, Next_E{1, 2, 3, 4, 5, -1}, Next_F{-1}, empty(0), head(-1) {}
    void display_Fill()
    {
        int i;
        for (i = head; Next_F[i] != -1; i = Next_F[i])
        {
            cout << values[i] << " , ";
        }
        cout << values[i];
    }
    void display_Empty()
    {
        int i;
        if (empty != -1)
        {
            for (i = empty; Next_E[i] != -1; i = Next_E[i])
            {
                cout << i << " --> ";
            }
            cout << i;
        }
        else
            cout << "List is full" << endl;
    }
    void add(int val)
    {
        if (empty == -1)
            cout << "No space available" << endl;
        else
        {
            int temp = head;
            values[empty] = val;
            head = empty;
            Next_F[empty] = temp;
            empty = Next_E[empty];
        }
    }
    void remove()
    {
        if (head == -1)
            cout << "List is empty" << endl;
        else if (Next_F[head] == -1)
        {
            int temp = empty;
            empty = head;
            head = -1;
            Next_E[empty] = temp;
        }
        else
        {
            int temp = empty;
            empty = head;
            head = Next_F[head];
            Next_E[empty] = temp;
        }
    }
    void remove(int val)
    {
        if (head == -1)
            cout << "List is empty" << endl;
        else if (Next_F[head] == -1)
        {
            if (values[head] == val)
            {
                int temp = head;
                empty = head;
                head = -1;
                Next_E[empty] = temp;
            }
        }
        else
        {
            int i;
            int pre_i;
            for (i = head; i != -1; i = Next_F[i])
            {
                if (values[i] == val)
                    break;
                pre_i = i;
            }
            if (i == -1)
                cout << "List is empty" << endl;
            else
            {
                if (head == i)
                {
                    int temp = empty;
                    empty = head;
                    head = Next_F[head];
                    Next_E[empty] = temp;
                }
                else if (Next_F[i] == -1)
                {
                    int temp = empty;
                    empty = i;
                    Next_F[pre_i] = -1;
                    Next_E[empty] = temp;
                }
                else
                {
                    int temp = empty;
                    empty = i;
                    Next_F[pre_i] = Next_F[i];
                    Next_E[empty] = temp;
                }
            }
        }
    }
    void display()
    {
        cout << "Values in Link List" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << values[i] << " ";
        }
        cout << endl
             << endl
             << "Empty List" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << Next_E[i] << " ";
        }
        cout << endl
             << endl
             << "Fill List" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << Next_F[i] << " ";
        }
        cout << endl
             << endl
             << "Head PTR: " << head << endl;
        cout << endl
             << "Empty PTR: " << empty << endl;
    }
};

int main()
{
    char ch;
    int val;
    StaticLinkedList SLL;
    do
    {
        system("cls");
        cout << "\t\tMenu" << endl
             << endl;
        cout << "1. Display Fill" << endl;
        cout << "2. Display Empty" << endl;
        cout << "3. Add an element" << endl;
        cout << "4. Remove an element" << endl;
        cout << "5. Remove last element" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            SLL.display_Fill();
            break;

        case '2':
            SLL.display_Empty();
            break;

        case '3':
            for (int i = 0; i < SIZE; i++)
            {
                cout << "Enter value: ";
                cin >> val;
                SLL.add(val);
                cout << endl;
            }
            break;

        case '4':
            cout << "Enter value: ";
            cin >> val;
            SLL.remove(val);
            break;

        case '5':
            SLL.remove();
            break;

        case '6':
            SLL.display();
            break;

        case '7':
            exit(0);
            break;

        default:
            cout << "Invalid choice";
            break;
        }
        _getch();
    } while (ch != '7');
    return 0;
}
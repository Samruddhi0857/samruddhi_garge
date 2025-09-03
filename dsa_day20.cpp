#include <iostream>
using namespace std;

#define MAX 10000   

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int value) 
{
        if (isFull()) 
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() 
{
        if (isEmpty()) 
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
{
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    
    void insertSorted(int x)
{
        if (isEmpty() || peek() > x) 
        {
            push(x);
            return;
        }
        int temp = pop();
        insertSorted(x);
        push(temp);
    }

  
    void sortStack() 
{
        if (!isEmpty()) 
        {
            int x = pop();
            sortStack();
            insertSorted(x);
        }
    }

  
    void display()
{
        if (isEmpty()) 
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "[";
        for (int i = top; i >= 0; i--)
          {
            cout << arr[i];
            if (i > 0) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() 
{
    Stack st;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements (last entered will be top):" << endl;
    for (int i = 0; i < n; i++)
      {
        int val;
        cin >> val;
        st.push(val);
    }

    cout << "\nOriginal(top → bottom): ";
    st.display();

    st.sortStack();

    cout << "Sorted Stack (ascending) (top → bottom): ";
    st.display();

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int topElem = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElem);
}


void reverseStack(stack<int> &st)
{
    if (st.empty()) return;

    int topElem = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, topElem);
}


void printTopToBottom(stack<int> st) 
{
    cout << "Stack (Top -> Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


void printBottomToTop(stack<int> &st) 
{
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    printBottomToTop(st);
    cout << x << " ";
    st.push(x); // restore
}

int main()
{
    stack<int> st;
    int n, val;
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> val;
        st.push(val);
    }

    reverseStack(st);

    printTopToBottom(st);    // option 1
    cout << "Stack (Bottom -> Top): ";
    printBottomToTop(st);    // option 2
    cout << endl;

    return 0;
}

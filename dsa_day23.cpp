#include <iostream>
#include <vector>
using namespace std;


class Deque
{
    vector<int> dq;      
    int frontIdx, backIdx, capacity, count;

public:
    Deque(int n) {
        dq.resize(n);
        frontIdx = 0;
        backIdx = -1;
        capacity = n;
        count = 0;
    }

    void push_back(int x) {
        if (count == capacity) return; 
        backIdx = (backIdx + 1) % capacity;
        dq[backIdx] = x;
        count++;
    }

    void pop_back() {
        if (empty()) return;
        backIdx = (backIdx - 1 + capacity) % capacity;
        count--;
    }

    void pop_front() {
        if (empty()) return;
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }

    int back() {
        return empty() ? -1 : dq[backIdx];
    }

    int front() {
        return empty() ? -1 : dq[frontIdx];
    }

    bool empty() {
        return count == 0;
    }
};


vector<int> slidingWindowMax(vector<int>& arr, int k) {
    int n = arr.size();
    Deque dq(n); 
    vector<int> result;

    for (int i = 0; i < n; i++) {
       
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

       
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        
        dq.push_back(i);

       
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> ans = slidingWindowMax(arr, k);

    cout << "Sliding Window Maximums: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

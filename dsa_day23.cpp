#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingWindowMax(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;  
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
        cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    vector<int> ans = slidingWindowMax(arr, k);

    cout << "Sliding Window Max eles: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

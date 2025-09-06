#include <iostream>
#include <vector>
using namespace std;
class Deque {
    vector<int> dq; 
public:
    void push_back(int x)
{
        dq.push_back(x);
    }

    void pop_back() 
{
        if (!dq.empty()) dq.pop_back();
    }

    void pop_front() 
{
        if (!dq.empty()) dq.erase(dq.begin());
    }

    int back() 
{
        return dq.empty() ? -1 : dq.back();
    }

    int front()
{
        return dq.empty() ? -1 : dq.front();
    }

    bool empty() 
{
        return dq.empty();
    }
};


vector<int> slidingWindowMax(vector<int>& arr, int k) 
{
    int n = arr.size();
      Deque dq;
    vector<int> result;

       for (int i = 0; i < n; i++)
      {
        
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

      
        while (!dq.empty() && arr[dq.back()] < arr[i])
          {
            dq.pop_back();
        }

       
        dq.push_back(i);

        
        if (i >= k - 1) 
        {
              result.push_back(arr[dq.front()]);
           }
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

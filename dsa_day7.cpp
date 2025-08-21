#include <iostream>
#include <vector>
using namespace std;

int rainwatercollect(vector<int>& n)
 {
    int size = n.size();
    int l= 0, r = size - 1;
    int left_hmax = 0, right_hmax = 0;
    long long filledwater = 0;

    while (l< r) 
    {
        if (n[l] < n[r])
         {
            if (n[l] >= left_hmax)
                   left_hmax = n[l];
            else
                filledwater += left_hmax - n[l];
            l++;
        } 
        else 
        {
            if (n[r] >= right_hmax)
                right_hmax= n[r];
            else
                filledwater += right_hmax - n[r];
            r--;
        }
    }
    return (int)filledwater;
}

int main()
 {
    int size;
    cout << "Enter size of array/ number of bars: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter array elements(bar heights): ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    cout << "Trapped Water: " << rainwatercollect(arr) << endl;
    return 0;
}

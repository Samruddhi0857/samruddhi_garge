#include <iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

void MergesortedArray(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int sum = m + n;
    int gap = (sum+ 1) / 2;  

    while (gap > 0) {
        int ptr1 = 0,  ptr2 = gap;

        while (ptr2 < sum) {
          
            if (ptr1 < m && ptr2 < m) {
                if (arr1[ptr1] > arr1[ptr2]) swap(arr1[ptr1], arr1[ptr2]);
            }
           
            else if (ptr1 < m && ptr2 >= m) {
                if (arr1[ptr1] > arr2[ptr2 - m]) swap(arr1[ptr1], arr2[ptr2 - m]);
            }
            
            else {
                if (arr2[ptr1- m] > arr2[ptr2- m]) swap(arr2[ptr1 - m], arr2[ptr2 - m]);
            }

            ptr1++;
            ptr2++;
        }

        if (gap == 1) break;  
        gap = (gap + 1) / 2;  
    }
}

int main() {
    int m, n;
    cout << "Enter size of arr1: ";
    cin >> m;
    cout << "Enter size of arr2: ";
    cin >> n;

    vector<int> arr1(m), arr2(n);

    cout << "Enter elements of arr1 (sorted): ";
    for (int i = 0; i < m; i++) cin >> arr1[i];

    cout << "Enter elements of arr2 (sorted): ";
    for (int j = 0; j < n; j++) cin >> arr2[j];

    MergesortedArray(arr1, arr2, m, n);

    cout << "\nMerged arrays:\n";
    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
}

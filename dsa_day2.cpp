#include <iostream>
#include <vector>
using namespace std;

class MissingNumber {
public:
    int findMissingNumber(vector<int>& arr, int n) {
        long long expectedSum = (1LL * n * (n + 1)) / 2;  
        long long actualSum = 0;
        for (int num : arr) {
            actualSum += num;
        }
        int missingnum=expectedSum-actualSum;
        return missingnum;
    }
};

int main() {
    int n;
    cout << "Enter number of elements in array  (Considered sorted array 1...n ): ";
    cin >> n;

    vector<int> arr(n - 1);
    cout << "Enter " << n-1 << " elements:\n";

    for (int i = 0; i < n - 1; i++) {
        cout<<"Enter element at pos"<<i<<": ";
        cin >> arr[i];
    }

    MissingNumber obj1=MissingNumber();
    cout << "Missing number: " << obj1.findMissingNumber(arr, n) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, vector<int>> indicesMap;
    vector<pair<int, int>> result;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

    
        if (sum == 0) {
            result.push_back({0, i});
        }

       
        if (indicesMap.find(sum) != indicesMap.end()) {
            for (int startIndex : indicesMap[sum]) {
                result.push_back({startIndex + 1, i});
            }
        }

      
        indicesMap[sum].push_back(i);
    }

    
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
      
        for (size_t i = 0; i < result.size(); i++) {
            cout << "(" << result[i].first << ", " << result[i].second << ")";
            if (i != result.size() - 1) cout << ", ";
        }
    }

    return 0;
}

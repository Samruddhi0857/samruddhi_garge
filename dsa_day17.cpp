#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cout<<"Enter number: ";
    cin >> n;

    vector<long long> factors;
    int i = 2;

    while (n != 1) {
        while (n % i == 0) {
            factors.push_back(i); 
            n = n / i;
        }
        i++;
    }

 
    cout << "[";
    for (size_t j = 0; j < factors.size(); j++) {
        cout << factors[j];
        if (j != factors.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

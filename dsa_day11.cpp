#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}


void permute(string str, int start, unordered_map<string, bool> &mp) {
    if (start == str.length() - 1) {
        mp[str] = true;  // store unique permutation
        return;
    }

    for (int i = start; i < str.length(); i++) {
        swap(str[start], str[i]);
        permute(str, start + 1, mp);
        swap(str[start], str[i]); // backtrack
    }
}

vector<string> uniquePer(string s) {
    unordered_map<string, bool> mp;
    permute(s, 0, mp);

    vector<string> result;
    for (unordered_map<string, bool>::iterator it = mp.begin(); it != mp.end(); ++it) {
        result.push_back(it->first);
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> permutations = uniquePer(s);

    cout << "Unique permutations are:\n";
    for (int i = 0; i < permutations.size(); i++) {
        cout << permutations[i] << endl;
    }

    return 0;
}

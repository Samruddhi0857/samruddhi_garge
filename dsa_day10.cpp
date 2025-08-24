#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;

vector<vector<string>>collectAna(vector<string>& strarr) {

    unordered_map<string, vector<string>> anagramMap;

   
    for (int i = 0; i < strarr.size(); i++)
     {
        string word = strarr[i];
        string key = word;

        sort(key.begin(), key.end()); 
        anagramMap[key].push_back(word);
    }

    
    vector<vector<string>> result;
    for (unordered_map<string, vector<string>>::iterator it = anagramMap.begin();
         it != anagramMap.end(); it++) 
         {
        result.push_back(it->second);
    }

    return result;
}

int main()
 {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> strarr;
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        strarr.push_back(word);
    }

    vector<vector<string>> groups =collectAna(strarr);

    cout << "\nAnagrams:\n";
    for (int i = 0; i < groups.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < groups[i].size(); j++) {
            cout << groups[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}

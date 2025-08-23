#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string FindLCP(vector<string>& arr) 
{
    if (arr.empty()) 
    {
        return "";
    }
 
    sort(arr.begin(), arr.end());

    string firstWord = arr.front();
    string lastWord  = arr.back();
    int minLength = min(firstWord.size(), lastWord.size());

    int index = 0;
    while (index < minLength && firstWord[index] == lastWord[index]) 
    {
        index++;
    }

    return firstWord.substr(0, index);
}

int main()
 {
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    string lcp= FindLCP(words);

    cout << "Longest Common Prefix: " << lcp<< endl;

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Count substrings with at most K distinct characters
int atMostK(const string &s, int k) 
{
    int n = s.size(), left = 0, result = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++)
      {
        freq[s[right]]++;

        // shrink window if more than k distinct chars
        while (freq.size() > k) 
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }

        // add all substrings ending at 'right'
        result += right - left + 1;
    }

    return result;
}

// Count substrings with exactly K distinct characters
int exactlyK(const string &s, int k)
{
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main()
{
    string s;
    int k;
    cin >> s >> k;

    cout << exactlyK(s, k) << endl;
    return 0;
}

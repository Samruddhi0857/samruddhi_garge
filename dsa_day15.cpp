#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int longestSubstring(string s)
{
    int left = 0, best = 0;
        unordered_set<char> seen;

    for (int right = 0; right < s.size(); right++)
      {
      
        while (seen.find(s[right]) != seen.end())
          {
                seen.erase(s[left]);
            left++;
        }
        
        seen.insert(s[right]);
        
             best = max(best, right - left + 1);
    }

    return best;
}

int main() 
{
    string s;
         cout << "Enter string: ";
              cin >> s;

    cout << "Result "
         << longestSubstring(s) << endl;

    return 0;
}

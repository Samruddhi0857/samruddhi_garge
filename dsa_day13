#include <iostream>
#include <string>
using namespace std;

int movefromcentre(const string& s, int i, int j) 
{
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
         i--;
        j++;
    }
    return j - i - 1; 
}

int main() 
{
    string s;
      cout << "Enter string: ";
         cin >> s;  

    int start = 0, end = 0;  //calculating length of string current 

    for (int i = 0; i < s.length(); i++)
    {
        int len1 = movefromcentre(s, i, i + 1); //even
      
        int len2 = movefromcentre(s, i, i);     // odd
            int len = max(len1, len2);

        if (end - start < len)
        {
               start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

   
  cout << "Longest Palindromic Substring: " 
         << s.substr(start, end - start + 1) << endl;

    return 0;
}

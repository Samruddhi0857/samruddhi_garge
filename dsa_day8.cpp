#include <iostream>
#include <algorithm>  
using namespace std;

string reverseStrWords(string s)
{
    string resStr = "";
    int n = s.size();
    int i = 0;

    while (i < n)
    {
        while (i < n && s[i] == ' ') i++; 
           if (i >= n) break;
        
      if (!resStr.empty()) resStr += ' '; 
        while (i < n && s[i] != ' ') 
           {
            resStr += s[i++];
           }
    }
  reverse(resStr.begin(), resStr.end());

    
    int start = 0;
    for (int j = 0; j <= resStr.size(); j++) 
    {
         if (j == resStr.size() || resStr[j] == ' ') 
         {
            reverse(resStr.begin() + start, resStr.begin() + j);
            start = j + 1;
        }
    }

    return resStr;
}

int main() 
{
    string st;
    cout << "Enter string:" << endl;
    getline(cin, st);  // ✅ read full line with spaces
    cout << "Reversed:\n" << reverseStrWords(st) << endl;
    return 0;
}





//Stack approach easier
/*
string reverseStrWords(string s)
{
    stack<string> st;
    string word = "";
    
    for (int i = 0; i < s.size(); i++) 
    {
        if (s[i] != ' ')
        {
            word += s[i];
        } else 
        {
            if (!word.empty())
            {
                st.push(word);
                word = "";
            }
        }
    }
    
    if (!word.empty()) st.push(word);

    
    string result = "";
    while (!st.empty()) 
    {
        result += st.top();
        st.pop();
        if (!st.empty()) result += " ";
    }
    
    return result;
}
*/

#include <iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
#include <climits>  
using namespace std;

vector<int> FindArrayLeaders(vector<int>& arr, int n) {
    int max=arr[n-1];
    vector<int> Arrleaders;
    Arrleaders.push_back(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
           Arrleaders.push_back( arr[i]); 
            max=arr[i];
        }
    }
     reverse(Arrleaders.begin(),Arrleaders.end());
  
    return Arrleaders;
    }


int main() {
    int n;
    cout << "Enter size of arr: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> leaders=FindArrayLeaders(arr, n);
cout<<"Leaders Array : ";
for(int i :leaders)
{
    cout<<i<<" ";
}

return 0;   
}


#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int searchnum(vector<int> arr,int k)
      {
          int n=arr.size();
      if(arr.size()==1 && k==1)
      {
         return arr[0];   
      }
      
      unordered_map<int,int> hashmap;
      for(int i=0;i<n;i++)
      {
          hashmap[arr[i]]++;
      }
      
      for(int i=0;i<n;i++)
      { if(hashmap[arr[i]]==k)
          {
              return arr[i];
          }
      }
       return -1;
      }
int main() {
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    
     cout<<"enter array: ";
      vector<int> arr(n);
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
      }
      cout<<"enter k: ";
      int k;
      cin>>k;
      
      int res=searchnum(arr,k);
      cout<<"Element occuring k times exactly: "<<res<<endl;
      
      
}

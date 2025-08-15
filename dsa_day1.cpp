#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Sortarr {
public:
    void sort_array(vector<int>& arr) {
        int n=arr.size();
         int low_value=0,curr_value=0,high_value=n-1;
       while(curr_value<=high_value)
       {
         if(arr[curr_value]==0)
         {
            swap(arr[curr_value],arr[low_value]);
            low_value++;
            curr_value++;
         }
         else if (arr[curr_value]==1)
         {
            curr_value++;
         }
         else{
            swap(arr[curr_value],arr[high_value]);
            high_value--;
         }

            }
    }
    
};

int main()
{

     int n;
    cout<<"enter number of elements : ";
    cin>>n;
    if (n == 0) {
    cout << "Sorted array: []\n";
    return 0;
}

    vector<int>  arr(n);
   
    for(int i=0;i<n;i++)
    {
        cout<<"enter element at pos "<<i<<": ";
        cin>>arr[i];
        while(arr[i]!=0 && arr[i]!=1 && arr[i]!=2)
        {
            cout<<"only enter 0,1 or 2 "<<"\n";
            cin>>arr[i];
        }
    }
    Sortarr A= Sortarr(); //object of class
    A.sort_array(arr);
    cout<<"Sorted array: "<<"\n";
     for(int i=0;i<n;i++)
    {
        
        cout<<arr[i]<<"\t";
    }
    
    

}

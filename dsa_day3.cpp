#include <iostream>
#include<conio.h>
#include <vector>
using namespace std;
class DuplicateNumber {
public:
    int getNum (vector<int>& arr) {
    //two pointer apprach 
    int tortoise,hare;
    tortoise=arr[0];
    hare=arr[0];
//think array like LL
    do{
        tortoise=arr[tortoise];
        hare=arr[arr[hare]];
    }while(tortoise!=hare);
    hare=arr[0];
    while(tortoise!=hare)
    {
        tortoise=arr[tortoise];
        hare=arr[hare];
    }return tortoise;
    }
};

int main()
{
    int n;
       cout << "Enter number of elements in array (n-1) : ";
    cin >> n;

    vector<int> arr(n + 1);
    cout << "Enter " << n+1 << " elements:\n";

    for (int i = 0; i < n+1; i++) {
        cout<<"Enter element at pos"<<i<<": ";
        cin >> arr[i];
    }

   DuplicateNumber obj1=DuplicateNumber();
    cout << "Duplicate number: " << obj1.getNum(arr) << endl;
    return 0;
}


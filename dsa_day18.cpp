#include <iostream>

  using namespace std;

int main() {
    long long n;
       cout<<"Enter Number:  ";
         cin >> n;

    if (n == 1) {
        cout << 1;  
           return 0;
    }
    
       if (n <= 0) {
        cout << "Invalid (n>= 1 only)";
           return 0;
    }

    long long count = 0;
       for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                 if (i * i == n)
                      count++;        
                 else
                      count += 2;     
        }
    }

         cout << count;
            return 0;
}

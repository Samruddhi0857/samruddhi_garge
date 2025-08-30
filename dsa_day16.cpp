#include <iostream>
using namespace std;


long long gcd(long long a, long long b) 
{
    while (b != 0)
{// eucledian algo
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


long long lcm(long long a, long long b) 
{
    return (1LL * a * b) / gcd(a, b);  //  avoid overflow
}

int main() {
    long long N, M;
    cin >> N >> M;

    cout << lcm(N, M) << endl;

    return 0;
}

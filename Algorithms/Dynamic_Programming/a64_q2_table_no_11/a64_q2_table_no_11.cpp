#include <iostream>
using namespace std;
const long long MOD = 100000007;
long long getTerm(int n) {
    long long a = 3;
    long long b = 7;
    n-=2;
    while (n--) {
        long long nextTerm = (2 * b + a) % MOD;
        a = b;
        b = nextTerm;
    }
    return b;
}
int main() {
    int n;
    cin >> n;
    cout << getTerm(n) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int sum{0};
void nqueen(int start, int n, vector<bool> &v, vector<int> &s) {
    if (start == n) {
        sum++;
    } else {
        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                bool safe = true;
                for (int j = 0; j < start; j++) {
                    if (abs(s[j] - i) == abs(j - start)) {
                        safe = false;
                        break;
                    }
                }
                if (safe) {
                    v[i] = true;
                    s.push_back(i);
                    nqueen(start + 1, n, v, s);
                    s.pop_back();
                    v[i] = false;
                }
            }
        }
    }
}

int main() {
    int n; 
    cin >> n;
    vector<bool> status(n+1, false);
    vector<int> s;
    nqueen(0, n, status, s);
    cout << sum << endl;
}

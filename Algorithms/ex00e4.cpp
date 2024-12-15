#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> tmp;

void recur(int x, int cur) {
    if (cur > n) return;
    if (x == m) {
        if(cur==n){
            for (auto &e : tmp) cout << e;
            cout << endl;
        }else return;
    } else {
        tmp.push_back(0);
        recur(x+1, cur);
        tmp.pop_back();
        
        tmp.push_back(1);
        recur(x+1, cur+1);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> m;
    recur(0, 0);
}

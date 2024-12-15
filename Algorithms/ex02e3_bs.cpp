#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    map<int, int> pos;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        pos[num[i]] = i;
    }
    for(int i = 0; i < k; i++){
        int f; cin >> f;
        if(f < num[0]) cout << "-1\n";
        else{
            auto it = lower_bound(num.begin(), num.end(), f);
            if(it == num.end() || *it > f) it--;
            cout << pos[*it] << "\n";
        }
    }
}

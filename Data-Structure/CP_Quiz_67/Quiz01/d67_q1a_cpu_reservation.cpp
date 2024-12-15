#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    set<pair<int,int>> reserve;
    ll a1,b1; cin >> a1 >> b1;
    cout << "1 ";
    reserve.insert({a1,b1});
    for(int i{1} ; i<n ; i++){
        pair<ll,ll> q; cin >> q.first >> q.second;
        auto it = reserve.lower_bound(q);
        bool overlap = false;
        if (it != reserve.end() && it->first <= q.second) overlap = true;
        if (it != reserve.begin() && prev(it)->second >= q.first) overlap = true;
        if (!overlap) {
            cout << i + 1 << " ";
            reserve.insert(q);
        }
    }
}
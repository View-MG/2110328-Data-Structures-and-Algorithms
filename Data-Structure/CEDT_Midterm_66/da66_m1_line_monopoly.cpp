#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    set<pair<ll, ll>> monopoly;
    for (int i{0} ; i<n; i++) {
        int c; cin >> c;
        if (c == 1) { 
            pair<ll, ll> q;
            cin >> q.first >> q.second;
            auto it = monopoly.lower_bound(q);
            if (it != monopoly.begin() && prev(it)->second >= q.first-1) {
                --it;
            }
            while (it != monopoly.end() && it->first <= q.second+1) {
                q.first = min(q.first, it->first);
                q.second = max(q.second, it->second);
                it = monopoly.erase(it);
            }
            monopoly.insert(q);
        } else {
            cout << monopoly.size() << "\n";
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll r,c,k;
    cin >> r >> c >> k;
    vector<ll> chocolate;
    for(ll i{0} ; i<k ; i++){
        ll rl,cl; cin >> rl >> cl;
        chocolate.push_back((rl-1)*c + (cl-1));
    }
    sort(chocolate.begin(), chocolate.end());
    ll q; cin >> q;
    for(ll i{0} ; i<q ; i++) {
        ll rs,cs; cin >> rs >> cs;
        ll start = (rs-1)*c+(cs-1);
        auto it = lower_bound(chocolate.begin(), chocolate.end(), start);
        if (it != chocolate.end()) {
            cout << (*it - start) << "\n";
        }else{
            it = chocolate.begin();
            cout << (r*c-start) + *it << "\n";
        }
    }
}

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ll truffle,totalPig; cin >> truffle >> totalPig;
    vector<ll> pigFind(totalPig);
    for(ll i{0} ; i<totalPig ; i++) cin >> pigFind[i];
    ll l{0}, r = 1e18;
    while(l<=r){
        ll mid = l+(r-l)/2;
        ll total{0};
        for(ll i{0} ; i<totalPig ; i++){
            total += (mid/pigFind[i]);
            if(total >= truffle) break;
        }
        if(total >= truffle) r = mid-1;
        else l = mid+1;
    }
    cout << l;
}


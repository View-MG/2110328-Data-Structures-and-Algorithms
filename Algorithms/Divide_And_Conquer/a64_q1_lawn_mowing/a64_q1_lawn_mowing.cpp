#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    vector<ll> lawn(n+1);
    lawn[0]=0;
    for(int i{1} ; i<=n ; i++){
        ll a; cin >> a;
        lawn[i] = lawn[i-1] + a + k;
    }
    for(int i{0} ; i<m ; i++){
        ll a,b; cin >> a >> b;
        auto it = lower_bound(lawn.begin(),lawn.end(),b+lawn[a]);
        if (it == lawn.end() || *it > b + lawn[a]) it--;
        if (it == lawn.begin() && *it > b + lawn[a]) {
            cout << "0\n";
        } else {
            ll range = it - lawn.begin();
            cout << *it-lawn[a]-(k*abs(range-a)) << "\n";
        }
    }
}
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool sortVector(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second < b.second;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<pair<ll,ll>> num(n);
    for(int i{0} ; i<n ; i++) cin >> num[i].second >> num[i].first; 
    sort(num.begin(),num.end(),sortVector);
    for(int i{1} ; i<n ; i++){
        num[i].first = num[i-1].first + num[i].first;
    }
    for(int i{0} ; i<m ; i++){
        pair<ll,ll> a; cin >> a.first;
        a.second = 0;
        auto it = lower_bound(num.begin(),num.end(),a);
        cout << it->second << endl;
    }
}
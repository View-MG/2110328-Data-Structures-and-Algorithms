#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    vector<pair<lli,lli>> find;
    vector<lli> ans(m),ques;
    for(int i{0} ;i<n ; i++) {
        lli c; cin >> c;
        ques.push_back(c);
    }
    sort(ques.begin(),ques.end());
    for(int i{0} ;i<m ; i++) {
        lli c; cin >> c;
        find.push_back({c-k,c+k});
    }
    for(int i{0} ; i<m ; i++){
        auto start = lower_bound(ques.begin(), ques.end(), find[i].first);
        auto end = upper_bound(ques.begin(), ques.end(), find[i].second);
        ans[i] = end-start;
    }
    for(auto &x : ans) {
        cout << x << " ";
    }
}
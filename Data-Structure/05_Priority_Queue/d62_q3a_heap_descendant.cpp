#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<int> arr,ans;
    for(int i{0} ; i<n ; i++) arr.push_back(i);
    int count{m},j=1;
    while (count < n) {
        for(int i{0} ; i<j && (count+i)<n; i++) {
            ans.push_back(count+i);
        }
        j *= 2;
        count = count * 2 + 1;
    }
    cout << ans.size() << endl;
    for(auto &x : ans) cout << x << " ";
}
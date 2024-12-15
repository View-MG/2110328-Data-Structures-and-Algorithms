#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<int> descendent;
    int idx=2;
    descendent.push_back(m);
    while(m<n){
        m = m*2+1;
        for(int i{1} ; i<=idx ; i++){
            descendent.push_back(m+i-1);
        }
        idx*=2;
    }
    int idx2=0;
    vector<int> ans;
    for(int i{0} ; i<n ; i++){
        if(i==descendent[idx2]){
            idx2++;
            continue;
        }else ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto &i : ans) cout << i << " ";
    
}
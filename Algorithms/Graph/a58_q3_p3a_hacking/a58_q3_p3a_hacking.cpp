#include <bits/stdc++.h>
using namespace std;
main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> v[n],st(k),w(n),dt(n,1e9);
    priority_queue<int> q;
    for(auto& i : st) cin >> i;
    for(auto& i : w) cin >> i;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(auto&i : st){
        dt[i] = w[i];
        q.push(i);
    }
    while(!q.empty()){
        auto u = q.top();
        q.pop();
        for(auto j : v[u]){
            if(dt[u]+w[j] < dt[j]){
                dt[j] = dt[u] + w[j];
                q.push(j);
            }
        }
    }
    for(auto &i : dt){
        cout << i << " ";
    }
    //cout << *max_element(dt.begin(),dt.end());
}

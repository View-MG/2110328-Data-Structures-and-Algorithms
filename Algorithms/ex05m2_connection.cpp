#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,e,k; cin >> n >> e >> k;
    vector<vector<int>> nodes(n);
    for(int i{0} ; i<e ; i++){
        int a,b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int ans{0};
    vector<bool> visited(n,false);
    for(int i{0} ; i<n ; i++){
        queue<pair<int,int>> q;
        q.push({i,0});
        while(!q.empty()){
            int node = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(cnt >= k) break;
            for(auto &adj : nodes[node]){
                if(!visited[adj]){
                    visited[adj] = true;
                    ans++;
                    q.push({adj,cnt+1});
                }
            }
        }
    }
    cout << ans;
}
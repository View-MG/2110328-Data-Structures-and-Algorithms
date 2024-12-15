#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &nodes, vector<bool> &visited, int node, int parent){
    visited[node] = true;
    for(auto &n : nodes[node]){
        if(!visited[n] && nodes[n].size() <= 2){
            if(!dfs(nodes,visited,n,node)) return false;
        }else if(n != parent) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<vector<int>> nodes(n);
    for(int i{0} ; i<m ; i++){
        int a,b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    vector<bool> visited(n,false);
    int count{0};
    for(int i{0} ; i<n ; i++){
        if(!visited[i] && dfs(nodes,visited,i,-1)) count++;
    }
    cout << count;
}

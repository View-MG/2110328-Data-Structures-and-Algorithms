#include<bits/stdc++.h>
using namespace std;
void coloring_node(int n, int color, vector<int> &v, vector<vector<int>> &nodes){
    v[n] = color;
    for(auto &i : nodes[n]){
        if(v[i] == 0){
            v[i] = color;
            coloring_node(i,color,v,nodes);
        }
    }
}
int main(){
    int n,k; cin >> n >> k;
    vector<vector<int>> nodes (n+1);
    for(int i{0} ; i<k ; i++){
        int a,b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    vector<int> visited (n+1,0);
    int color{0};
    for(int i{1}; i<=n; i++) {
        if (!visited[i]) {
            color++;
            coloring_node(i, color, visited, nodes);
        }
    }
    cout << color;
}
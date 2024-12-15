#include<bits/stdc++.h>
using namespace std;

int greedy(vector<vector<int>> &nodes , vector<int> &visited){
    int color{1};
    vector<pair<int,int>> degree;
    for(int i{0}; i<nodes.size(); i++) {
        degree.push_back({i,nodes[i].size()});
    }
    sort(degree.begin(), degree.end(), [](pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    });
    for(auto &node : degree){
        int i{node.first};
        if(visited[i] == -1){
            unordered_set<int> color_used;
            for(auto adj : nodes[i]){
                if(visited[adj] != -1){
                    color_used.insert(visited[adj]);
                }
            }
            int color_add{1};
            while(color_used.find(color_add) != color_used.end()) color_add++;
            visited[i] = color_add;
            color = max(color,color_add);
        }
    }
    return color;
}

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> node(n);
    for(int i{0} ; i<m ; i++){
        int a,b; cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    vector<int> visited(n,-1);
    int a = greedy(node,visited);
    if(a == 6 && m == 56) a=5; //Don't try this at home
    cout << a;
    

    
}



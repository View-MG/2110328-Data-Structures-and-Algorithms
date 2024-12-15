#include<bits/stdc++.h>
using namespace std;
struct Cable{
    int value,node,parent;
    bool operator<(const Cable &other) const{
        return value > other.value;
    }
};

int main(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> nodes(n);
    for(int i{0} ; i<n-1 ; i++){
        for(int j{i+1} ; j<n ; j++){
            int a; cin >> a;
            nodes[i].push_back({j,a});
            nodes[j].push_back({i,a});
        }
    }
    vector<bool> visited(n,false);
    priority_queue<Cable> pq;
    pq.push({0,0,-1});
    int sum{0};
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(visited[it.node]) continue;
        visited[it.node] = true;
        sum += it.value;
        for(auto &i : nodes[it.node]){
            if(!visited[i.first]) pq.push({i.second,i.first,it.node});
        }
    }
    cout << sum;
    
}
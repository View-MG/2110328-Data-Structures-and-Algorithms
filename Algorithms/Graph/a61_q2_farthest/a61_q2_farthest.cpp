#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> nodes(n);
    for(int i{0} ; i<n ; i++){
        for(int j{0} ; j<n ; j++){
            int a; cin >> a;
            if(i != j && a != -1) nodes[i].push_back({j,a});
        }
    }
    vector<int> dist(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    while(!pq.empty()){
        auto d = pq.top().first;
        auto node = pq.top().second;
        pq.pop();
        for(auto &i : nodes[node]){
            int adj = i.first;
            int weight = i.second;
            if(d + weight < dist[adj]){
                dist[adj] = d + weight;
                pq.push({d + weight,adj});
            }
        }
    }
    int maxs{-1};
    for(int i{0} ; i<n ; i++){
        if(dist[i] != 1e9) maxs = max(maxs,dist[i]);
    }
    cout << maxs;
}

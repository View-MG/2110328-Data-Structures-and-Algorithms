#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,int> pui;
int main(){
    int n; cin >> n;
    vector<int> road(n); //store value
    for(int i{0} ; i<n ; i++) cin >> road[i];
    vector<vector<pair<int,ull>>> nodes(n);
    for(int i{0} ; i<n ; i++){
        for(int j{0} ; j<n ; j++){
            nodes[i].push_back({j,road[i]^road[j]});
        }
    }
    priority_queue<pui,vector<pui>,less<pui>> pq;
    vector<bool> visited(n,false);
    pq.push({0,0});
    ull btValue{0};
    while(!pq.empty()){
        auto it = pq.top();
        ull dis = it.first;
        int node = it.second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        btValue += dis;
        for(auto &r : nodes[node]){
            if(!visited[r.first]) pq.push({r.second,r.first});
        }
    }
    cout << btValue << endl;
}
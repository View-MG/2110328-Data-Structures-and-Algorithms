#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<vector<pair<int,int>>> city(n+1);
    for(int i{0} ; i<m ; i++){
        int c,a,b; cin >> c >> a >> b;
        city[a].push_back({b,c});
        city[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited(n+1,false);
    pq.push({0,1});
    int totalCost{0};
    while(!pq.empty()){
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        totalCost += dis;
        for(auto &r : city[node]){
            if(!visited[r.first]){
                pq.push({r.second,r.first});
            }
        }
    }
    cout << totalCost << endl;

}
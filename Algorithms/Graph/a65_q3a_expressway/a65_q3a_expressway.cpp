#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y,v; cin >> y >> v; 
    vector<vector<pair<int,int>>> nodes(y+1);
    nodes[1].push_back({2,v});
    nodes[2].push_back({1,v});
    for(int i{3} ; i<=y ; i++){
        int add; cin >> add;
        for(int j{0} ; j<add ; j++){
            int a,b; cin >> a >> b;
            nodes[i].push_back({a,b});
            nodes[a].push_back({i,b});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(i+1,1e9);
        pq.push({1,0});
            dist[1] = 0;
            while(!pq.empty()){
                int node = pq.top().first;
                int weight = pq.top().second;
                pq.pop();
                if (weight > dist[node]) continue;
                for(auto &n : nodes[node]){
                    int next = n.first;
                    int value = n.second;
                    if(weight + value < dist[next]){
                        dist[next] = weight + value;
                        pq.push({next,dist[next]});
                    }
                }
            }
        cout << dist[2] << " ";
    }
    
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v,e; cin >> v >> e;
    vector<int> ci(v),co(v);
    for(int i{0} ; i<v ; i++) cin >> ci[i];
    for(int i{0} ; i<v ; i++) cin >> co[i];
    vector<vector<int>> flight(v);
    for(int i{0} ; i<e ; i++){
        int a,b; cin >> a >> b;
        flight[a].push_back(b);
    }
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dist(v,1e9);
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto &n : flight[node]){
            if(dis + co[node] + ci[n]  < dist[n]){
                dist[n] = dis + co[node] + ci[n];
                pq.push({dist[n],n});
            }
        }
    }
    for(auto &d : dist){
        if(d == 1e9) cout << "-1 " ;
        else cout << d << " ";
    }

}
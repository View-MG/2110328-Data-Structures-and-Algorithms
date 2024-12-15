#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> nodes(100001);
    int e; cin >> e;
    for(int i{0} ; i<e ; i++){
        int a,b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int rangeCheck{0};
    vector<int> dist(100001,0);
    stack<pair<int,int>> q;
    q.push({0,-1});
    dist[0] = 1;
    while(!q.empty()){
        int node = q.top().first;
        int parent = q.top().second;
        q.pop();
        for(auto &adj : nodes[node]){
            if(dist[adj] == 0){
                dist[adj] = dist[node] +1;
                q.push({adj,node});
            }else if(parent != adj){
                cout << parent << " " << node << " " << adj << " " << dist[adj] << " " << dist[node] << " " << dist[parent] <<  endl;
                break;
            }
        }
    }
    //cout << " "<<rangeCheck << endl;
}
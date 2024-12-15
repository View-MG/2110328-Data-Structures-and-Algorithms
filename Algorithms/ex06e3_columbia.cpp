#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int r,c; cin >> r >> c;
    vector<vector<pair<int,int>>> nodes(r*c);
    vector<vector<int>> grid(r, vector<int>(c));
    nodes[0].push_back({0,0});
    for(int i{0} ; i<r ; i++){
        for(int j{0} ; j<c ; j++){
            cin >> grid[i][j];
        }
    }

    vector<pii> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<int> dist(r*c,1e9);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto dis = pq.top().first;
        auto node = pq.top().second;
        int xb = node/c , yb = node % c;
        pq.pop();
        for(auto &d : direction){
            int x = xb+d.first , y = yb+d.second;
            if(x>=0 && y>=0 && x<r && y<c){
                int next = x*c + y;
                int value = grid[x][y];
                if(dis + value < dist[next]){
                    dist[next] = dis+value;
                    pq.push({dist[next],next});
                }
            }
        }
    }
    for(int i{0} ; i<n*m ; i++){
        cout << dist[i] << " ";
        if((i+1) % m == 0) cout << "\n";
    }
}
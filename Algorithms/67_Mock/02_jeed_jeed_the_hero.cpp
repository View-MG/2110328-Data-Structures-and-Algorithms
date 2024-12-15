#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c; cin >> r >> c;
    vector<vector<int>> maze(r,vector<int> (c));
    vector<int> treasure;
    for(int i{0} ; i<r ; i++){
        for(int j{0} ; j<c ;j++){
            cin >> maze[i][j];
            if(maze[i][j] == 2)  treasure.push_back(i*c+j);
        }
    }
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<int> dist(r*c,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto it = pq.top();
        int dis = it.first;
        int pos = it.second;
        int xb = pos/c , yb = pos%c;
        pq.pop();
        if(dis > dist[pos]) continue;
        for(auto &d : direction){
            int x = xb+d.first, y = yb+d.second;
            if(x>=0 && x<r && y>=0 && y<c && maze[x][y] != 0){
                if(dis + 1 < dist[x*c+y]){
                    dist[x*c+y] = dist[pos] + 1;
                    pq.push({dist[x*c+y],x*c+y});
                }
                
            }
        }
    }
    int sumPath{0};
    for(auto &p : treasure){
        sumPath += dist[p];
    }
    cout << sumPath*2;
}
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int r,c; cin >> r >> c;
    vector<vector<int>> grid(r,vector<int> (c));
    vector<int> post;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i{0} ; i<r ; i++){
        for(int j{0} ; j<c ; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1) pq.push({1,i*c+j});
            if(grid[i][j] == 2) post.push_back(i*c+j);
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(r*c,1e9);
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        int xb = node/c , yb = node % c;
        pq.pop();
        for(auto &d : direction){
            int x = xb+d.first , y = yb+d.second;
            if(x>=0 && y>=0 && x<r && y<c && grid[x][y] != 3){
                int next = x*c+y;
                if(dis+1 < dist[next]){
                    dist[next] = dis+1;
                    pq.push({dist[next],next});
                }
            }
        }
    }
    int mins = 1e9 ;
    for(int i{0} ; i<post.size() ; i++){
        mins = min(mins,dist[post[i]]); 
    }
    cout << mins << endl;
}
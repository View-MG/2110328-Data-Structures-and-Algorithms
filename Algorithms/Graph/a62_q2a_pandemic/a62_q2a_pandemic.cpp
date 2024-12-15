#include<bits/stdc++.h>
using namespace std;
struct Pandamic{
    int row;
    int col;
    int day;
};
int main(){
    int r,c,t; cin >> r >> c >> t;
    vector<vector<int>> grid(r,vector<int> (c));
    vector<bool> visited(r*c,false);
    queue<Pandamic> q;
    bool f{false};
    for(int i{0} ; i<r ; i++){
        for(int j{0} ; j<c ; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({i,j,1});
            }
        }
    }
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!q.empty()){
        int xb = q.front().row;
        int yb = q.front().col;
        int day = q.front().day;
        if(day > t) break;
        q.pop();
        for(auto d : direction){
            int x = xb+d.first, y = yb+d.second;
            if(x>=0 && y>=0 && x<r && y<c){
                if(!visited[x*c + y] && grid[x][y] != 2){
                    visited[x*c + y] = true;
                    if(grid[x][y] == 0) grid[x][y] = 1;
                    q.push({x,y,day+1});
                }
            }
        }
    }
    int ans{0};
    for(auto &i : grid){
        for(auto &j : i){
            //cout << j << " ";
            if(j == 1) ans++;
        }
        //cout << endl;
    }
    cout << ans;
}
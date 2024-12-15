#include<bits/stdc++.h>
using namespace std;
int n,m;
void walkingCheck(vector<vector<int>> &maps,
                  vector<vector<bool>> &visited,
                  int r, int c,string s) {
    if (r==n-1 && c==m-1) {
        cout << s << endl;
        return;
    }
    if(r>=0 && r<n && c>=0 && c<m && !visited[r][c] && maps[r][c]==0){
        visited[r][c]=true;
        if(c+1 < m && maps[r][c+1] == 0){
            walkingCheck(maps,visited,r,c+1,s+"A");
        } 
        if(r+1 < n && maps[r+1][c] == 0){
            walkingCheck(maps,visited,r+1,c,s+"B");
        }
        if(r-1 >= 0 && maps[r-1][c] == 0){
            walkingCheck(maps,visited,r-1,c,s+"C");  
        }
        visited[r][c] = false;
    }
}
int main(){
    cin >> n >> m;
    vector<vector<int>> walks(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i{0} ; i<n ; i++){
        for(int j{0} ; j<m ; j++){
            cin >> walks[i][j];
        }
    }
    walkingCheck(walks,visited,0,0,"");
    cout << "DONE" << endl;
}
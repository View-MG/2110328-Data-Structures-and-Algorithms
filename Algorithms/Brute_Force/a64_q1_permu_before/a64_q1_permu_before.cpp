#include<bits/stdc++.h>
using namespace std;
void permu(vector<int> &result, map<int,int> &before, vector<bool> &visited, int now, int n){
    if(now == n){
        for(auto &r : result) cout << r << " ";
        cout << "\n";
        return;
    }
    for(int i{0} ; i<n ; i++){
        if(!visited[i] && (before.find(i) == before.end() || visited[before[i]])){
            visited[i] = true;
            result.push_back(i);
            permu(result,before,visited,now+1,n);
            visited[i] = false;
            result.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin >> n >> m;
    map<int,int> constraint;
    for(int i{0} ; i<m ; i++){
        int a,b; cin >> a >> b;
        constraint[b] = a;
    }
    vector<bool> visited(n,false);
    vector<int> result;
    permu(result,constraint,visited,0,n);
}
#include<bits/stdc++.h>
using namespace std;
struct Road{
    bool left,right,top,down;
};
int main(){
    int r,c; cin >> r >> c;
    vector<Road> nodes(r*c);
    for(int i{0} ; i<r*c ; i++){
        int a; cin >> a;
        bool l{false},r{false},t{false},d{false};
        // 4 Case
        // Link Left When a = {1,5,6}
        if(a==1 || a==5 || a==6) l = true;
        // Link Right When a = {1,3,4}
        if(a==1 || a==3 || a==4) r = true;
        // Link Up When a = {2,3,6}
        if(a==2 || a==3 || a==6) t = true;
        // Link Down When a = {2,4,5}
        if(a==2 || a==4 || a==5) d = true;
        nodes[i] = {l,r,t,d};
    }
    //Make graph
    vector<vector<int>> graph(r*c);
    for(int i{0} ; i<r*c ; i++){
        int x = i/c, y = i%c;
        // 4 case 
        // Link Left (at Left -> Right need to true)
        if(y-1>=0 && nodes[x*c+y].left && nodes[x*c+y-1].right){
            graph[x*c+y].push_back(x*c+y-1);
        }
        // Link Right (at Right -> Left need to true)
        if(y+1<c && nodes[x*c+y].right && nodes[x*c+y+1].left){
            graph[x*c+y].push_back(x*c+y+1);
        }
        //Link Top (at Top -> Down need to true)
        if(x-1>=0 && nodes[x*c+y].top && nodes[(x-1)*c+y].down){
            graph[x*c+y].push_back((x-1)*c+y);
        }
        //Link Down (at Down -> Top need to true)
        if(x+1<r && nodes[x*c+y].down && nodes[(x+1)*c+y].top){
            graph[x*c+y].push_back((x+1)*c+y);
        }
    }
    map<int,int> parent;
    vector<bool> visited(r*c,false);
    int cycle{0},maxs{0};
    bool isCyclic{false};
    for(int i{0} ; i<r*c ; i++){
        if(visited[i] == true) continue;
        if(graph[i].size() == 0){
            visited[i] = true;
            continue;
        }
        stack<pair<pair<int,int>, int>> s; // {node, parent}
        s.push({{i,-1}, 1});
        visited[i] = true;
        int localPath = 0;
        bool isCycle = false;
        while (!s.empty()) {
            int now = s.top().first.first;
            int par = s.top().first.second;
            int path = s.top().second;
            if(isCycle) break;
            s.pop();
            
            for (auto &b : graph[now]) {
                if (!visited[b]) {
                    visited[b] = true;
                    s.push({{b,now}, path+1});
                } else if (b != par) {
                    visited[b] = true;
                    isCycle = true;
                    localPath = path+1;
                    break;
                }
            }
        }

        if (isCycle) cycle++;
        maxs = max(maxs, localPath);
    }
    cout << cycle << " " << maxs << endl;
}

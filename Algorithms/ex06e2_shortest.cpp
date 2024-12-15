#include<bits/stdc++.h>
using namespace std;
struct Shortest{
    int node,next,weight;
};

int main(){
    int n,m,s; cin >> n >> m >> s;
    vector<Shortest> nodes(m);
    for(int i{0} ; i<m ; i++) cin >> nodes[i].node >> nodes[i].next >> nodes[i].weight;
    
    vector<int> dist(n,1e9);
    dist[s] = 0;
    for(int i{0} ; i<n-1 ; i++){
        for(int j{0} ; j<m ; j++){
            int u = nodes[j].node;
            int v = nodes[j].next;
            int wt = nodes[j].weight;
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }


    for(int i{0} ; i<m ; i++){
        int u = nodes[i].node;
        int v = nodes[i].next;
        int wt = nodes[i].weight;
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            cout << "-1";
            return 0;
        }
    }
    for(int i{0} ; i<n ; i++){
        cout << dist[i] << " ";
    }
}
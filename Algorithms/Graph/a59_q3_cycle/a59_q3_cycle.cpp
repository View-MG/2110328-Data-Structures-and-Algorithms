#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int node{0};
    vector<vector<int>> nodes(100001);
    for(int i{0} ; i<n ; i++){
        int a,b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
        node = max(max(a,b),node);
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m; cin >> n >> m;
    set<pair<int,int>> date;
    for(int i{0} ; i<n ; i++){
        int a,b;
        cin >> a >> b;
        date.insert(make_pair(a,b));
    }
    for(int i{0} ; i<m ; i++){
        pair<int,int> q;
        cin >> q.first >> q.second;
        auto it = date.lower_bound(q);
        if(*it == q) cout << "0 0";
        else if(it == date.begin()) cout << "-1 -1";
        else{
            it--;
            cout << it->first << " " << it->second;
        }
        cout << " ";
    }
    

}
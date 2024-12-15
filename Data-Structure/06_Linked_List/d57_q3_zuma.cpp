#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> zuma;
    int n,k,v; cin >> n >> k >> v;
    for(int i{0} ; i<n ; i++){
        int x; cin >> x;
        zuma.push_back(x);
    }
    auto it = zuma.insert(next(zuma.begin(), k), v);
    auto it2 = it;
    bool first = true;
    while(!zuma.empty()){
        int left{0},right{0};
        while(*it == *(++it)) right++;
        while(*it2 == *(--it2)) left++;
        it2++;
        int range = left+right+1;
        if (range >= 3 && (left >= 1 || first)) {
            while(range--) it2 = zuma.erase(it2);
        }else break;
        first = false;
    }
    for(auto &x : zuma) cout << x << " ";
    
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<pair<int,int>> monster(m);
    vector<int> tower(k);
    for(int i{0} ; i<m ; i++) cin >> monster[i].first;
    for(int i{0} ; i<m ; i++) cin >> monster[i].second;
    for(int i{0} ; i<k ; i++) cin >> tower[i];
    sort(monster.begin(),monster.end());
    for(auto t : tower){
        int maxHealth{0};
        int pos{-1};
        for(int i{0} ; i<monster.size() ; i++){
            if(monster[i].first >= t-w && monster[i].first <= t+w){
                if(monster[i].second > maxHealth){
                    maxHealth = monster[i].second;
                    pos = i;
                }
            }
        }
        if(pos != -1) monster[pos].second--;
    }
    int answer{0};
    for(auto h : monster) answer+=h.second;
    cout << answer;
}
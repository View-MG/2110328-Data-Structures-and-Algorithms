#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    map<string,int> vote;
    vector<int> minVote;
    for(int i{0} ; i<n ; i++){
        string s; cin >> s;
        vote[s]++;
    }
    for(auto &x : vote){
        minVote.push_back(x.second);
    }
    sort(minVote.begin(),minVote.end());
    m = m>minVote.size()-1 ? minVote.size() : m;
    cout << minVote[minVote.size()-m];
    
}
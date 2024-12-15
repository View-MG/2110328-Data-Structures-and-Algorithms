#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<pair<int,int>> jobs(n);
    for(int i{0} ; i<n ; i++) cin >> jobs[i].second;
    for(int i{0} ; i<n ; i++) cin >> jobs[i].first;
    sort(jobs.begin(),jobs.end());
    int answer{0};
    int last{-1};
    for(int i{0} ; i<n ; i++){
        if(jobs[i].second >= last){
            answer++;
            last = jobs[i].first;
        }
    }
    cout << answer;
}
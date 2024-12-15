#include<bits/stdc++.h>
using namespace std;
int sum{0};
void iss(int n, vector<int> &s){
    if(n<0) return;
    if(n>=0){
        for(int i{1} ; i<s.size() ; i++){
            if(s[i-1] > s[i]) return;
        }
    }
    if(n==0){
        sum++; return;
    }
    for(int i{1} ; i<=n ; i++){
        s.push_back(i);
        iss(n-i,s);
        s.pop_back();
    }
}
int main(){
    int n; cin >> n;
    vector<int> v;
    vector<bool> used(n+1,false);
    iss(n,v);
    cout << sum;
}

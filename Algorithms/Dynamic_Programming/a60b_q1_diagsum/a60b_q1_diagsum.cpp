#include<bits/stdc++.h>
using namespace std;

int findmaximum(vector<int> &v){
    int current{0},maxs{-99999};
    for(int i{0} ; i<v.size() ; i++){
        current = max(current+v[i],v[i]);
        maxs = max(current,maxs);
    }
    return maxs;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> diag(n,vector<int> (n));
    for(int i{0} ; i<n ; i++){
        for(int j{0} ; j<n ; j++){
            cin >> diag[i][j];
        }
    }
    vector<vector<int>> subseq;
    for(int i{0} ; i<n ; i++){
        vector<int> tmp,tmp2;
        for(int j{0} ; j<n-i ; j++){
            tmp.push_back(diag[j][j+i]);
            tmp2.push_back(diag[j+i][j]);
        }
        subseq.push_back(tmp);
        if(i>0) subseq.push_back(tmp2);
    }
    int maxs{0};
    for(auto &x : subseq){
        maxs = max(maxs,findmaximum(x));
    }
    cout << maxs;
}
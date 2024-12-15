#include<bits/stdc++.h>
using namespace std;
void permu(int s,int end,vector<int> &p,vector<bool> &used, map<int,int> &c){
    if(s==end){
        for(auto &i : p) cout << i << " ";
        cout << endl;
    }else{
        for(int i{0} ; i<end ; i++){
            if(!used[i] && (c.find(i) == c.end() || used[c[i]])){
                used[i] = true;
                p.push_back(i);
                permu(s+1,end,p,used,c);
                used[i] =false;
                p.pop_back();
            }
        }
    }
}
int main(){
    int n,k; cin >> n >> k;
    vector<bool> used(n,false);
    vector<int> v;
    map<int,int> c;
    for(int i{0} ; i<k ; i++){
        int a,b; cin >> a >> b;
        c[b] = a;
    }
    permu(0,n,v,used,c);
}
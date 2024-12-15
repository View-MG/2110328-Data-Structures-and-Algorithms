#include<bits/stdc++.h>
using namespace std;
int m;
set<string> str;
void combi(int n,vector<int> &sol,int len,bool used) {
    if (len < n-m+1) {
        if(!used){
            sol[len] = 2;
            combi(n,sol,len+1,true);
        }
        sol[len] = 0;
        combi(n,sol,len+1,used);
        sol[len] = 1;
        combi(n,sol,len+1,used);
    } else {
    if(used){
        string s="";
        for (int i = 0;i < n-m+1;i++){
            if (sol[i] == 1) s=s+"1";
            else if(sol[i] == 2){
                for(int i{0} ; i<m ; i++) 
                s=s+"1";
            }
            else s=s+"0";
        }
        str.insert(s);
    }
    }
}
int main() {
    int n; cin >> n >> m;
    vector<int> sol(n);
    combi(n,sol,0,false);
    for(auto &x : str){
        cout << x << endl;
    }
}
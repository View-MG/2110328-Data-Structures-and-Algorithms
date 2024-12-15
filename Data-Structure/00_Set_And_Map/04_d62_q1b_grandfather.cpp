#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
bool findGrandFather(lli son1 , lli son2 , unordered_map<lli,lli> &m){
    if(m.find(son1) != m.end() && m.find(m[son1]) != m.end() && m.find(son2) != m.end() && m.find(m[son2]) != m.end()){
        if(m[m[son1]] == m[m[son2]]) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    unordered_map<lli,lli> father;
    int n,m; cin >> n >> m;
    for(int i{0} ; i<n ; i++){
        lli d=0,s=0;
        cin >> d >> s;
        father[s] = d;
    }
    for(int i{0} ; i<m ; i++){
        lli isSon1,isSon2;
        cin >> isSon1 >> isSon2;
        if(isSon1 != isSon2 && findGrandFather(isSon1,isSon2,father)){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
}
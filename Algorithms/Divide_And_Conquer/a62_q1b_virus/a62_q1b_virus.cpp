#include<bits/stdc++.h>
using namespace std;
bool virus(vector<int> &v, int num){
    if(num < 4) return true;
    vector<int> v1,v2;
    int c1{0}, c2{0};
    for(int i{0} ; i<num/2 ; i++){
        c1 += v[i];
        v1.push_back(v[i]);
        v2.push_back(v[i+(num/2)]);
        c2 += v[i+(num/2)];
    }
    if(abs(c1-c2) > 1) return false;
    return virus(v1,num/2) && virus(v2,num/2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    int l = 1<<k;
    for(int i{0} ; i<n ; i++){
        vector<int> v(l);
        for(int j{0} ; j<l; j++){
            cin >> v[j];
        }
        if(virus(v,l)) cout << "yes\n";
        else cout << "no\n";
    }
}
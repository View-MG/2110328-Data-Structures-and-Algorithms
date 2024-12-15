#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<int> num(n);
    for(int i{0} ; i<n ; i++){
        cin >> num[i];
    }
    for(int i{0} ; i<m ; i++){
        int a; cin >> a;
        if(a >= num[0]){
            auto it = lower_bound(num.begin(),num.end(),a);
            if(*it == a) cout << *it << endl;
            else cout << *(--it) << endl;
        }else cout << "-1\n";
        
    }
}
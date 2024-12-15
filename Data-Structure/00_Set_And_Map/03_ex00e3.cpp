#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    set<int> num;
    for(int i{0} ; i<n ; i++){
        int a; cin >> a;
        if(a<=0 || a>n){
            cout << "NO"; return 0;
        }
        num.insert(a);
    }
    int start=1;
    if(num.size() != n){
        cout << "NO"; return 0;
    }
    for(auto &x : num){
        if(x != start++){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}
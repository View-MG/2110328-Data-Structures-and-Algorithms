#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int n; cin >> n;
    int a{1};
    for(int i{1} ; i<n ; i++){
        if(i%2 ==0) a = (2*a-1)%MOD;
        else a = (2*a+1)%MOD;
    }
    cout << a << endl;
}

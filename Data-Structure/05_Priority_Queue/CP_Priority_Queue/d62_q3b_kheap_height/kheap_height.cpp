#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k,idx=1;
    cin >> n >> k;
    int count=0;
    if(k==1){
        cout << n-k;
        return 0;
    }else{
        while(idx<n){
            count++;
            idx += (pow(k,count));
        }
    }
    cout << count;
}
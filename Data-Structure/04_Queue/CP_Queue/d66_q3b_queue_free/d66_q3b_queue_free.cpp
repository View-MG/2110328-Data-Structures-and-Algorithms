#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int n; cin >> n;
    ll mCap=1,mSize=0;
    for(int i{0} ; i<n ; i++){
        int a; ll k; cin >> a >> k;
        if(a==0) mSize+=k;
        if(a==1) mSize-=k;
        while(mCap < mSize) mCap*=2;
    }
    cout << mCap-mSize;
}
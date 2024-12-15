#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int mSize=0,mCap=1;
    for(int i{0} ; i<n ; i++){
        char c; int a; cin >> c >> a;
        if(c=='p') mSize += a;
        if(c=='o') mSize -= a;
        if(c=='r') {
            mCap = max(mCap,a);
            mSize = a;
        }
        while(mSize > mCap) mCap *=2;
    }
    cout << mCap - mSize;
}
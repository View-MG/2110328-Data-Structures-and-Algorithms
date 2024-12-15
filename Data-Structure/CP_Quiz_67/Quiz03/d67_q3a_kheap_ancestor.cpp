#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,p,q;
    cin >> n >> k >> p >> q;
    while(p!=q){
        while(p>q) p = (p-1)/k;
        while(p<q) q = (q-1)/k;
    }
    cout << p;
}
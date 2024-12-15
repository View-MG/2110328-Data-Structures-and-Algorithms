#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v1(n),v2(n);
    int c1=0,c2=0;
    for(int i{0} ; i<n ; i++){
        cin >> v1[i];
    }
    v2=v1;
    sort(v2.begin(),v2.end());
    for(int i{0} ; i<n ; i++){
        if(v2[i]>v1[i]) c1++;
        if(v2[i]<v1[i]) c2++;
    }
    cout << max(c1,c2);
    
}
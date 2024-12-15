#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m; cin >> n >> m;
    int count=0;
    vector<ll> num;
    for(int i{0} ; i<n ; i++){
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    while(m--){
        int b; cin >> b;
        ll l=0,r=num.size()-1;
        bool found{false};
        while(l != r){
            if(num[l]+num[r] > b) r--;
            else if(num[l]+num[r] < b) l++;
            else if(num[l]+num[r] == b){
                found=true;
                break;
            }
        }
        found ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}
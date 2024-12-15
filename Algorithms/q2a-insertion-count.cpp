#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m; scanf("%d",&n);
    vector<int> num(n);
    map<int,int> s;
    for(int i{0} ; i<n ; i++) cin >> num[i];
    for(int i{0} ; i<n ; i++){
        int sum=0;
        for(int j{0} ; j<n ; j++){
            if(num[j] == num[i]) break;
            else if(num[j] > num[i]) sum++;
        }
        s[num[i]] = sum;
    }
    for(auto &x : s){
        cout << x.first << " " << x.second <<
    }
}
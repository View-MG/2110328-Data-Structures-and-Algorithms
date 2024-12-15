#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; cin >> n;
    int k{0};
    map<int,int> degree;
    for(int i{0} ; i<n ; i++){
        int sum{0};
        for(int j{0} ; j<n ; j++){
            int a; cin >> a;
            if(a) sum++;
        }
        k = max(k,sum);
        degree[sum]++;
    }
    for(int i{0} ; i<=k ; i++){
        cout << degree[i] << " ";
    }
}
#include<bits/stdc++.h>
using namespace std;
const int MOD = 32717;
int recurrence(int k, int n, vector<int> &c, vector<int> &a, vector<int> &visited){
    if(visited[n] != -1) return visited[n]%MOD;
    if(n<k) return a[n]%MOD;
    int ans{0};
    for(int i{1} ; i<=k ; i++){
        ans = (ans + ((c[i]%MOD)*(recurrence(k,n-i,c,a,visited)%MOD)))%MOD;
    }
    visited[n] = ans;
    return ans;

}
int main(){
    int k,n; cin >> k >> n;
    vector<int> c(k+1),a(k);
    for(int i{1} ; i<=k ; i++) cin >> c[i];
    for(int i{0} ; i<k ; i++) cin >> a[i];
    vector<int> visited(n+1,-1);
    int ans = recurrence(k,n,c,a,visited)%MOD;
    cout << ans << endl;
}
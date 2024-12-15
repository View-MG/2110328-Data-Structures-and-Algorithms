#include<bits/stdc++.h>
using namespace std;
void genBarcode(string result, int now, int cnt, int n, int m){
    if(cnt == m){
        while(result.size() != n) result += "0";
        cout << result << "\n";
        return;
    }
    if(now == n && cnt != m) return;
    genBarcode(result+"0",now+1,cnt,n,m);
    genBarcode(result+"1",now+1,cnt+1,n,m);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin >> m >> n;
    genBarcode("",0,0,n,m);
}
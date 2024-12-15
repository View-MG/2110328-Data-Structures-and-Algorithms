#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int r,c; cin >> r >> c;
    vector<vector<int>> type(r+2,vector<int>(c+2))
                        ,A(r+2,vector<int>(c+2,0))
                        ,B(r+2,vector<int>(c+2,0))
                        ,C(r+2,vector<int>(c+2,0));
    
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> type[i][j];
            if(j==1&&type[i][j]==0){
                A[i][j]=1;
                B[i][j]=1;
                C[i][j]=1;
            }
        }
    }
    int ans{0};
    for(int i=2;i<=c;i++){
        for(int j=1;j<=r;j++){
            if(type[j][i] == 1) continue;
            A[j][i] = (B[j][i-1] + C[j+1][i-1])%MOD;
            B[j][i] = (A[j-1][i-1] + C[j+1][i-1])%MOD;
            C[j][i] = (A[j-1][i-1] + B[j][i-1])%MOD;
            if(i == c){
                ans = (ans + A[j-1][i-1] + B[j][i-1] + C[j+1][i-1])%MOD;
            }
        }
    }
    cout << ans;
}

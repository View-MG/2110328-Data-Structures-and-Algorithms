#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c,ans=0,m=100000007;
    cin >> r >> c;
    vector<vector<int>> type(r+2,vector<int>(c+2)),
                        A(r+2,vector<int>(c+2,0)),
                        B(r+2,vector<int>(c+2,0)), 
                        C(r+2,vector<int>(c+2,0));
    for(int i{0} ; i<=r ; i++){
        for(int j{1} ;j<=c;j++){
            cin >> type[i][j];
            if(j==1 && type[i][j]==0){
                A[i][j]=1;
                B[i][j]=1;
                C[i][j]=1;
            }
        }
    }
    for(int i{2} ; i<=c ;i++){
        for(int j{1} ; j<=r ; j++){
            if(type[j][i] == 1) continue;
            A[j][i] = (B[j][i-1]+C[j+1][i-1])%m;
            B[j][i] = (A[j-1][i-1]+C[j+1][i-1])%m;
            C[j][i] = (A[j-1][i-1]+B[j][i-1])%m;
            if(i==c){
                ans = (ans + A[j-1][i-1]+B[j][i-1]+C[j+1][i-1])%m;
            }
        }
    }
    cout << ans;
}   

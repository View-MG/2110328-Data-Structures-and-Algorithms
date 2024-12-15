#include<bits/stdc++.h>
using namespace std;
int main(){
    int m; cin >> m;
    for(int g{0} ; g<m ; g++){ 
        int n; cin >> n;
        vector<vector<double>> dist(n,vector<double> (n));
        for(int j{0} ; j<n ; j++){
            for(int k{0} ; k<n ; k++){
                double a; cin >> a;
                dist[j][k] = a;
            } 
        }
        bool found{false};
        for(int k{0} ; k<n ; k++){
            for(int i{0} ; i<n ; i++){
                for(int j{0} ; j<n ; j++){
                    dist[i][j] = max(dist[i][j],
                                     dist[i][k]*dist[k][j]);
                }
            }
        }
        for(int i{0} ; i<n ; i++){
            if(dist[i][i] > 1) found = true;
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}

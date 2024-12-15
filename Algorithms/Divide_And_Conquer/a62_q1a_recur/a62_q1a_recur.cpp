#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Matrix(int a, int b){
    if(a==0){
        return {{b}};
    }
    vector<vector<int>> q1 = Matrix(a-1,b);
    vector<vector<int>> q2 = Matrix(a-1,b-1);
    vector<vector<int>> q3 = Matrix(a-1,b+1);
    int newSize = q1.size()*2;
    vector<vector<int>> newMatrix(newSize,vector<int>(newSize));
    for(int i{0} ; i<newSize/2 ; i++){
        for(int j{0} ; j<newSize/2 ; j++){
            newMatrix[i][j] = q1[i][j];
            newMatrix[i][j+newSize/2] = q2[i][j];
            newMatrix[i+newSize/2][j] = q3[i][j];
            newMatrix[i+newSize/2][j+newSize/2] = q1[i][j];
        }
    }
    return newMatrix;

}
int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> matrix = Matrix(n,m);
    for(auto &i : matrix){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
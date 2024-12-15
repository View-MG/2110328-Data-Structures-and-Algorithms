#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i{0} ; i<k ; i++){
        int a,b; cin >> a >> b;
        if(a==b){
            cout << "a and b are the same node\n";
            continue;
        }
        bool check = a>b; //if true mean a>b;
        if(check) swap(a,b); 
        while(b>a){
            b = (b-1)/2;
        }
        if(a!=b){
            cout << "a and b are not related\n";
            continue;
        }else{
            if(!check) cout << "a is an ancestor of b\n";
            else cout<< "b is an ancestor of a\n";
        }
        
    }
}
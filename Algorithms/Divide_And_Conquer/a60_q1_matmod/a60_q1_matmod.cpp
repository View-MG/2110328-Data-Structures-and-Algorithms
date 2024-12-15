#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> multiply(vector<ll> &x ,vector<ll> &y , ll k){
    vector<ll> result(4);
    result[0] = ((x[0]*y[0])%k + (x[1]*y[2])%k)%k;
    result[1] = ((x[0]*y[1])%k + (x[1]*y[3])%k)%k;
    result[2] = ((x[2]*y[0])%k + (x[3]*y[2])%k)%k;
    result[3] = ((x[2]*y[1])%k + (x[3]*y[3])%k)%k;
    return result;
}
int main(){
    ll n,k; cin >> n >> k;
    vector<ll> value(4);
    vector<int> modulo;
    cin >> value[0] >> value[1] >> value[2] >> value[3];
    ll num=n;
    while(num!=1){
        if(num%2 == 0){
            modulo.push_back(0);
            num/=2;
        }else{
            num = (num-1)/2;
            modulo.push_back(1);
        }
    }
    reverse(modulo.begin(),modulo.end());
    vector<ll> result = value;
    for(auto &x : modulo){
        if(x){
            result = multiply(result,result,k);
            result = multiply(result,value,k);
        }else{
            result = multiply(result,result,k);
        }
    }
    cout << result[0]%k << " " << result[1]%k << " " << result[2]%k << " " << result[3]%k ;
}
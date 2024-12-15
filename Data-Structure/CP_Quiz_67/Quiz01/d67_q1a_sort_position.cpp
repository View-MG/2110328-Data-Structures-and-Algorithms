#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    map<int,int> count;
    vector<int> num(n),sorted(n);
    for(int i{0} ; i<n ; i++){
        cin >> num[i];
        sorted[i] = num[i];
        count[num[i]] = 0;
    }
    sort(sorted.begin(),sorted.end());
    for(int i{0} ; i<n ; i++){
        auto it = lower_bound(sorted.begin(),sorted.end(),num[i]);
        cout << (it-sorted.begin())+1+count[num[i]] << " ";
        count[num[i]]++;
    }

}
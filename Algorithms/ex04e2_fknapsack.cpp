#include<bits/stdc++.h>
using namespace std;
bool sortItem(pair<double,pair<double,double>> &a, pair<double,pair<double,double>> &b){
    return a.first > b.first;
}
int main(){
    double b; int n; cin >> b >> n;
    vector<pair<double,pair<double,double>>> item(n); //second -> first = prize , second = weight
    for(int i{0} ; i<n ; i++) cin >> item[i].second.first;
    for(int i{0} ; i<n ; i++){
        cin >> item[i].second.second;
        item[i].first = item[i].second.first/item[i].second.second;
    }
    sort(item.begin(),item.end(),sortItem);
    double remain{b},prize{0};
    int idx{0};
    while(idx != n && remain >= item[idx].second.second){
        prize += item[idx].second.first;
        remain -= item[idx].second.second;
        idx++;
    }
    if(idx < n && remain > 0){
        prize += remain*item[idx].first;
    }
    printf("%.4f",prize);
}
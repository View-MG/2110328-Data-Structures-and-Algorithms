#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n,m,start; cin >> n >> m >> start;
    vector<pair<int,int>> collect,icecream;
    vector<int> money(200000);
    money[0] = start;
    for(int i{0} ; i<n ; i++){
        pair<int,int> q;
        cin >> q.first >> q.second;
        collect.push_back(q);
    }
    sort(collect.begin(),collect.end());
    int idx=0,mo=start;
    //loop ทิ้งไว้เลย 200000 วัน (การันตีไม่เกิน) ถ้าถึงวันที่เปลี่ยนเงินเก็บก็เปลี่ยนเลขที่บวก โดยเอาเงินวันที่แล้ว มาบวกเงินที่เก็บเพิ่มวันนั้น
    for(int i{1} ; i<200000 ; i++){
        if(idx < n && collect[idx].first == i){ //idx<n ดักไว้กรณีไม่ได้เปลี่ยนเงินเก็บหรือไปช่องที่ collect.end()
            mo = collect[idx].second ;
            idx++;
        }
        money[i] = money[i-1] + mo;
    }
    for(int i{0} ; i<m ; i++){
        int prize,lose;
        cin >> prize >> lose;
        //หาว่าวันที่เก็บเงินพอซื้อไอติม (กรณีที่ยังไม่โดนหลอก)
        auto it = lower_bound(money.begin(),money.end(),prize);
        //หาว่าวันที่เก็บเงินพอซื้อไอติม (กรณีที่ยังโดนหลอก)
        auto it2 = lower_bound(money.begin(),money.end(),prize+money[lose]);

        //เช็คว่าสามารถซื้อก่อนโดนหรอก หรือซื้อได้หลังโดนหลอก
        if(it-money.begin() <= lose) cout << it-money.begin();
        else cout << it2-money.begin();
        cout << " ";
    }


}
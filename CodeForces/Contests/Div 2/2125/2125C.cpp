#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt( ll end, ll num);

ll cnt( ll end, ll num){
    return end/num;
}

ll sp(ll r){
    ll R = cnt(r,2) + cnt(r,3) + cnt(r,5) + cnt(r,7) - cnt(r,6) - cnt(r,10)
    - cnt(r,14) - cnt(r,15) - cnt(r,21) - cnt(r,35) + cnt(r,30) + cnt(r,70) + cnt(r, 42) + cnt(r , 105) - cnt(r,210);
    return R;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        ll l,r;
        cin>>l>>r;
        cout<<(r-l + 1)- (sp(r) - sp(l-1))<<"\n";
    }
}
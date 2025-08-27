#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    deque<pair<int,ll>> dq;
    for(int i=0; i<k; i++){
        while(!dq.empty() && dq.back().second > x){
            dq.pop_back();
        }
        dq.push_back({i,x});
        x =(a*x + b)%c;
    }
    ll ans = 0;
    for(int i=k; i<=n; i++){
        ans^=(dq.front().second);
        while(!dq.empty() && dq.back().second > x){
            dq.pop_back();
        }
        dq.push_back({i,x});
        while(dq.front().first <= i-k && !dq.empty()){
            dq.pop_front();
        }
        x =(a*x + b)%c;
    }
    cout<<ans;
}
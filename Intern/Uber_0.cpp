#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,X;
    cin>>n>>X;
    // I take station[0] to give me 1 unit of energy
    vector<ll> costs(32,1'000'000'000);
    for(int i=0; i<n; i++){
        cin>>costs[i];
    }
    for(int i = 1; i<32; i++){
        costs[i] = min(costs[i],2*costs[i-1]);
    } // updated costs
    vector<ll> cost_presum(32);
    int x = X;
    if(x&1){
        cost_presum[0] = costs[0];
    }
    else{
        cost_presum[0] = 0LL;
    }
    x>>=1;
    for(int i = 1; i<32; i++){
        if(x&1){
            cost_presum[i] = cost_presum[i-1] + costs[i];
        }
        else{
            cost_presum[i] = cost_presum[i-1];
        }
        x>>=1;
    }
    // for(auto c : cost_presum) cout<<c<<" ";
    // cout<<"\n";
    ll ans = cost_presum[31];
    // cout<<ans<<"\n";
    x = X;
    for(int i=0; i<32; i++){
        if(x&1){
            // do ntg
        }
        else{
            ans = min(ans, costs[i] + cost_presum[31] - cost_presum[i]);
        }
        x>>=1;
    }
    cout<<ans<<"\n";
}
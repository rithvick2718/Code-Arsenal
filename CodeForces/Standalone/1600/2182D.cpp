#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 998244353LL;
vector<ll> fact(52);
vector<ll> invfact(52);
ll inv(ll val){
    ll ans = 1LL;
    ll x = val;
    ll n = MOD - 2;
    while(n > 0){
        if(n&1) ans =  (ans * x)%MOD;
        x = (x * x)%MOD;
        n>>=1;
    }
    return ans;
}
void fill(){
    fact[0] = 1LL; 
    invfact[0] = 1LL; 
    for(int i = 1; i < 52; i++){
        fact[i] = (i * fact[i-1])%MOD;
        invfact[i] = (inv(i) * invfact[i-1])%MOD;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill();
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(auto &b : a) cin>>b;
        sort(a.begin()+1, a.end());
        int ub  = 0;
        for(int i = 1; i<n; i++){
            ub += i*(a[i+1] - a[i]);
        }
        int freq = 1;
        for(int i = n-1; i > 0; i--){
            if( a[n] != a[i] ) break;
            freq++;
        }
        int lb = ub - (n - freq);
        long long ans = 0LL;
        if(a[0] >= lb){
            int k = a[0] - lb;
            k = min(n-freq, k);
            ans = (fact[n-freq] * fact[k + freq])%MOD;
            ans = (ans * invfact[k])%MOD;
        }
        cout<<ans<<"\n";
    }
}
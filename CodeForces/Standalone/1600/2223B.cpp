#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353LL
vector<ll> fact(2005);
vector<ll> invf(2005);
ll inv(ll a){
    ll n = MOD - 2LL;
    ll ans = 1LL;
    a = (a)%MOD;
    while(n > 0){
        if(n&1) ans=(ans*a)%MOD;
        a = (a*a)%MOD;
        n>>=1;
    }
    return ans;
}
void fill(){
    fact[0] = 1LL;
    invf[0] = inv(1LL);
    for(ll i = 1LL; i < 2005; i++){
        fact[i] = (fact[i-1] * i)%MOD;
        invf[i] = (invf[i-1] * inv(i))%MOD;
    }
    return;
}
struct Fraction {
    ll num, den;
    bool operator<(const Fraction& other) const {
        return (__int128_t)num * other.den < (__int128_t)other.num * den;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill();
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &x : a) cin>>x;
        for(auto &x : b) cin>>x;        
        vector<Fraction> c;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                c.push_back({b[i], b[j]});
                c.push_back({b[j], b[i]});
            }
        }        
        sort(c.begin(), c.end());
        ll cnt = 0LL;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                Fraction ratio = {a[j], a[i]};                
                auto it = upper_bound(c.begin(), c.end(), ratio);
                ll dis = distance(it, c.end());
                cnt = ( cnt + (dis * fact[n-2]) )%MOD;
            }
        }
        cnt = ( cnt * invf[n] )%MOD;
        cout<<cnt<<"\n";
    }
    return 0;   
}
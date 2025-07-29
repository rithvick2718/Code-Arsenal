#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1'000'000'007
int pwr(int a, int n, int mod){
    ll ToMultiply = a;
    ll ans = 1;
    while(n>0){
        if(n&1){
            ans = (ans * ToMultiply)%mod;
        }
        n>>=1;
        ToMultiply = (ToMultiply * ToMultiply)%mod;
    }
    return (int) ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int bc = pwr(b,c,MOD-1);
        int abc = pwr(a,bc,MOD);
        cout<<abc<<"\n";
    }
}
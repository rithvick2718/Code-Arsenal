#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b){
    if(a>=b){
        ll r = a%b;
        while(r!=0){
            a = b;
            b = r;
            r = a%b;
        }
        return b;
    }
    return gcd(b,a);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll g = gcd(a,b);
        a/=g;
        b/=g;
        // cout<<"a : "<<a<<" b : "<<b<<"\n";
        if(a <= k && b <= k){
            cout<<1<<"\n";
        }
        else cout<<2<<"\n";
    }
}
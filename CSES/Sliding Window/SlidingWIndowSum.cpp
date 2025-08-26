#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,x,a,b,c;
    cin>>n>>k>>x>>a>>b>>c;
    ll xf,xb;
    xf =x;
    xb =x;
    ll ans, sum = 0;
    for(int i=0; i<k; i++){
        sum+=xb;
        xb = (a*xb + b)%c;
    }
    ans = sum;
    n-=k;
    while(n>0){
        sum-=xf;
        sum+=xb;
        ans^=sum;
        xb = (a*xb + b)%c;
        xf = (a*xf + b)%c;        
        n--;
    }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll pwr(int x){
    ll k = 1LL;
    while(k<x){
        k*=2;
    }
    return k;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    int x,y,mx;
    while(tt--){
        cin>>x>>y;
        if(x == y){
            cout<<-1<<"\n";
        }
        else{
            mx = max(x,y);
            cout<<pwr(mx)-mx<<"\n";
        }
    }
}
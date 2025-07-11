#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<bool> T;
        while(n>=k){
            T.push_back(n&1);
            n>>=1; 
        }
        // now n<k
        reverse(T.begin(),T.end());
        ll ans = 0LL;
        ll num =0LL;
        for(auto t : T){
            ans = 2*ans + (t+n)*(t+num);
            num = 2*num + t;
            n = 2*n + t;
        }
        cout<<ans<<"\n";
    }
}
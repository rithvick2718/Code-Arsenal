#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        ll n,k;
        cin>>n>>k;
        ll d = n;
        vector<ll> q;
        q.push_back(d);
        while(d>=k){
            d>>=1;
            q.push_back(d);
        }
        int size = q.size();
        reverse(q.begin(),q.end());
        vector<ll> dp(size,0);
        vector<ll> num_of_val(size,0);
        for(int i=0; i+1<size; i++){
            if(q[i+1]&1){
                dp[i+1] = 2*dp[i]+(1+q[i])*(1+num_of_val[i]);
                num_of_val[i+1]=2*num_of_val[i]+1;
            }
            else{
                dp[i+1]=2*dp[i]+q[i]*num_of_val[i];
                num_of_val[i+1]=2*num_of_val[i];
            }
        }
        cout<<dp[size-1]<<"\n";
    }
}
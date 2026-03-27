#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[8001];
int b[8001];
ll c[8001];
ll dp[8001]; // present
ll prevdp[8001]; // past
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            b[i] = a[i];
        }
        ll sum = 0LL;
        for(int i = 0; i < n; i++){
            cin>>c[i];
            sum+=c[i];
        }
        sort(b, b+n);
        prevdp[0] = (a[0] == b[0]) ? c[0] : 0;
        for(int j = 1; j < n; j++){
            prevdp[j] = (a[0] == b[j]) ? c[0] : 0;
            prevdp[j] = max(prevdp[j-1], prevdp[j]);
        }
        dp[n-1] = prevdp[n-1];
        for(int i = 1; i < n; i++){
            dp[0] = (a[i] == b[0]) ? c[i] : 0;
            dp[0] = max(dp[0], prevdp[0]);
            for(int j = 1; j < n; j++){
                if(a[i] == b[j]){
                    dp[j] = c[i] + prevdp[j-1];
                }
                else{
                    dp[j] = max(dp[j-1], prevdp[j]);
                }
            }
            for(int k = 0; k < n; k++){
                prevdp[k] = dp[k];
            }
        }
        sum-=dp[n-1];
        cout<<sum<<"\n";
    }
}
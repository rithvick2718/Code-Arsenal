#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll I(int n, int m){
    if(n-1 == m+1) return 1LL;
    return 0LL;
}
int D(int n){
    int d = 0;
    while(n>1){
        n>>=1;
        d++;
    }
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 67,M =33;
    vector<vector<ll>> dp(N, vector<ll>(M,0));
    // n = 0 -> 0 num
    // n = 1 -> 1 num for all m
    // n = 2 -> 1 num from m = 1
    for(int m = 0; m<M; m++){
        dp[1][m] = 1;
        dp[2][m] = 1;
    }
    dp[2][0] = 0;
    for(int m = 1; m<M; m++){
        for(int n = 3; n<N; n++){
            dp[n][m] = dp[n-1][m-1] + dp[n-2][m-1] -I(n,m);
        }
    }
    // presum dp.
    for(int m = 0; m<M; m++){
        for(int n = 1; n<N; n++){
            dp[n][m]+=dp[n-1][m];
        }
    }
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        ll ans = 0;
        cin>>n>>k;
        int d = D(n);
        if( k <= 2*d -1 )
        {
            ans = n - dp[k][d];
        }
        cout<<ans<<"\n";
    }
}
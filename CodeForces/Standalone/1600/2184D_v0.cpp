#include<bits/stdc++.h>
using namespace std;
#define ll long long
//dp[0][n][m] -> number of even numbers that have exactly n moves to 0 and are less than equal to 2^m (not equal to 0)
//dp[1][n][m] -> number of  odd numbers that have exactly n moves to 0 and are less than equal to 2^m (not equal to 0)
ll I(int n, int m){
    if(n - 1 == m + 1) return 1LL;
    return 0LL;
}
ll D(ll n){
    ll d = 0;
    while(n>1){
        n>>=1;
        d++;
    }
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector< vector< vector<ll> > > dp( 2 , vector< vector<ll> > ( 100, vector<ll>(40 , 0) ) );
    for(int m = 0; m < 40; m++){
        dp[1][1][m]=1;
        dp[0][2][m] =1;
    }
    dp[0][2][0] = 0;
    // for n = 1 only 1 is the number
    // for n = 2 only 2 is the number
    for(int n =3; n < 100; n++){
        for(int m = 1; m < 40; m++){
            dp[0][n][m] = dp[0][n-1][m-1] + dp[1][n-1][m-1]; // FINE.
            dp[1][n][m] =  dp[0][n-1][m] - I(n,m); // FINE.
        }
    }
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        ll d = D(n);
        ll ans = 0;
        if( k <= 2*d-1){
            for(int i=0; i<=k; i++){
                ans+= dp[0][i][d] + dp[1][i][d];
            }
            ans = n - ans;
        }
        cout<<ans<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1'000'000'000'001LL
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dp(n,vector<ll>(n,INF));
    int u,v;
    ll w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        dp[u-1][v-1] = min(w,dp[u-1][v-1]);
        dp[v-1][u-1] = min(w,dp[v-1][u-1]);
    }// taking edges
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }// setting self edges as 0
    for(int v=0; v<n; v++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = min(dp[i][v] + dp[v][j], dp[i][j]);
            }
        }
    }// this is Floyd-Warshall
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j] == INF) dp[i][j] = -1;
        }
    }// As the question demands INF to be reset as -1
    while(q--){
        cin>>u>>v;
        cout<<dp[u-1][v-1]<<"\n";
    }
}
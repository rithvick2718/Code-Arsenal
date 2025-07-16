#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<int> start(n); // start[i] means what's the best solution if I start with a[i].
        vector<int> dp(n+1);
        dp[n] = n+1;
        for(int i = n-1; i>=0; i--){
            if(i + a[i] + 1 < n){
                start[i] = dp[i+a[i]+1] - i - a[i] -1;
            }
            else if(i + a[i] + 1 == n){
                start[i] = 0;
            }
            else{
                start[i] = n - i;
            }
            dp[i] = min (start[i] + i, dp[i+1]);
        }
        cout<<dp[0]<<"\n";
    }
}
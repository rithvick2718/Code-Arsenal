#include<bits/stdc++.h>
using namespace std;
int vals[2'00'001];
int presum[2'00'001];
int sufsum[2'00'001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k,w;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>w;
            if(w <= k) vals[i] = +1;
            else vals[i] = -1;
        }
        int small_l = INT_MAX, large_r = -1;
        presum[0] = vals[0];
        sufsum[n-1] = vals[n-1];
        if(presum[0] >= 0) small_l = min(small_l,0);
        if(sufsum[n-1] >= 0) large_r = max(large_r,n-1);
        for(int i = 1; i < n; i++){
            presum[i] = vals[i] + presum[i-1];
            if(presum[i] >= 0) small_l = min(small_l, i);
        }
        for(int i = n-2; i >= 0; i --){
            sufsum[i] = vals[i] + sufsum[i+1];
            if(sufsum[i] >= 0) large_r = max(large_r,i);
        }
        // presum and sufsum has been made
        bool ans = (small_l < large_r - 1);
        int mx = presum[n-2];
        for(int l = n-3; (l >= 0) && !ans; l--){
            if(mx - presum[l] >= 0 && presum[l] >=0){
                ans = true;
            }
            mx = max(presum[l], mx);
        }
        mx = sufsum[1];
        for(int r = 2; (r < n) && !ans; r++){
            if(mx - sufsum[r] >= 0 && sufsum[r] >=0){
                ans = true;
            }
            mx = max(mx, sufsum[r]);
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
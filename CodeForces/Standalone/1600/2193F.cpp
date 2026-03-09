#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<tuple<ll,ll,ll>> convert(const vector<pair<ll,ll>> &x){ // this coversts the sorted list into a usable tuple
    vector<tuple<ll,ll,ll>> ans;
    ll a,b,c;
    pair<ll,ll> s;
    // so the idea is that x is in dictionary order and for a given x I only need to know the lowest and highest values of y.
    vector<pair<ll,ll>>::const_iterator it = x.begin();
    while(it!=x.end()){
        a = it->first;
        b = it->second;
        s ={a,LLONG_MAX};
        it = upper_bound(it , x.end(), s); // at max is x.end()
        --it;
        c = it->second; // at max is x.end() - 1
        ans.emplace_back(a,b,c);
        it++; // at max is x.end(), so while loop works
    }
    return ans;
}
ll dis_l (ll cur, ll low, ll high){ // you start at curr, cover all the houses from low to high and return to low
    if(low<=cur && cur<= high)
        return (high - low) + (high - cur);
    if(cur<=low)
        return (low - cur) + 2*(high - low);
    return cur - low;
}
ll dis_h (ll cur, ll low, ll high){
    if(low<=cur && cur<= high)
        return (high - low) + (cur - low);
    if(cur>=high)
        return (cur - high) + 2*(high - low);
    return high - cur;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        ll ax,ay,bx,by;
        cin>>n>>ax>>ay>>bx>>by;
        vector<pair<ll,ll>> x(n);
        for(int i=0; i<n; i++) cin>>x[i].first;
        for(int i=0; i<n; i++) cin>>x[i].second;
        x.push_back({ax,ay});
        x.push_back({bx,by});
        sort(x.begin(),x.end());
        vector<tuple<ll,ll,ll>> t = convert(x);
        // for(auto p : t){
        //     cout<<"("<<get<0>(p)<<","<<get<1>(p)<<","<<get<2>(p)<<") ,";
        // }
        // cout<<"\n";
        int m = t.size();
        vector<vector<ll>> dp(2, vector<ll> (m,0));
        //dp[0][i] is the time taken to reach the lowest house
        // dp[1][i] is the time taken to reach the highest house
        dp[0][0]=0;
        dp[1][0]=0;
        for(int i=1; i < m; i++){
            dp[0][i] = min( dp[0][i-1] + dis_l(get<1>(t[i-1]),get<1>(t[i]), get<2>(t[i])) 
                        ,dp[1][i-1] + dis_l(get<2>(t[i-1]),get<1>(t[i]), get<2>(t[i]))) +
                        (get<0>(t[i]) - get<0>(t[i-1]));
            dp[1][i] = min(dp[0][i-1] + dis_h(get<1>(t[i-1]),get<1>(t[i]), get<2>(t[i])) 
                        ,dp[1][i-1] + dis_h(get<2>(t[i-1]),get<1>(t[i]), get<2>(t[i]))) +
                        (get<0>(t[i]) - get<0>(t[i-1]));
        }
        cout<<dp[0][m-1]<<"\n";
   }
}
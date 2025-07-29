#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<pair<int,int>> h(n);
        for(int i=0; i<n; i++){
            h[i] = { height[i] , i };
        }
        sort(h.begin(),h.end());
        vector<int> mn(n);
        vector<int> mx(n);
        mn[n-1] = h[n-1].second;
        mx[n-1] = h[n-1].second;
        for(int i=n-2; i>=0; i--){
            mx[i] = max(mx[i+1],h[i].second);
            mn[i] = min(mn[i+1],h[i].second);
        }
        for(auto t : h){
            cout<<t.first<<" ";
        }
        cout<<"\n";
        for(auto t : h){
            cout<<t.second<<" ";
        }
        cout<<"\n";
        for(auto m : mn) cout<<m<<" ";
        cout<<"\n";
        for(auto m : mx) cout<<m<<" ";
        cout<<"\n";
        int ans = 0;
        for(int i = 0; i<n-1; i++){
            ans = max({ ans, h[i].first * (mx[i+1] - h[i].second), h[i].first * ( h[i].second - mn[i+1]) }); 
        }
        return ans;
    }
};

int main(){
    Solution S;
    vector<int> b = {1,8,6,2,5,4,8,3,7};
    cout<<S.maxArea(b);
}
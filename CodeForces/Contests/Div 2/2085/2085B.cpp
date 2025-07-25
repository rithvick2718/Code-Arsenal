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
        int z = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i] == 0 ) z++;
        }
        vector<pair<int,int>> ans;
        if(z == 0){
            ans.push_back({1,n});
        }
        else{
            if(a[0]!=0){
                ans.push_back({2,n});
                ans.push_back({1,2});
            }
            else{
                ans.push_back({1,2});
                if(a[0] == 0) z--;
                if(a[1] == 0) z--;
                if(z>0){
                    ans.push_back({2,n-1});
                    ans.push_back({1,2});                    
                }
                else{
                    ans.push_back({1,n-1});
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(auto p : ans){
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        string S;
        cin>>S;
        vector<int> cnt(26,0);
        for(auto s : S){
            cnt[s-'A']++;
        }
        string ans;
        for(int i=25; i>=0; i--){
            while(cnt[i]>0){
                ans+=('A'+i);
                cnt[i]--;
            }
        }
        cout<<ans<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<int> h(n);
        for(int i=0; i<n; i++){
            cin>>h[i];
        }
        int jump_range;
        jump_range = h[k-1];
        sort(h.begin(),h.end());
        vector<int>::iterator it = lower_bound(h.begin(),h.end(),jump_range);
        int pos = it - h.begin();
        while(pos + 1 < n){
            if(h[pos+1] - h[pos] > jump_range ){
                break;
            }
            pos++;
        }
        if(pos+1>=n) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
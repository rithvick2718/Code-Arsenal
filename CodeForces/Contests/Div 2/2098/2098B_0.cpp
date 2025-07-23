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
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans;
        int e = n - k;
        if(e&1) e++;
        ans = a[n-e/2] - a[e/2-1] + 1;
        cout<<ans<<"\n";
    }
} //good one.
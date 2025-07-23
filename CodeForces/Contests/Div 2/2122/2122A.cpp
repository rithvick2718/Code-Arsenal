#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        bool ans;
        if(n<=2 && m<=2) ans = false;
        else if(n == 1 || m == 1) ans = false;
        else ans = true;
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
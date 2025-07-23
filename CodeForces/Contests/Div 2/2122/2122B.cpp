#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        ll a,b,c,d;
        ll mn_op = 0LL;
        for(int i=0; i<n; i++){
            cin>>a>>b>>c>>d;
            mn_op += max(0LL,a-c);
            if(b-d>0){
                mn_op += min(a,c) + b-d;
            }
        }
        cout<<mn_op<<"\n";
    }
}
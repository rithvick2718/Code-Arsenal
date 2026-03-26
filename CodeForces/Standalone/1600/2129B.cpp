#include<bits/stdc++.h>
using namespace std;
vector<int> p(5001);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,x;
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>x;
            p[x] = i;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int a = p[i] - 1;
            int b = n - p[i];
            for(int j = 1; j < i; j++){
                if(p[j] > p[i]) b--;
                else a--;
            }
            ans+=min(a,b);
        }
        cout<<ans<<"\n";
    }
}
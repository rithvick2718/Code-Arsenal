#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,a,k;
        cin>>n>>k;
        vector<int> conts;
        int val = 0;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a==1){
                if(val!=0) conts.push_back(val);
                val = 0;
            }
            else{
                val++;
            }
        }
        if(val!=0) conts.push_back(val);
        int ans = 0;
        if(!conts.empty()){
            for(auto cont : conts){
                val = cont/(k+1);
                if(val*(k+1) + k == cont) val++;
                ans += val;
            }
        }
        cout<<ans<<"\n";
    }
}
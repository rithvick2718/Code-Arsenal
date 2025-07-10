#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        //code
        int n,k;
        cin>>n>>k;
        vector<int> per(n,-1);
        int i = k-1;
        int put = 1;
        while(i<n){
            per[i]=put;
            put++;
            i+=k;
        }
        for(int i=0; i<n; i++){
            if(per[i] == -1){
                per[i]=put;
                put++;
            }
        }
        for(auto p : per) cout<<p<<" ";
        cout<<"\n";
    }
}
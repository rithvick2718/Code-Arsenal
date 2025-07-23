#include<bits/stdc++.h>
using namespace std;
int a[1'00'005];
int n,k,e;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        e = n - k;
        if(e&1) e++;
        cout<<a[n-e/2] - a[e/2-1] + 1<<"\n";
    }
} //good one.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd (int a, int b){ //a>0, b>0
    if(a<b) swap(a,b);
    int r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r =a%b;
    }
    return b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n),gl(n,1),gh(n,1);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    gl[0] = arr[0];
    gh[n-1] = arr[n-1];
    for(int i = 1; i<n; i++){
        gl[i] = gcd(gl[i-1],arr[i]);
        gh[n-i-1] = gcd(gh[n-i],arr[n-i-1]);
    }
    ll ans = (ll) gl[n-1];
    for(int i=1; i<n-1; i++){
        ans+=(ll)min(gl[i],gh[i]);
    }
    cout<<ans<<"\n";
}
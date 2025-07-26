#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int mn = 0;
    int sum = 0;
    int ans = a[0];
    for(int i =0; i<n; i++){
        sum+=a[i];
        ans = max(ans,sum-mn);
        mn = min(sum,mn);
    }
    cout<<ans<<"\n";
}
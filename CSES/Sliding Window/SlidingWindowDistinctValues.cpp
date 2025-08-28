#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int num_dist = 0;
    for(int i=0; i<k; i++){
        if(mp[arr[i]] == 0){
            num_dist++;
        }
        mp[arr[i]]++;
    }
    cout<<num_dist<<" ";
    for(int i=k; i<n; i++){
        mp[arr[i-k]] --;
        if(mp[arr[i-k]] == 0) num_dist--;
        if(mp[arr[i]] == 0) num_dist++;
        mp[arr[i]]++;
        cout<<num_dist<<" ";
    }
}
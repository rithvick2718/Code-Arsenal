#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    unordered_map<int,int> freq;
    set<pair<int,int>> S; // {-freq, val}
    for(int i=0; i<k; i++){
        freq[arr[i]]++;
    }
    for(auto x : freq){
        S.insert( { -x.second, x.first });
    }
    cout<<S.begin()->second<<" ";
    for(int i=k; i<n; i++){
        S.erase({-freq[arr[i]],arr[i]});
        S.erase({-freq[arr[i-k]],arr[i-k]});
        freq[arr[i]]++;
        freq[arr[i-k]]--;
        S.insert({-freq[arr[i]],arr[i]});
        S.insert({-freq[arr[i-k]],arr[i-k]});
        cout<<S.begin()->second<<" ";
    }
}
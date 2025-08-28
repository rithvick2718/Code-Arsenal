#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> freq(k+1,0);
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    } //O(n)
    for(int i=0; i<k; i++){
        if(arr[i] <= k){
            freq[arr[i]]++;
        }
    }//O(k)
    set<int> store;
    for(int i=0; i<=k; i++){
        if(freq[i] == 0) store.insert(i);
    }//O(k log k)
    cout<<*store.begin()<<" ";
    for(int i=k; i<n; i++){
        if(arr[i] <=k ){
            if(freq[arr[i]] == 0){
                store.erase(arr[i]);
            }
            freq[arr[i]] ++;
        }
        if(arr[i-k] <=k){
            freq[arr[i-k]]--;
            if(freq[arr[i-k]] == 0){
                store.insert(arr[i-k]);
            }
        }
        cout<<*store.begin()<<" ";
    }
}
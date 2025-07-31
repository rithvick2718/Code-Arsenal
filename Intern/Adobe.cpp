#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve(vector<int> arr){
    int n = arr.size();
    vector<int> ones(n);
    vector<int> precompute_number_of_ones(n);
    ll evens,odds,total;
    ll MUL = 1LL;
    ll ans =0;
    for(int b = 0; b<32; b++){
        for(int i=0; i<n; i++){
            ones[i] = arr[i]&1; // so ones[i] is either 1 or 0
            arr[i]>>=1; // divide arr[i] by 2
        }
        precompute_number_of_ones[0] = ones[0];
        odds = 0;
        evens = 0;
        if(precompute_number_of_ones[0]&1) odds++;
        else evens++;
        for(int i=1; i<n; i++){
            precompute_number_of_ones[i] = ones[i] + precompute_number_of_ones[i-1];
            if(precompute_number_of_ones[i]&1) odds++;
            else evens++;
        }
        total = odds;
        for(int i = 0; i<n; i++){
            if(precompute_number_of_ones[i]&1) odds --;
            else evens--;
            if(precompute_number_of_ones[i]&1) total+=evens;
            else total+=odds;
        }
        ans += total*MUL;
        MUL<<=1;
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,60946,643,8441,2141,22,334,4,8212,14124,123132,21,32,3241,4,41,234124,43214,4,12,2342431,412,4,124};
    cout<<solve(arr)<<"\n";
    int n = arr.size();
    int curr;
    int ans = 0;
    for(int l=0; l<n; l++){
        curr = 0;
        for(int r = l; r<n; r++){
            curr^=arr[r];
            ans+=curr;
        }
    }
    cout<<ans;
}
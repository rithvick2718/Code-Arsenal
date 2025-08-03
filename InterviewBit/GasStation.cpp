#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int SolutioncanCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    vector<ll> P(2*n);
    P[0] = A[0] - B[0];
    for(int i = 1; i< 2*n; i++){
        P[i] = P[i-1] + A[i%n] - B[i%n];
    }
    // for(auto p : P){
    //     cout<<p<<" ";
    // }
    ll val = 0;
    map<ll,int> mp;
    for(int i=0; i<n; i++) mp[P[i]]++;
    int found = -1;
    for(int start = 0; start<n; start++){
        // cout<<val<<" "<<mp.begin()->first<<" : ";
        // for(int i = start; i<start +n; i++){
        //     cout<<P[i]<<" ";
        // }
        // cout<<"\n";
        if(val <= mp.begin()->first){
            found = start;
            break;
        }
        else{
            mp[P[start+n]]++;
            mp[P[start]]--;
            if(mp[P[start]] == 0){
                mp.erase(P[start]);
            }
            val = P[start];
        }
    }
    return found;
}
int main(){
    vector<int> A = {959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337, 395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209};
    vector<int> B = {862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571, 657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884};
    cout<<SolutioncanCompleteCircuit(A,B);
}
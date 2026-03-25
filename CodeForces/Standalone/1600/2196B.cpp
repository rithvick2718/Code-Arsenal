#include<bits/stdc++.h>
using namespace std;
int ohio(int x){
    int low = 1;
    int high = 500;
    int mid = low + (high - low)/2;
    while(low < high){
        mid = low + (high - low)/2;
        if(mid * mid < x){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return high;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,B,count = 0;
        cin>>n;
        B = ohio(n);
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        for(int i = 0; i < n; i++){
            int j;
            if(a[i] >= B){
                j = i%a[i]; // this is the smallest j ans it's positive
                for(int k = (j-i)/a[i]; i + k*a[i] < n; k++){
                    j = i + k*a[i];
                    if(a[j] == abs(k)) count++; // no need to worry about j = i, in that case we need a[i] = 0 but it's given a[i] > 0
                }
            }
            else{
                for(int k = 1; ( k < B )  && ( i + k*a[i] < n ); k++){
                    j = i + k*a[i];
                    if(a[j] == k ) count++;
                }
            }
        }
        cout<<count<<"\n";
    }
}
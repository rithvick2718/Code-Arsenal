#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        bool arr[n][m];
        int num[n];
        for(int i = 0; i < n; i++){
            num[i] = 0;
            if(i > 0) num[i]+=num[i-1];
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
                num[i] +=arr[i][j];
            }
        }
        // now num[n-1] is the total number of 1's in the grid
        long long a = (num[n-1])/2;
        long long b = (num[n-1] + 1)/2;
        int d = lower_bound(num, num + n, a) - num;
        int c = num[d];
        int r = 0; // num of rights to print
        while(c!=a && r < m){
            c-=arr[d][r];
            r++;
        }
        cout<<a*b<<"\n";
        for(int i = 0; i < d; i++) cout<<"D";
        for(int i = 0; i < r; i++) cout<<"R";
        cout<<"D";
        for(int i = 0; i < m - r; i++) cout<<"R";
        for(int i = 0; i < n - d - 1; i++) cout<<"D";
        cout<<"\n";
    }
}
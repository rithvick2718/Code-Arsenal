#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int t[32][n]; // t[i][x] means the value you jump to after 2^i jumps
    for(int i=0; i<n; i++){
        cin>>t[0][i];
        t[0][i]--;
    }
    for(int r = 1; r<32; r++){
        for(int i=0; i<n; i++){
            t[r][i] = t[r-1][ t[r-1][i] ]; // 2^r jumps is same as 2^(r-1) jumps from i to say j, and 2^(r-1) jumps from j to ans
        }
    }
    int x,k,i;
    while(q--){
        cin>>x>>k;
        x--;
        i=0;
        while(k>0){
            if(k&1){
                x = t[i][x];
            }
            i++;
            k>>=1;
        }
        cout<<x + 1<<"\n";
    }
}
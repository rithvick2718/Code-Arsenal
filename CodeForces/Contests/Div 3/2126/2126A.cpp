#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int x;
        cin>>x;
        int d = x%10;
        while(x>0){
            d =  min(d,x%10);
            x/=10;
        }
        cout<<d<<"\n";
    }
}
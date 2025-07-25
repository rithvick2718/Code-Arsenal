#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(const string  &r){
    int n = r.length();
    int low = 0;
    int high = n-1;
    while(low<high){
        if(r[low] != r[high]) return false;
        low++;
        high--;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        string r;
        cin>>r;
        if(k>0){
            bool ans = false;
            for(int i=1; i<n; i++){
                if(r[0]!=r[i]){
                    ans = true;
                    break;
                }
            }
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int low = 0;
            int high = n-1;
            bool ans = false;
            while(low<high){
                if(r[high] - r[low] > 0){
                    ans = true;
                    break;
                }
                else if(r[high] - r[low] < 0){
                    ans = false;
                    break;
                }
                low++;
                high--;
            }
            if(ans) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
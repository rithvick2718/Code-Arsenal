#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        int n = s.length();
        int k = 0; // k records the first position of the first 0 in s
        while(k<n){
            if(s[k] == '0') break;
            else k++;
        }
        if(k == n){
            cout<<1<<" "<<n<<" "<<1<<" "<<1<<"\n"; 
        }
        else{ // note that k is also the lenght of the array before the first 0.
            int mx = -1;
            int res;
            int l2=1,r2=n-k;
            for(int i=0; i<=k; i++){
                res = 0;
                int j = 0;
                for(; j<n-k; j++){
                    if(s[i+j] != s[k+j]){
                        res++;
                    }
                    else{
                        if(res>mx){
                            mx = res;
                            l2 = 1 + i;
                            r2 = i + n -k;
                        }
                        break;
                    }
                }
                if(res>mx){
                    mx = res;
                    l2 = 1+i;
                    r2 = i + n - k;
                }
            }
            cout<<1<<" "<<n<<" "<<l2<<" "<<r2<<"\n";
        }
    }
}
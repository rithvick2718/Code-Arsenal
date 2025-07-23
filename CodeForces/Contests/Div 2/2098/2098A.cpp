#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        string S;
        cin>>S;
        vector<int> available(10,0);
        for(auto s : S){
            available[s-'0']++;
        }
        vector<int> digits(10);
        for(int i=0; i<10; i++){
            int j = 9 - i;
            while(j<10){
                if(available[j]>0){
                    available[j]--;
                    digits[i] = j;
                    break;
                }
                else j++;
            }
        }
        for(auto digit : digits) cout<<digit;
        cout<<"\n";
    }
}
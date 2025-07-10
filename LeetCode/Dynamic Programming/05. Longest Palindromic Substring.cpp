#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for(int l=n-1;l>=0; l--){
            dp[l][l] = true;
            if(l+1 < n && s[l]==s[l+1]) dp[l][l+1]=true;
            for(int r = l+2; r<n; r++){
                if(s[l] == s[r]){
                    dp[l][r] = dp[l+1][r-1];
                }
                // else dp[l][r] is already false
            }
        }
        string ans=s.substr(0,1);
        for(int len = n; len>0; len--){
            for(int l =0; len + l -1 <n; l++){
                if(dp[l][len+l-1]){
                    return s.substr(l,len);
                }
            }
        }
        return ans;
    }
};
int main()
{
    string s;
    cin>> s;
    Solution SOL;
    cout<<SOL.longestPalindrome(s);
}
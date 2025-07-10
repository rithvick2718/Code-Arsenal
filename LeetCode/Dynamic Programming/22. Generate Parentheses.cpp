#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0].push_back("");
        for(int i = 1; i <= n; i++){
            for(int j = i-1; j>=0; j--){
                for(auto s : dp[j]){
                    for( auto r : dp[i-1-j]){
                        dp[i].push_back("("+s+")"+r);
                    }
                }
            }
        }
        for(auto S : dp){
            for(auto s : S) cout<<s<<" ";
            cout<<"\n";
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    sol.generateParenthesis(4);
}
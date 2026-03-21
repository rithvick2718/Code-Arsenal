#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> lvl(n,-1);
        lvl[id] = 0;
        queue<int> q;
        q.push(id);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : friends[u]){
                if(lvl[v] == -1){
                    lvl[v] = 1+lvl[u];
                    q.push(v);
                }
            }
        }
        unordered_map<string,int> si;
        for(int i=0; i<n; i++){
            if(lvl[i] == level){
                for(auto videos : watchedVideos[i]){
                    si[videos]++;
                }
            }
        }
        vector<pair<int,string>> p;
        for(auto [vids, freqs] : si){
            p.push_back({freqs,vids});
        }
        sort(p.begin(),p.end());
        vector<string> ans;
        for(auto [freq, vids] :  p){
            ans.push_back(vids);
        }
        return ans;
    }
};
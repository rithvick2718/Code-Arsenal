#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size(),false);
        visit[0] = true;
        int num = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            num++;
            int u = q.front();
            q.pop();
            for(auto v : rooms[u]){
                if(!visit[v]){
                    visit[v] = true;
                    q.push(v);
                }
            }
        }
        if(num == rooms.size()) return true;
        return false;
    }
};
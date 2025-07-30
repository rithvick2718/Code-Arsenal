#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    vector<int> distance(n,-1);
    distance[0] = 1;
    int temp;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(auto x : graph[temp]){
            if(distance[x] == -1){
                distance[x] = 1 + distance[temp];
                q.push(x);
            }
        }
    }
    if(distance[n-1] == -1) cout<<"IMPOSSIBLE";
    else{
        cout<<distance[n-1]<<"\n";
        stack<int> s;
        s.push(n-1);
        while(s.top()!=0){
            for(auto x : graph[s.top()]){
                if(distance[x] + 1 == distance[s.top()]){
                    s.push(x);
                    break;
                }
            }
        }
        while(!s.empty()){
            cout<<s.top()+1<<" ";
            s.pop();
        }
    }
}